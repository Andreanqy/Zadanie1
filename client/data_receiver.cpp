#include "data_receiver.h"
#include <zmq.hpp>
#include <iostream>

// Конструктор
DataReceiver::DataReceiver(const std::string& connectAddress, DataCallback callback) : connectAddress(connectAddress), callback(callback), running(false) {}

// Деструктор
DataReceiver::~DataReceiver() {
    stop();
}

// Запуск приемника
void DataReceiver::start() {
    running = true;
    receiverThread = std::thread(&DataReceiver::run, this);
}

// Остановка приемника
void DataReceiver::stop() {
    running = false;
    if (receiverThread.joinable()) {
        receiverThread.join();
    }
}

// Работа приемника
void DataReceiver::run() {
    zmq::context_t context(1);
    zmq::socket_t subscriber(context, ZMQ_SUB);
    
    try {
        subscriber.connect(connectAddress);
        subscriber.set(zmq::sockopt::subscribe, "");
        
        while (running) {
            zmq::message_t message;
            auto result = subscriber.recv(message, zmq::recv_flags::none);
            
            if (result && running) {
                std::string data(static_cast<char*>(message.data()), message.size());
                callback(data);
            }
        }
        
    } catch (const zmq::error_t& e) {
        std::cerr << "ZMQ Error: " << e.what() << std::endl;
    }
}