#pragma once
#ifdef LOG_H
#define LOG_H
#endif 
#include "libs.h"
class Logger {
    private: 
        ArrayList<Pair<Information, String>>msgs;
    public:
        inline void addToMsgLi(Message e) {
            Pair<Information, String>MSG = e.createMSG();
            msgs.add(MSG);
        }

        inline Information getInfo() {
            return msgs.get(0).getitemA();
        }

        inline String getMsgStr() {
            return msgs.get(0).getitemB();
        }

        inline void clearmsgs() {
            for(unsigned int i = 0; i < msgs.size(); i++) {
                msgs.remove(i);
            }
        }

        inline void printAll() {
            String strinfo;
            for(unsigned int i = 0; i < msgs.size(); i++) {
                strinfo = msgs.get(i).getitemB();
                cout << "Message: " << strinfo.str << endl;
            }
        }
};