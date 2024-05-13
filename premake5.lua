workspace "SolidStateGE"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SolidStateGE"
	location "SolidStateGE"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/Vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SLD_PLATFORM_WINDOWS",
			"SLD_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "SLD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SLD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SLD_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SolidStateGE/Vendor/spdlog/include",
		"SolidStateGE/src"
	}

	links 
	{
		"SolidStateGE"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"SLD_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "SLD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SLD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SLD_DIST"
		optimize "On"