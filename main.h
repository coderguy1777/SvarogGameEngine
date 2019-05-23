#include "EngineHeader.h"

namespace enginecore {
    class Window {
        private:
            int width, height;
            double posx, posy;

        public:
            Window(int w, int h) {
                this->width = w;
                this->height = h;
            }
    };
}