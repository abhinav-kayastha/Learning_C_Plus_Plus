//
// Created by abhin on 30/01/2024.
//

#include <iostream>
#include <deque>

class RunningAverage {
private:
    std::deque<int> values;
    const int size;

public:
    RunningAverage(int n) : size(n) {}

    void add_value(int value) {
        if (values.size() >= size) {
            values.pop_front();
        }
        values.push_back(value);
    }

    double get_average() const {
        if (values.empty()) {
            return 0.0;
        }

        double sum = 0;
        for (int val : values) {
            sum += val;
        }
        return sum / values.size();
    }
};

int main() {
    int input;
    std::cout << "Enter up to 5 numbers to calculate running average (enter 0 to stop):\n";

    RunningAverage avg(5);
    int count = 0;

    do {
        std::cin >> input;
        if (input != 0) {
            avg.add_value(input);
            std::cout << "Current running average: " << avg.get_average() << std::endl;
            count++;
        }
    }

    while (input != 0 && count < 5);

    std::cout << "Final running average: " << avg.get_average() << std::endl;

    return 0;
}
