#pragma once
#ifndef SVAROG_POLYGON_H
#define SVAROG_POLYGON_H
#include "math/vec3.h"
#include "spdlog/spdlog.h"
#include <vector>
#include <cmath>


class SvarogPolygon {
    private:
        struct VertexGroup {
            std::vector<Vector3>vertex_storage;
            unsigned int vertex_index;
            void add_new_verticie(const Vector3& new_vert) {
                vertex_storage.push_back(new_vert);
            }

            void assign_vert_order() {
                for(const auto& vertex: vertex_storage) {
                    auto vert_1 = vertex;
                    auto vert_2 = vertex_storage.front();
                }
            }
        };

        unsigned int vertex_count;
        VertexGroup verticies;
        bool has_max_count;
    public:
        SvarogPolygon();
        void add_vertex(const Vector3& new_vertex);
        bool get_count_state() const;
        std::vector<Vector3>get_polygon_vertex_li() const;
        unsigned int get_vertex_amount() const;
};


#endif