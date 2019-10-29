#include "imgui_init.h"
void ImGuiInit::make_imgui_context(GLFWwindow* window, const char* glsl_v) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_v);
}

void ImGuiInit::make_imgui_style(unsigned int style) {
    switch(style) {
        case GUI_STYLE::STYLE_DARK: ImGui::StyleColorsDark(); break;
        case GUI_STYLE::STYLE_LIGHT: ImGui::StyleColorsLight(); break;
        case GUI_STYLE::STYLE_NONE: ImGui::StyleColorsClassic(); break;
        default: ImGui::StyleColorsClassic(); break;
    }
}

void ImGuiInit::init_imgui_frames() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiInit::init_imgui_render() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiInit::init_imgui_shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiInit::imgui_ini_use(bool is_used) {
    if(is_used) {
        ImGui::GetIO().IniFilename = "imgui.ini";
    }

    if(!is_used) {
        ImGui::GetIO().IniFilename = NULL;
    }
}