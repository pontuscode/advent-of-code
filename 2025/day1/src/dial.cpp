#include <format>
#include <iostream>
#include "dial.h"
#include "logger.h"


bool Dial::rotate(const std::string& input) {
    std::string temp = input;
    Direction dir;
    if(input.front() == 'L') {
        dir = LEFT;
    } else {
        dir = RIGHT;
    }

    std::string rem = temp.erase(0, 1); 
    return this->rotate(dir, std::stoi(rem));
}


bool Dial::rotate(const Direction& direction, const int& value) {
    int _val = direction * value;
    std::cout << "Current position: " << this->position << std::endl;
    if(_val < 0) {
        this->position = this->doNegativeRotation(_val);
    } else {
        this->position = this->doPositiveRotation(_val);
    }
    std::cout << "New position: " << this->position << "\n---\n";
    return this->position == 0;
}


int Dial::doNegativeRotation(const int& value) {
    std::cout << std::format("Rotating {} steps to the left\n", value);
    int _normalized = value % 100;

    if(abs(_normalized) > this->position) {
        return 100 - (abs(value % 100) - this->position); 
    } else {
        return this->position - abs(_normalized);
    }
}


int Dial::doPositiveRotation(const int& value) {
    std::cout << std::format("Rotating {} steps to the right\n", value);
    int _normalized = value % 100;
    int newVal = _normalized + this->position;

    if(newVal > 100) {
        return newVal - 100;
    } else if(newVal == 100) {
        return 0;
    } else {
        return newVal;
    }
}
