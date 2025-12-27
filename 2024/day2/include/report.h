#include <array>
#include <iostream>


class Report {
public:
    Report(std::array<int, 5> levels) {
        this->levels = levels;
    }

    void sayHello();

private:
    std::array<int, 5> levels{}; 
};
