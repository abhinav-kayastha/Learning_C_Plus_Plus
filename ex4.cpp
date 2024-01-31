#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class House {
private:
    std::string address;
    double area;
    int price;

public:
    House() : area(0.0), price(0) {}

    House(const std::string& address, double area, int price)
            : address(address), area(area), price(price) {}

    friend std::ostream& operator<<(std::ostream& out, const House& house) {
        return out << house.address << " " << house.area << " " << house.price;
    }

    friend std::istream& operator>>(std::istream& in, House& house) {
        std::getline(in, house.address, ' ');
        in >> house.area >> house.price;
        in.ignore(); // Ignore the newline character
        return in;
    }

    bool operator<(const House& other) const {
        return static_cast<double>(price) / area < static_cast<double>(other.price) / other.area;
    }

    void setAddress(const std::string& addr) {
        address = addr;
    }

    void setArea(double a) {
        area = a;
    }

    void setPrice(int p) {
        price = p;
    }
};

int main() {
    std::vector<House> houses(5);

    // Ask user to enter information for five houses
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter information for house " << i + 1 << " (address area price): ";
        std::cin >> houses[i];
    }

    // Sort the vector of houses
    std::sort(houses.begin(), houses.end());

    // Print the sorted house information
    std::cout << std::endl;
    std::cout << "Sorted house information:\n";
    std::cout << std::endl;
    for (const auto& house : houses) {
        std::cout << house << std::endl;
    }

    return 0;
}
