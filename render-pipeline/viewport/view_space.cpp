#include "view_space.h"

ViewSpace::ViewSpace() {
    view_li = new ViewSpace_Data();
}

void ViewSpace::insert_new_object(SvarogShape render_obj) {
    view_li->object_li.push_back(render_obj);
}

void ViewSpace::render_all() {
    for(SvarogShape i: view_li->object_li) {
        i.draw();
    }
}