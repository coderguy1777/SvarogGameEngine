#pragma once
#ifndef CUBE_H
#define CUBE_H
#include "math/vec3.h"
#include "svarog_shape.h"
#include "core/ds-classes/Array.h"
class SvarogCube {
    private:
        Array<Vector3, 36>cube_vertexs;
        Array<unsigned int, 12>cube_indicies;

        void add_cube_data() {
            cube_vertexs.add(Vector3(0.5f, 0.5f, -0.5f));
            cube_vertexs.add(Vector3(0.5f, -0.5f, 0.0f));
            cube_vertexs.add(Vector3(0.5f, 0.0f, 0.5f));
            cube_vertexs.add(Vector3(0.0f, -0.5f, 0.5f));
            cube_vertexs.add(Vector3(0.5f, 0.0f, 0.5f));
            cube_vertexs.add(Vector3(0.0f, 0.0f, 0.0f));
        }

    public:
        SvarogCube();
        void translate_cube(Vector3 translation_point);
        void rotate_cube(Vector3 rotation_axis);
        void draw_cube();
};
#endif