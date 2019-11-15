#include "ClassString.h"
ClassString::ClassString() {
    class_info.class_id = 0;
    class_info.class_name = "";
}

ClassString::ClassString(unsigned int class_id, std::string class_name) {
    class_info.class_id = class_id;
    class_info.class_name = class_name;
}

void ClassString::bind_class_string(unsigned int class_id, std::string class_name) {
    class_info.class_name = class_name;
    class_info.class_id = class_id;
}

std::string ClassString::get_class_str() const {
    return class_info.class_name;
}

unsigned int ClassString::get_class_id() const {
    return class_info.class_id;
}