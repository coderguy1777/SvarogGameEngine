#pragma once
#ifdef MESSAGE_H
#define MESSAGE_H
#endif
#include "core/String.h"
#include "core/ArrayList.h"
#include "core/Pair.h"
#include "Event.h"
typedef struct {
    int ID;
    Event event;
    const char* type;
} Information;
class Message {
    private:
        String msgLog;
        Information info;
    public:
        Message(Information information, String log) {
            this->msgLog = log;
            this->info = information;
        }
        
        Pair<Information, String> createMSG() {
            Pair<Information, String>msg;
            msg.setitemA(this->info);
            msg.setitemB(msgLog);
            return msg;
        }
};