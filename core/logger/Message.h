#pragma once
#ifdef MESSAGE_H
#define MESSAGE_H
#endif
#include "core/String.h"
#include "core/ds-classes/Pair.h"
#include "core/ds-classes/Array.h"
class Message {
    private:
        struct MessageContent {
            Array<String, 10>msg_data;
            unsigned int msg_id;
            Array<String, 10>msg_types;
            unsigned int type;
        } msg_content;
        MessageContent *content;

    public: 
        Message() {
            content = new MessageContent();
        }
        // getters for message
        Array<String, 10> getmsg_data() const;
        Array<String, 10> getmsg_types() const;
        unsigned int get_msg_id() const;
        unsigned int get_type_id() const;

        // setters for message
        void set_msg_data(Array<String, 10>new_data);
        void set_msg_types(Array<String, 10>new_types);
        
        Array<String, 10>get_msg_data() const;
        Array<String, 10>get_msg_types() const;
};