#include <autobox_manager.h>

void AutoboxManager::read(){
    return;
}

void AutoboxManager::write(){
    return;
}

void AutoboxManager::Run(){
    while(1){
        read();
        write();
        usleep(100 * MILISECOND);
    }

    return;
}