#pragma once

#include <string>
#include <thread>
#include <atomic>
#include <functional>

class DataReceiver {
public:
    using DataCallback = std::function<void(const std::string&)>;
    
    DataReceiver(const std::string& connectAddress, DataCallback callback);
    ~DataReceiver();
    
    void start();
    void stop();
    
private:
    void run();
    
    std::string connectAddress;
    DataCallback callback;
    std::thread receiverThread;
    std::atomic<bool> running;
};