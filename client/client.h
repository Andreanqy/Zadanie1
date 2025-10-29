#pragma once
#include <string>
#include "data_receiver.h"

class Client {
public:
    Client(const std::string& connectAddress);
    void start();
    void stop();
    
private:
    void onDataReceived(const std::string& data);
    
    std::string connectAddress;
    DataReceiver* receiver;
};