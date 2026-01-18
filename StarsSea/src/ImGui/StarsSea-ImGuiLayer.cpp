#include <glad/glad.h>

#include "../StarsSea-pch.h"
#include "StarsSea-ImGuiLayer.h"

#include "imgui.h"

#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#include "../StarsSea/ApplicationStarsSea.h"


#include <GLFW/glfw3.h>


namespace StarsSea
{
	StarsSeaImGuiLayer::StarsSeaImGuiLayer()
		: Layer("StarsSeaImGuiLayer")
	{

	}

	StarsSeaImGuiLayer::~StarsSeaImGuiLayer()
	{

	}

	void StarsSeaImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& starseaio = ImGui::GetIO(); (void) starseaio;
		starseaio.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		//starseaio.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		starseaio.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		starseaio.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		//starseaio.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		//starseaio.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		ImGuiStyle& StarsSeaStyle = ImGui::GetStyle();
		if (starseaio.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			StarsSeaStyle.WindowRounding = 0.0f;
			StarsSeaStyle.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		ApplicationStarsSea& StarsSeaApp = ApplicationStarsSea::Get();
		GLFWwindow* starseawindow = static_cast<GLFWwindow*>(StarsSeaApp.GetWindow().GetNativeWindow());

		ImGui_ImplGlfw_InitForOpenGL(starseawindow, true);
		ImGui_ImplOpenGL3_Init("#version 410");
		
	}

	void StarsSeaImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void StarsSeaImGuiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void StarsSeaImGuiLayer::End() {
		ImGuiIO& starseaio = ImGui::GetIO();
		ApplicationStarsSea& StarsSeaApp = ApplicationStarsSea::Get();
		starseaio.DisplaySize = ImVec2(StarsSeaApp.GetWindow().GetWidth(), StarsSeaApp.GetWindow().GetHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		if (starseaio.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			GLFWwindow* starseacurrentcontext = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(starseacurrentcontext);
		}
	}

	void StarsSeaImGuiLayer::OnImGuiRender() {
		static bool starseashow = true;
		ImGui::ShowDemoWindow(&starseashow);
	}
}