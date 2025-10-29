#include "client.h"
#include "data_sorter.h"
#include <iostream>

// Конструктор
Client::Client(const std::string& connectAddress) : connectAddress(connectAddress), receiver(nullptr) {}

// Запуск клиента
void Client::start() {
    receiver = new DataReceiver(connectAddress, [this](const std::string& data) { this->onDataReceived(data); });
    receiver->start();
}

// Остановка клиента
void Client::stop() {
    if (receiver) {
        receiver->stop();
        delete receiver;
        receiver = nullptr;
    }
}

// Обработка данных о студентах
void Client::onDataReceived(const std::string& data) {
    std::vector<Student> students = DataSorter::parseStudents(data);
    DataSorter::sortStudents(students);
    DataSorter::displayStudents(students);
}