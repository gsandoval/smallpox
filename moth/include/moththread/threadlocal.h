#ifndef THREADLOCAL_H
#define THREADLOCAL_H

#include <memory>
#include <pthread.h>

namespace moth
{

static pthread_key_t _local_storage_key;
static pthread_once_t _local_storage_key_once = PTHREAD_ONCE_INIT;

template <typename T>
class ThreadLocal {
private:
    static void Init() {
        pthread_key_create(&_local_storage_key, NULL);
    }
public:
    void Set(const T *value) {
        pthread_once(&_local_storage_key_once, ThreadLocal::Init);
        pthread_setspecific(_local_storage_key, value);
    }

    T* Get() {
        T *ptr = (T*) pthread_getspecific(_local_storage_key);
        return ptr;
    }
};

}

#endif // THREADLOCAL_H
