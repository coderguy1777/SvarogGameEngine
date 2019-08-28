#pragma once 
#ifdef LOGGERGROUP_H
#define LOGGERGROUP_H
#endif 
#include "core/String.h"
#include "core/ds-classes/Pair.h"
#include "core/ds-classes/Array.h"
#include "Message.h"
#include "macrodefs.h"
#include<ostream>
#include<fstream>
#include<sstream>
template<class X, class Y>
FORWARD_DEC(LoggerGroup);

template<class X, class Y>
class LoggerGroup {
    private:
        X const &group_type;
        Y const &sub_group_type;
        struct GroupLog {
            Array<Pair<X, Y>>file_log;
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

        // getters for group type and sub group type.
        X get_group_type() const;
        Y get_sub_group_type() const;

        // setters for group types and sub group types.
        void set_group_type(X const&);
        void set_sub_group_type(Y const&);

        // setters for the group log struct.
        void set_is_printed_log(bool output_log);
        void set_array_log(Array<Pair<X, Y>>log);

        // getters for group log struct.
        bool is_log_printed() const;
        Array<Pair<X, Y>>get_group_log_array() const;

        // file information setup
        void set_file_title(String file_title);
        void set_file_type(String file_type);
        void set_output_path(String output_path);
        void set_max_size(int max_size);

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