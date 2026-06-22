#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

    unordered_map<string, vector<string>> mp;

    mp["Fruits"].push_back("Apple");
    mp["Fruits"].push_back("Banana");

    mp["Colors"].push_back("Red");
    mp["Colors"].push_back("Blue");

    for (auto &p : mp) {
        cout << p.first << " -> ";

        for (string x : p.second) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}