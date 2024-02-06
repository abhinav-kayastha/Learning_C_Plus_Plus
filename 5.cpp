//
// Created by abhin on 06/02/2024.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iterator>

using namespace std;

class LottoNumberGenerator {
public:
    LottoNumberGenerator(int min, int max) : numbers(), min(min), max(max) {
        srand(time(NULL));
    }

    int operator()() {
        int number;
        do {
            number = rand() % (max - min + 1) + min;
        } while (find(numbers.begin(), numbers.end(), number) != numbers.end());
        numbers.push_back(number);
        return number;
    }

    const vector<int>& getNumbers() const {
        return numbers;
    }

private:
    vector<int> numbers;
    int min;
    int max;
};

struct PrintWithIndex {
    int index = 1;
    void operator()(int number) {
        cout << "#" << index++ << ": " << number << endl;
    }
};

int main() {
    char continueGenerating;

    LottoNumberGenerator lottoGenerator(1, 40);
    LottoNumberGenerator vikingLottoGenerator(1, 48);
    LottoNumberGenerator eurojackpotGenerator(1, 50);

    do {
        vector<int> lottoNumbers(7);
        vector<int> vikingLottoNumbers(6);
        vector<int> eurojackpotNumbers(5);

        generate(lottoNumbers.begin(), lottoNumbers.end(), lottoGenerator);
        generate(vikingLottoNumbers.begin(), vikingLottoNumbers.end(), vikingLottoGenerator);

        sort(lottoNumbers.begin(), lottoNumbers.end());
        sort(vikingLottoNumbers.begin(), vikingLottoNumbers.end());

        cout << "Lotto: ";
        copy(lottoNumbers.begin(), lottoNumbers.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        cout << "Viking lotto: ";
        copy(vikingLottoNumbers.begin(), vikingLottoNumbers.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        // Find matching numbers between Lotto and Viking Lotto
        cout << "Matched numbers in Lotto & Viking Lotto:" << endl;
        vector<int> matchingNumbers1;
        set_intersection(lottoNumbers.begin(), lottoNumbers.end(),
                         vikingLottoNumbers.begin(), vikingLottoNumbers.end(),
                         back_inserter(matchingNumbers1));
        PrintWithIndex printIndex1;
        for_each(matchingNumbers1.begin(), matchingNumbers1.end(), printIndex1);
        cout << endl;

        // Generate Eurojackpot numbers
        generate(eurojackpotNumbers.begin(), eurojackpotNumbers.end(), eurojackpotGenerator);

        sort(eurojackpotNumbers.begin(), eurojackpotNumbers.end());

        cout << "Eurojackpot: ";
        copy(eurojackpotNumbers.begin(), eurojackpotNumbers.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        // Find matching numbers in all three sets
        cout << "Matching numbers in all three sets:" << endl;
        vector<int> finalMatchingNumbers;
        set_intersection(matchingNumbers1.begin(), matchingNumbers1.end(),
                         eurojackpotNumbers.begin(), eurojackpotNumbers.end(),
                         back_inserter(finalMatchingNumbers));

        PrintWithIndex printIndex2;
        for_each(finalMatchingNumbers.begin(), finalMatchingNumbers.end(), printIndex2);
        cout << endl;

        cout << "Continue? (y/n): ";
        cin >> continueGenerating;

    } while (continueGenerating == 'y' || continueGenerating == 'Y');

    return 0;
}