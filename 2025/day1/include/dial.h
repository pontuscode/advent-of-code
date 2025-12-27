#pragma once


enum Direction {
    // Represents a rotation direction
    LEFT = -1,
    RIGHT = 1
};


class Dial {
public: 
    Dial() {}
    Dial(const int startPosition) {
        this->position = startPosition;
    }

    bool rotate(const std::string& input);
    bool rotate(const Direction& direction, const int& value);

private:
    int position = 50;

    int doPositiveRotation(const int&);
    int doNegativeRotation(const int&);
};
