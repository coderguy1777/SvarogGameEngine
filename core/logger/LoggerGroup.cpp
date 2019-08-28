#include "LoggerGroup.h"
template<class X, class Y>
X LoggerGroup<X, Y>::get_group_type() const {
    return group_type;
}

template<class X, class Y>
Y LoggerGroup<X, Y>::get_sub_group_type() const {
    return sub_group_type;
}

template<class X, class Y>
void LoggerGroup<X, Y>::set_group_type(X const& new_type) {
    this->group_type = new_type;
}

template<class X, class Y>
void LoggerGroup<X, Y>::set_sub_group_type(Y const& sub_type) {
    this->sub_group_type = sub_type;
}

template<class X, class Y>
void LoggerGroup<X, Y>::set_is_printed_log(bool output_log) {
    group_log->is_printed = output_log;
}

template<class X, class Y>
void LoggerGroup<X, Y>::set_array_log(Array<Pair<X, Y>>log) {
    for(unsigned int i = 0; i < log.length() && i < group_log->file_log.length(); i++) {
        group_log->file_log.array[i] = log.array[i];
    }
}

template<class X, class Y>
bool LoggerGroup<X, Y>::is_log_printed() const {
    return group_log->is_printed;
}

template<class X, class Y>
Array<Pair<X, Y>> LoggerGroup<X, Y>::get_group_log_array() const {
    return group_log->file_log;
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
    std::string filepath = get_output_path() + get_file_title() + get_file_type();
    std::ofstream log_group_output(filepath, ios::out);
    bool output_check = is_log_printed();
    if(output_check) {
        do {
            for(unsigned int i = 0; i <= group_log->file_log.length(); i++) {
                log_group_output << group_log->file_log.array[i];
                log_group_output << '\n';
                if(i == group_log->file_log.length()) {
                    output_check = false;
                    log_group_output.close();
                }
            }
        } while(output_check);
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