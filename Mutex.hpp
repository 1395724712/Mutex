#ifndef WH_MUTEX_HPP
#define WH_MUTEX_HPP

#include<pthread.h>
#include<errno.h>
#if defined(__clang__) && (!defined(SWIG))
#define THREAD_ANNOTATION_ATTRIBUTE__(x)   __attribute__((x))
#else
#define THREAD_ANNOTATION_ATTRIBUTE__(x)   // no-op
#endif

#define GUARDED_BY(x) \
  THREAD_ANNOTATION_ATTRIBUTE__(guarded_by(x))

//互斥锁
class Mutex{
public:
    //构造函数，负责锁的初始化
    Mutex();
    //析构函数，负责锁的销毁
    ~Mutex();
    //加锁
    void lock();
    //解锁
    void unlock();
private:
    pthread_mutex_t mutex_;
};

class MutexLock{
public:
    //不进行默认构造
    MutexLock() = delete;
    //不进行拷贝构造
    MutexLock(const MutexLock&) = delete;
    //构造函数加锁
    explicit MutexLock(Mutex& mutex);
    // 析构函数解锁
    ~MutexLock();
private:
    Mutex& mutex_;
};
#endif