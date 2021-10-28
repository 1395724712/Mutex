#include"Mutex.hpp"

#include<iostream>
#include<unistd.h>
#include<vector>
using namespace std;

Mutex mutex;

void* testFunc(void *){
    MutexLock lock(mutex);
    sleep(1);
    cout<<100<<endl;
}

int main(){
    vector<pthread_t> vec;
    for(int i=0;i<10;i++){
        pthread_t pID;
        pthread_create(&pID,nullptr,testFunc,nullptr);
        vec.push_back(pID);
    }

    for(auto pid:vec)
        pthread_join(pid,nullptr);


    cout<<"running success"<<endl;

    return 0;
}