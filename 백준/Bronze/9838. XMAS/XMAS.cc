#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, gift_num;
    cin >> n;
    vector<int> gifts_people(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> gift_num;
        gifts_people[gift_num - 1] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << gifts_people[i] << '\n';
    }
    return 0;
}