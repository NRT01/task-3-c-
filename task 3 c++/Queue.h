#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[(front + i) % capacity];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
        front = 0;
        rear = size - 1;
    }

public:
    explicit Queue(int cap = 10)
        : capacity(cap), front(0), rear(-1), size(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& value) {
        if (size == capacity) {
            resize();
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        ++size;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Очередь пуста!");
        }
        T value = data[front];
        front = (front + 1) % capacity;
        --size;
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Очередь пуста!");
        }
        return data[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void print() const {
        if (isEmpty()) {
            std::wcout << L"Очередь пуста." << std::endl;
            return;
        }
        std::wcout << L"Содержимое очереди: ";
        for (int i = 0; i < size; ++i) {
            std::wcout << data[(front + i) % capacity] << L" ";
        }
        std::wcout << std::endl;
    }
};

#endif // QUEUE_H
