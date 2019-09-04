#include "glad_loader.h"
void GladLoader::load_glad() {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::invalid_argument("GLAD FAILURE");
        glad_loaded = 0;
        glfwTerminate();
    } else {
        spdlog::info("GLAD has been loading.....");
        glad_loaded = 1;
    }
}

int GladLoader::get_load_state() const {
    return glad_loaded;
}