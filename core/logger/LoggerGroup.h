#pragma once 
#ifndef LOGGERGROUP_H
#define LOGGERGROUP_H 
#include "core/String.h"
#include "core/ds-classes/Pair.h"
#include "core/ds-classes/Array.h"
#include "core/events/event-types/mouseevent.h"
#include "core/ds-classes/ArrayList.h"
#include "Message.h"
#include<ostream>
#include<fstream>
#include<sstream>
#include "macrodefs.h"
template<class X, class Y>
FORWARD_DEC(LoggerGroup);

template<class X, class Y>
class LoggerGroup {
    private:
        struct GroupLog {
            ArrayList<X>parent_log;
            ArrayList<Y>sub_type_log;
            bool is_printed;
        } log_group;

        struct GroupLogFile {
            String title;
            String file_type;
            String output_path;
            int max_file_size;
            const unsigned int min_file_size = 0;
        } log_group_file;

        GroupLogFile *group_file_log;
        GroupLog *group_log;
        bool is_in_log;
    public:
        LoggerGroup() {
            group_log = new GroupLog();
            group_file_log = new GroupLogFile();
        }

        // assertion so group log isnt logged if its in a file group.
        inline void group_is_in_log_group();
        bool get_is_in_log() const;


        // setters for the group log struct.
        void set_is_printed_log(bool output_log);

        // getters for group log struct.
        bool is_log_printed() const;

        // file information setup
        void set_file_title(String file_title);
        void set_file_type(String file_type);
        void set_output_path(String output_path);
        void set_max_size(int max_size);

        /*
        inline void set_pt_log_len(unsigned int len) {
            group_log->parent_log.setSize(len);
        }

        inline void set_sb_log_len(unsigned int len) {
            group_log->sub_type_log.setSize(len);
        }
       */
        void size_tst() {
            std::cout << group_log->parent_log.size() << std::endl;
        }

        // adding to keyevent arr.
        void add_to_parent_log(X const& item);
        void add_to_sub_type_log(Y const& item);

        const char* get_file_title() const;
        const char* get_file_type() const;
        const char* get_output_path() const; 
        int get_max_size() const;

        // file streaming method for group log
        void stream_group_log();

        // operator overloads
        void * operator new(size_t size) {
            void * p = ::new LoggerGroup();
            return p;
        }
};
#endif