#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "server/server.h"
#include "client/client.h"

int main() {
    std::string bindAddress = "tcp://*:5555";
    std::string connectAddress = "tcp://localhost:5555";
    
    int choice;
    std::cout << "Select mode:\n1. Server\n2. Client\n3. Both\nChoice: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    Server* server = nullptr;
    Client* client = nullptr;
    
    if (choice == 1 || choice == 3) {
        server = new Server(bindAddress);
        server->start();
        std::cout << "Server started..." << std::endl;
    }
    
    if (choice == 2 || choice == 3) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        client = new Client(connectAddress);
        client->start();
        std::cout << "Client started..." << std::endl;
    }
    
    if (choice == 3) {
        std::cout << "Both server and client running. Press Enter to stop..." << std::endl;
    } else if (choice == 1) {
        std::cout << "Server running. Press Enter to stop..." << std::endl;
    } else if (choice == 2) {
        std::cout << "Client running. Press Enter to stop..." << std::endl;
    }
    
    std::cin.ignore();
    std::cin.get();
    
    if (server) {
        server->stop();
        delete server;
    }
    
    if (client) {
        client->stop();
        delete client;
    }
    
    return 0;
}