#pragma once
#ifndef CUBE_H
#define CUBE_H
#include "math/vec3.h"
#include "svarog_polygon.h"
#include "svarog_shape.h"
#include "core/ds-classes/Array.h"
struct index_list {
    std::vector<unsigned int>polygon_index;
    index_list(unsigned int index_1, unsigned int index_2, unsigned int index_3) {
        polygon_index.push_back(index_1);
        polygon_index.push_back(index_2);
        polygon_index.push_back(index_3);
    }

    index_list() {
        polygon_index.push_back(0);
        polygon_index.push_back(0);
        polygon_index.push_back(0);
    }
};

class SvarogCube {
    private:
        Array<SvarogPolygon, 6>cube_vertexs;
        Array<index_list, 6>cube_indicies;
        Vector3 cube_position;
        SvarogShape cube_mesh;
        struct cube_size {
            float l, w, h;
            cube_size(float length, float width, float height) {
                l = length;
                w = width;
                h = height;
            }

            cube_size() {
                l = w = h = 0.0f;
            }

            float get_cube_length() const {
                return l;
            }

            float get_cube_width() const {
                return w;
            }

            float get_cube_height() const {
                return h;
            }

            void modify_cube_size(float l, float w, float h) {
                l = l;
                w = w;
                h = h;
            }

        } cube_size_data;
        
        void add_cube_data() {
            SvarogPolygon polygon_1;
            polygon_1.add_vertex(Vector3(0.5f, 0.5f, -0.5f));
            polygon_1.add_vertex(Vector3(0.5f, -0.5f, -0.5f));
            polygon_1.add_vertex(Vector3(-0.5f, -0.5f, -0.5f));
            SvarogPolygon polygon_2;
            polygon_2.add_vertex(Vector3(0.5f, -0.5f, -0.5f));
            polygon_2.add_vertex(Vector3(-0.5f, -0.5f, -0.5f));
            polygon_2.add_vertex(Vector3(-0.5f, 0.5f, -0.5f));
            SvarogPolygon polygon_3;
            polygon_3.add_vertex(Vector3(0.5f, -0.5f, -0.5f));
            polygon_3.add_vertex(Vector3(0.5f, -0.5f, -0.5f));
            polygon_3.add_vertex(Vector3(-0.5f, -0.5f, -0.5f));
            SvarogPolygon polygon_4;
            polygon_4.add_vertex(Vector3(0.5f, 0.5f, 0.5f));
            polygon_4.add_vertex(Vector3(-0.5f, -0.5f, 0.5f));
            polygon_4.add_vertex(Vector3(0.5f, 0.5f, 0.0f));
            SvarogPolygon polygon_5;
            polygon_5.add_vertex(Vector3(-0.5f, -0.5f, 0.5f));
            polygon_5.add_vertex(Vector3(0.5f, 0.5f, -0.5f));
            polygon_5.add_vertex(Vector3(-0.5f, -0.5f, 0.0f));
            SvarogPolygon polygon_6;
            polygon_6.add_vertex(Vector3(-0.5f, 0.0f, -0.5f));
            polygon_6.add_vertex(Vector3(-0.5f, 0.0f, 0.5f));
            polygon_6.add_vertex(Vector3(-0.5f, -0.5f, 0.5f));
            cube_vertexs.add(polygon_1);
            cube_vertexs.add(polygon_2);
            cube_vertexs.add(polygon_3);
            cube_vertexs.add(polygon_4);
            cube_vertexs.add(polygon_5);
            cube_vertexs.add(polygon_6);
            cube_indicies.add(index_list(0, 1, 3));
            cube_indicies.add(index_list(1, 2, 3));
            cube_indicies.add(index_list(0, 1, 2));
            cube_indicies.add(index_list(1, 4, 5));
            cube_indicies.add(index_list(2, 4, 5));
            cube_indicies.add(index_list(4, 5, 6));
        }

    public:
        SvarogCube();
        Vector3 get_cube_position() const;
        Vector3 get_cube_size() const;
        void translate_cube(Vector3 translation_point);
        void rotate_cube(Vector3 rotation_axis);
        void scale_cube(Vector3 scale_factor);
        void draw_cube();
};
#endif