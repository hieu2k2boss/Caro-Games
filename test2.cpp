#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx; // Mutex để bảo vệ biến đếm

void increment(int& counter) {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Khóa mutex trước khi truy cập biến đếm
        ++counter;
    }
}

int main() {
    int counter = 0;
    std::vector<std::thread> threads;

    // Tạo và khởi động 10 luồng
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(increment, std::ref(counter)));
    }

    // Chờ các luồng hoàn thành
    for (auto& th : threads) {
        th.join();
    }

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
