#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<int> calc(int n, vector<ci> &people) {
    vector<int> result(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (people[i].first < people[j].first && people[i].second < people[j].second)
                result[i]++;
        }
    }
    return result;
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<ci> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i].first >> people[i].second;
    }

    //연산
    vector<int> result = calc(n, people);

    //출력
    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}