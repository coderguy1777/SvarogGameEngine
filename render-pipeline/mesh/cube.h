#pragma once
#ifndef CUBE_H
#define CUBE_H
#include "math/vec3.h"
#include "svarog_polygon.h"
#include "svarog_shape.h"
#include "core/ds-classes/Array.h"
struct index_list {
    std::vector<unsigned int>polygon_index;
    void add_index(unsigned int index) {
        polygon_index.push_back(index);
    }

    unsigned int get_index(int val) const {
        return polygon_index[val];
    }
};

class SvarogCube {
    private:
        std::vector<SvarogPolygon>cube_vertexs;
        index_list cube_indicies;
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
            cube_vertexs.push_back(polygon_1);
            cube_vertexs.push_back(polygon_2);
            cube_vertexs.push_back(polygon_3);
            cube_vertexs.push_back(polygon_4);
            cube_vertexs.push_back(polygon_5);
            cube_vertexs.push_back(polygon_6);
            cube_indicies.add_index(0);
            cube_indicies.add_index(1);
            cube_indicies.add_index(3);
            cube_indicies.add_index(1);
            cube_indicies.add_index(2);
            cube_indicies.add_index(3);
            cube_indicies.add_index(0);
            cube_indicies.add_index(1);
            cube_indicies.add_index(2);
            /*cube_indices.push_back(index_list(0, 1, 3));
            cube_indices.push_back(index_list(1, 2, 3));
            cube_indices.push_back(index_list(0, 1, 2));
            cube_indices.push_back(index_list(3, 4, 5));
            cube_indices.push_back(index_list(1, 3, 4));
            cube_indices.push_back(index_list(4, 5, 6));
            */
        }

    public:
        SvarogCube();
        Vector3 get_cube_position() const;
        Vector3 get_cube_size() const;
        SvarogShape get_cube_mesh() const;
        void translate_cube(Vector3 translation_point);
        void rotate_cube(Vector3 rotation_axis);
        void scale_cube(Vector3 scale_factor);
        void make_cube();
};
#endif