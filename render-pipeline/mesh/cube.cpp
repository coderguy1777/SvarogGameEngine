#include "cube.h"
SvarogCube::SvarogCube() {
    add_cube_data();
}

Vector3 SvarogCube::get_cube_position() const {
    return cube_position;
}

Vector3 SvarogCube::get_cube_size() const {
    return Vector3(cube_size_data.get_cube_length(), cube_size_data.get_cube_width(), cube_size_data.get_cube_height());
}

void SvarogCube::translate_cube(Vector3 translation_position) {
    cube_position = get_cube_position() + translation_position;
}

void SvarogCube::scale_cube(Vector3 scale_factor) {
    auto length_scale = cube_size_data.get_cube_length() * scale_factor.getComponentX();
    auto width_scale = cube_size_data.get_cube_width() * scale_factor.getComponentY();
    auto height_scale = cube_size_data.get_cube_height() * scale_factor.getComponentZ();
    cube_size_data.modify_cube_size(length_scale, width_scale, height_scale);
}

void SvarogCube::make_cube() {
    std::vector<float>cube_polygons;
    std::vector<uint>cube_indexs;
    for(unsigned int i =0; i < cube_vertexs.size(); i++) {
        auto temp = cube_vertexs[i];
        cube_polygons.push_back(temp.get_vertex().getComponentX());
        cube_polygons.push_back(temp.get_vertex().getComponentY());
        cube_polygons.push_back(temp.get_vertex().getComponentZ());
    }

    for(unsigned int j = 0; j < cube_indices[j].polygon_index.size(); j++) {
        auto temp = cube_indices[j].polygon_index[j];
        cube_indexs.push_back(temp);
    }

    cube_mesh.pass_vert_data(cube_polygons);
    cube_mesh.pass_position_data(cube_indexs);
}

SvarogShape SvarogCube::get_cube_mesh() const {
    return cube_mesh;
}