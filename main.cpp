#include <iostream>
#include <memory>
#include <vector>
#include "factory.h"
#include "five_angles.h"
#include "eight_angles.h"
#include "six_angles.h"
#include "subscriber.h"

int main() {
    std::cout << "Input the size of buffer: ";
    int num = 10;
    std::cin >> num;
    const int32_t buffer_size = num;
    std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer =
            std::make_shared<std::vector<std::shared_ptr<figure>>>();
    buffer->reserve(buffer_size);
    factory factory;
    std::string command;
    std::cout << "Add - adding a new shape\n" << "Exit - the end of the program\n";
    //thread
    subscriber sub;
    sub.processors.push_back(std::make_shared<stream_processor>());
    sub.processors.push_back(std::make_shared<file_processor>());
    std::thread sub_thread(std::ref(sub));

    while (true)
    {
        std::unique_lock<std::mutex> guard(sub.mtx);
        std::cout << "Begin\n";
        std::cin >> command;
        if (command == "Add") {
            try
            {
                buffer->push_back(factory.FigureCreate(std::cin));
            }
            catch (std::logic_error &e)
            {
                std::cout << e.what() << '\n';
                continue;
            }
            if (buffer->size() == buffer_size)
            {
                sub.buffer = buffer;
                sub.cv.notify_all();
                sub.cv.wait(guard, [&](){ return sub.buffer == nullptr;});
                buffer->clear();
            }
        }
        else if (command == "Exit")
        {
            break;
        }
        else
        {
            std::cout << "Unknown command\n";
        }
    }

    sub.end = true;
    sub.cv.notify_all();
    sub_thread.join();

    return 0;
}
