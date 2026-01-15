workspace "SeaStars"

	platforms{
		"x64",
		"x86"
	}

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "StarsSea/utils/GLFW/include"
IncludeDir["Glad"] = "StarsSea/utils/Glad/include"
IncludeDir["ImGui"] = "StarsSea/utils/imgui"

include "StarsSea/utils/GLFW/premake5.lua"
include "StarsSea/utils/Glad/premake5.lua"
include "StarsSea/utils/imgui/premake5.lua"

project "StarsSea"
	location "StarsSea"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/utils/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"
		buildoptions { "/utf-8", "/wd26495", "/wd26812" }

		defines{
			"STARSSEAPLATFORMWINDOWS",
			"STARSSEABUILDDLL",
			"GLFW_INCLUDE_NONE"
		}

	postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/StarsSea-Sandbox")
		}
	filter "configurations:Debug"
		defines "STARSSEADEBUG"
		buildoptions "/MDd"
		symbols "On"
	filter "configurations:Release"
		defines "STARSSEARELEASE"
		buildoptions "/MD"
		optimize "On"
	filter "configurations:Dist"
		defines "STARSSEADIST"
		buildoptions "/MD"
		optimize "On"

project "StarsSea-Sandbox"
	location "StarsSea-Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"StarsSea/utils/spdlog/include",
			"StarsSea/src"
		}

		links{
			"StarsSea"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "Off"
			systemversion "latest"
			buildoptions { "/utf-8", "/wd26495", "/wd26812" }
			defines{
				"STARSSEAPLATFORMWINDOWS"
			}

		filter "configurations:Debug"
			defines "STARSSEADEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "STARSSEARELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "STARSSEADIST"
			optimize "On"