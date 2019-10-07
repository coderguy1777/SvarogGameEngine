#include "gui_layer.h"
template<class T>
void ImGuiLayer<T>::add_gui_component(T const& gui_part) {
    component_stack->push(gui_part);
}

template<class T>
T ImGuiLayer<T>::get_gui_component() const {
    return component_stack->top();
}

template<class T>
void ImGuiLayer<T>::pop_gui_component() {
    component_stack->pop();
}

template<class T>
T ImGuiLayer<T>::get_top_component() const {
    component_stack->top();
}