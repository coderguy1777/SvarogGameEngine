#pragma once
#ifdef MESSAGE_H
#define MESSAGE_H
#endif
#include "core/String.h"
#include "core/ArrayList.h"
#include "core/Pair.h"
struct Information {
    int ID;
    int Priority;
    const char* type;
};
template<class T>
class Message {
    private:
        String msgLog;
        T const& information;
    public:
        Message(T const& info, String log) {
            this->msgLog = log;
            this->information = info;
        }
        template<class A, class B>
        Pair createMSG() {
            Pair<T, String>msg;
            msg.setitemA(T const& information);
            msg.setitemB(String msgLog);
            return msg;
        }
};