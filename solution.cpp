// Выполнил: Кузнецов Константин
// Advanced C++, 2018

// Программа для поиска в массиве всеx возможных 3-х ключей,
// сумма которых дает заданное значение.

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

typedef vector< pair<int, string> > pairs;

vector<pairs> FindPairs(pairs& input, int const target) {
    vector<pairs> output;
    sort(input.begin(), input.end());

    for (int i = 0; i < input.size(); ++i) {
        int front = i + 1;
        int back  = input.size() - 1;

        while (front < back) {
            int sum = input[i].first + input[front].first + input[back].first;

            if (sum < target) front++;
            else if (sum > target) back--;
            else {
                int tmp = front;
                while (front < back && input[tmp].first == input[front].first) {
                    pairs triplet = {input[i], input[front], input[back]};
                    output.emplace_back(triplet);
                    front++;
                }
                front = tmp;
                back--;
            }
        }
    }

    return output;
}

void PrintPairs(pairs& input) {
    for (auto& p : input)
        cout << p.first << ":" << p.second << " ";
}

int main(int argc, char const *argv[]) {
    int target    = 0;  // заданное значение
    int num_pairs = 0;  // количество пар: int -> string

    cin >> target >> num_pairs;
    pairs input;
    for (size_t i = 0; i < num_pairs; ++i) {
        int first;
        string second;
        cin >> first >> second;
        auto p = make_pair(first, second);
        input.emplace_back(p);
    }

    vector<pairs> output = FindPairs(input, target);
    for (auto& v : output) {
        PrintPairs(v);
        cout << endl;
    }

    return 0;
}
