//
// Created by abhin on 06/02/2024.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;

class IndexCounter {
public:
    IndexCounter() : index(0) {}
    int operator()() { return ++index; }
private:
    int index;
};

class LottoNumberGenerator {
public:
    LottoNumberGenerator(int min, int max) : distribution(min, max) {}

    vector<int> operator()() {
        vector<int> numbers(7);
        generate(numbers.begin(), numbers.end(), [this]() { return distribution(engine); });
        return numbers;
    }

private:
    default_random_engine engine{random_device{}()};
    uniform_int_distribution<int> distribution;
};

int main() {
    LottoNumberGenerator lotto(1, 40);
    LottoNumberGenerator vikingLotto(1, 48);
    LottoNumberGenerator euroJackpot(1, 50);

    IndexCounter indexCounter;

    char choice;
    do {
        vector<int> lottoNumbers = lotto();
        vector<int> vikingLottoNumbers = vikingLotto();
        vector<int> euroJackpotNumbers = euroJackpot();

        cout << "Lotto:";
        for_each(lottoNumbers.begin(), lottoNumbers.end(), [](int num) { cout << " " << num; });
        cout << endl;

        cout << "Viking lotto:";
        for_each(vikingLottoNumbers.begin(), vikingLottoNumbers.end(), [](int num) { cout << " " << num; });
        cout << endl;

        cout << "Eurojackpot:";
        for_each(euroJackpotNumbers.begin(), euroJackpotNumbers.end(), [](int num) { cout << " " << num; });
        cout << endl;

        vector<int> commonNumbers;
        set_intersection(lottoNumbers.begin(), lottoNumbers.end(),
                         vikingLottoNumbers.begin(), vikingLottoNumbers.end(),
                         back_inserter(commonNumbers));
        set_intersection(commonNumbers.begin(), commonNumbers.end(),
                         euroJackpotNumbers.begin(), euroJackpotNumbers.end(),
                         back_inserter(commonNumbers));

        cout << "Matching numbers:" << endl;
        for_each(commonNumbers.begin(), commonNumbers.end(), [&](int num) {
            cout << "#" << indexCounter() << ": " << num << endl;
        });

        cout << endl;
        cout << "Continue? (y/n): ";
        cin >> choice;
        cout << endl;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
