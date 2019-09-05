#include "glad_loader.h"
void GladLoader::load_glad() {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        spdlog::info("Glad failed to load.");
        throw std::invalid_argument("GLAD FAILURE");
        glfwTerminate();
    } else {
        spdlog::info("********************************************************");
        spdlog::info("GLAD load state: ");
        spdlog::info("GLAD has been loaded!");
    }
}

int GladLoader::get_load_state() const {
    return glad_loaded;
}