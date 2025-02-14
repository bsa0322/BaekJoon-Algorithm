#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 20;
const int ALICE_SIZE = 3;

int main() {
    int alice_sum, total_sum = 0, alice_idx;
    vector<int> num(SIZE);
    for (int i = 0; i < SIZE; i++) {
        cin >> num[i];
        if (num[i] == SIZE) {
            alice_idx = i;
        }
        total_sum += num[i];
    }
    alice_sum = num[(alice_idx - 1 + SIZE) % SIZE] + num[alice_idx] + num[(alice_idx + 1) % SIZE];
    double alice = (double) alice_sum / ALICE_SIZE;
    double bob = (double) total_sum / SIZE;
    if (alice > bob) {
        cout << "Alice";
    } else if (alice < bob) {
        cout << "Bob";
    } else {
        cout << "Tie";
    }
}