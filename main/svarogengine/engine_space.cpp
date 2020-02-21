#include "engine_space.h"

EngineSpace* EngineSpace::getEngineSpace() {
    if(!engine) {
        engine = new EngineSpace;
    }
    return engine;
}

EngineSpace* EngineSpace::engine = 0;