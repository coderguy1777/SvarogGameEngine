#include "LoggerGroup.h"
template<class X, class Y>
void LoggerGroup<X, Y>::set_is_printed_log(bool output_log) {
    group_log->is_printed = output_log;
}

template<class X, class Y>
bool LoggerGroup<X, Y>::is_log_printed() const {
    return group_log->is_printed;
}

template<class X, class Y>
void LoggerGroup<X, Y>::set_file_title(String file_title) {
    group_file_log->title = file_title;
}

template<class X, class Y>
void LoggerGroup<X, Y>::set_file_type(String output_type) {
    group_file_log->file_type = output_type;
}

template<class X, class Y>
void LoggerGroup<X, Y>::set_output_path(String path_output) {
    group_file_log->output_path = path_output;
}

template<class X, class Y>
void LoggerGroup<X, Y>::set_max_size(int max_size) {
    group_file_log->max_file_size = max_size;
}

template<class X, class Y>
const char* LoggerGroup<X, Y>::get_file_title() const {
    return group_file_log->title.str;
}

template<class X, class Y>
const char* LoggerGroup<X, Y>::get_file_type() const {
    return group_file_log->file_type.str;
}

template<class X, class Y>
const char* LoggerGroup<X, Y>::get_output_path() const {
    return group_file_log->output_path.str;
}

template<class X, class Y>
int LoggerGroup<X,Y>::get_max_size() const {
    return group_file_log->max_file_size;
}

// method that writes the file group log.
template<class X, class Y>
void LoggerGroup<X,Y>::stream_group_log() {
    std::string filepath = std::string(std::string(get_output_path())+ std::string(get_file_title()) + std::string(get_file_type()));
    std::ofstream log_group_output;
    log_group_output.open(filepath, std::ostream::out);
    bool output_check = is_log_printed();
    if(output_check) {
        do {
            for(unsigned int i = 0; i <= group_log->parent_log.size(); i++) {
                log_group_output << group_log->parent_log.get(i);
                log_group_output << '\n';
                if(i == group_log->parent_log.size() && i == group_log->sub_type_log.size()) {
                    output_check = false;
                    log_group_output.close();
                }
            }
        } while(output_check);
        log_group_output.close();
    } else if(!output_check) {
        throw std::invalid_argument("File output is not set, please set this too continue and out put the log as requested.");
        exit(0);
    }
}

template<class X, class Y>
void LoggerGroup<X,Y>::group_is_in_log_group() {
    ASSERT_EQUAL(is_log_printed(), false);
    ASSERT_EQUAL(is_in_log, true);
}

template<class X, class Y>
bool LoggerGroup<X, Y>::get_is_in_log() const {
    return (is_in_log);
}

template<class X, class Y>
void LoggerGroup<X, Y>::add_to_parent_log(const X &item) {
    group_log->parent_log.add(item);
}

MULT_TMP_TYPE(LoggerGroup, Event, int);
MULT_TMP_TYPE(LoggerGroup, Event, MouseEvent);