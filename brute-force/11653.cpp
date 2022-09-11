//
// Created by BaeSuA on 2022-09-10.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> primeDivide(int n) {
    vector<int> result;
    for (int i = 2; i <= n;) {
        if (n % i == 0) {
            result.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }
    return result;
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산 & 출력
    vector<int> result = primeDivide(n);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}