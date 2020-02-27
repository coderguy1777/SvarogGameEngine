#include "mesh/svarog_shape.h"

namespace MeshGeneration {
    static SvarogShape cube() {
        float vertices[] = {
            0.5f, 0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, 0.5f , -0.5f, 
            0.5f, 0.5f, -0.5f,
        };        
        
        unsigned int poss[] = {  
            0, 1, 3,  
            1, 2, 3,
            0, 1, 4,
        };

        SvarogShape mesh;
        std::vector<float>vertt;
        std::vector<unsigned int>pos;

        for(int i = 0; i < 15; i++) {
            vertt.push_back(vertices[i]);
        }
        for(int j = 0; j < 9; j++) {
            pos.push_back(poss[j]);
        }
        
        mesh.pass_position_data(pos);
        mesh.pass_vert_data(vertt);
        mesh.init();
        return mesh;
    }
}