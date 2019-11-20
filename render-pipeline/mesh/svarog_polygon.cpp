#include "svarog_polygon.h"
SvarogPolygon::SvarogPolygon() {
    has_max_count = (verticies.vertex_storage.size() == 3) ? true : false;
}

bool SvarogPolygon::get_count_state() const {
    return has_max_count;
}

std::vector<Vector3>SvarogPolygon::get_polygon_vertex_li() const {
    return (verticies.vertex_storage);
}

void SvarogPolygon::add_vertex(const Vector3& vertex) {
    if(get_count_state()) {
        spdlog::error("UNABLE TO ADD POLYGON VERTEX, MAX REACHED");
    } else if(!get_count_state()) {
        verticies.add_new_verticie(vertex);
    }
}

