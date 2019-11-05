#include "svarog_thread.h"
template<class T>
bool SvarogThread<T>::get_max() const {
    is_max = (thread_tasks.size() > PROCESS_MAX) ? true : false;
    return is_max;
}