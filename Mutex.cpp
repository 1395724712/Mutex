#include"Mutex.hpp"
#include<assert.h>
Mutex::Mutex(){
    pthread_mutex_init(&mutex_,nullptr);
}

Mutex::~Mutex(){
    pthread_mutex_destroy(&mutex_);
}

void Mutex::lock(){
    int rtnVal = pthread_mutex_lock(&mutex_);
    assert(rtnVal==0);
}

void Mutex::unlock(){
    int rtnVal = pthread_mutex_unlock(&mutex_);
    assert(rtnVal==0);
}

MutexLock::MutexLock(Mutex& mutex):
mutex_(mutex)
{
    mutex_.lock();
}

MutexLock::~MutexLock(){
    mutex_.unlock();
}