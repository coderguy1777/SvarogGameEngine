#pragma once
#ifndef SVAROG_POLYGON_H
#define SVAROG_POLYGON_H
#include "math/vec3.h"
#include "spdlog/spdlog.h"
#include <vector>
#include <cmath>

struct vertex_ids {
    unsigned int vertex_index;
    Vector3 vertex;
    vertex_ids(Vector3 vertex, uint vert_index) {
        this->vertex = vertex;
        this->vertex_index = vert_index;
    }
};

class SvarogPolygon {
    private:
        unsigned int vertex_count;
        std::vector<vertex_ids>polygon_vertexs;
        bool has_max_count;
    public:
        SvarogPolygon();
        void add_vertex(const Vector3& new_vertex);
        bool get_count_state() const;
        std::vector<Vector3>get_polygon_vertex_li() const;
        unsigned int get_vertex_amount() const;
};


#endif