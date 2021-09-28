#include <iostream>

using namespace std;

int table[1000010];

int main() {
    int n;

    //입력
    cin >> n;

    //연산
    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2]; //뒤에 00을 붙이거나 1을 붙이는 경우 더하기
        table[i] %= 15746;
    }

    //출력
    cout << table[n] << '\n';

    return 0;
}