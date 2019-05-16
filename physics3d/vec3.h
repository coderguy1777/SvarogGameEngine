#include "core/Vector.h"


class Vector3 {
    private:
        float initx, inity, initz;
    
    public:
        Vector3(float lx, float ly, float lz) {
            this->initx = lx;
            this->inity = ly;
            this->initz = lz;
        }

        float vec3Mag();
};