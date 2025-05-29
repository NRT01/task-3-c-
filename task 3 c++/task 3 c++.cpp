#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include "Queue.h"

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);

    try {
        Queue<int> qInt;

        qInt.enqueue(5);
        qInt.enqueue(15);
        qInt.enqueue(25);

        qInt.print();

        std::wcout << L"Первый элемент (peek): " << qInt.peek() << std::endl;

        std::wcout << L"Удаляем элемент: " << qInt.dequeue() << std::endl;

        qInt.print();

        qInt.clear();

        qInt.print();

        // Теперь очередь со строками (wstring)
        Queue<std::wstring> qStr;

        qStr.enqueue(L"один");
        qStr.enqueue(L"два");
        qStr.enqueue(L"три");

        qStr.print();

        while (!qStr.isEmpty()) {
            std::wcout << L"Удаляем элемент: " << qStr.dequeue() << std::endl;
        }

        qStr.print();

    }
    catch (const std::exception& e) {
        std::wcerr << L"Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
