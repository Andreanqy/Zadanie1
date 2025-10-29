#include "server.h"
#include "data_manager.h"
#include <zmq.hpp>
#include <iostream>
#include <chrono>

// Конструктор
Server::Server(const std::string& bindAddress) : bindAddress(bindAddress), running(false) {}

// Деструктор
Server::~Server() {
    stop();
}

// Запуск сервера
void Server::start() {
    running = true;
    serverThread = std::thread(&Server::run, this);
}

// Остановка сервера
void Server::stop() {
    running = false;
    if (serverThread.joinable()) {
        serverThread.join();
    }
}

// Работа сервера
void Server::run() {
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    
    try {
        publisher.bind(bindAddress);
        
        DataManager dataManager;
        dataManager.addStudentsFromFile("student_file_1.txt");
        dataManager.addStudentsFromFile("student_file_2.txt");
        dataManager.mergeDuplicates();
        
        std::string studentsData = dataManager.serializeStudents();
        
        while (running) {
            zmq::message_t message(studentsData.size());
            memcpy(message.data(), studentsData.c_str(), studentsData.size());

            publisher.send(message, zmq::send_flags::none);

            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
        
    } catch (const zmq::error_t& e) {
        std::cerr << "ZMQ Error: " << e.what() << std::endl;
    }
}