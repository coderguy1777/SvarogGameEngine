#pragma once
#ifndef GUI_LAYER_H
#define GUI_LAYER_H
#include "macrodefs.h"
#include "core/ds-classes/Stack.h"
enum class LAYER_ITEM_TYPES {

};
template <class T>
class ImGuiLayer {
    private:
        Stack<T>*component_stack;
    public: 
        ImGuiLayer() {
            component_stack=new Stack<T>();
        }

        void add_gui_component(T const&);
        T get_gui_component() const;
        void pop_gui_component();
        T get_top_component() const;
};


#endif