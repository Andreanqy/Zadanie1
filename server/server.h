#pragma once

#include <string>
#include <thread>
#include <atomic>

class Server {
public:
    Server(const std::string& bindAddress);
    ~Server();
    
    void start();
    void stop();
    
private:
    void run();
    
    std::string bindAddress;
    std::thread serverThread;
    std::atomic<bool> running;
};