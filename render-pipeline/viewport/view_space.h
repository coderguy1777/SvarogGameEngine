#pragma once
#ifndef VIEW_SPACE_H
#define VIEW_SPACE_H
#include "render-pipeline/mesh/MeshGen.h"
#include "render-pipeline/shader/SvarogShader.h"

struct ViewSpace_Data {
    std::vector<SvarogShape>object_li;
    std::vector<SvarogShader>shader_li;
};

class ViewSpace {
    private:
        ViewSpace_Data* view_li;

    public: 
        ViewSpace();
        void insert_new_object(SvarogShape render_object);
        void render_all();}

};


#endif