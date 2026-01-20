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
IncludeDir["glm"] = "StarsSea/utils/glm"

include "StarsSea/utils/GLFW/premake5.lua"
include "StarsSea/utils/Glad/premake5.lua"
include "StarsSea/utils/imgui/premake5.lua"

project "StarsSea"
	location "StarsSea"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/utils/glm/glm/**.hpp",
		"%{prj.name}/utils/glm/glm/**.inl"
	}

	defines{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/utils/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
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
			runtime "Debug"
			symbols "On"
		filter "configurations:Release"
			defines "STARSSEARELEASE"
			runtime "Release"
			optimize "On"
		filter "configurations:Dist"
			defines "STARSSEADIST"
			runtime "Release"
			optimize "On"

project "StarsSea-Sandbox"
	location "StarsSea-Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"StarsSea/utils/spdlog/include",
			"StarsSea/src",
			"StarsSea/utils",
			"%{IncludeDir.glm}"
		}

		links{
			"StarsSea"
		}

		filter "system:windows"
		systemversion "latest"

		buildoptions { "/utf-8", "/wd26495", "/wd26812" }

		defines{
				"STARSSEAPLATFORMWINDOWS"
		}

		filter "configurations:Debug"
			defines "STARSSEADEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "STARSSEARELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "STARSSEADIST"
			runtime "Release"
			optimize "on"