//
// Created by BaeSuA on 2022-09-07.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int SIZE = 1e6;

vector<bool> isPrime() {
    vector<bool> is_prime(SIZE + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= SIZE; i++) {
        for (int j = i * i; j <= SIZE; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

bool isAnswer(int num) {
    set<int> s;
    int k = num, sum;
    while (true) {
        sum = 0;
        while (k > 0) {
            int temp = k % 10;
            sum += temp * temp;
            k /= 10;
        }
        // 이미 존재한다면->상근수 x
        if (s.find(sum) != s.end()) {
            return false;
        }
        if (sum == 1) {
            return true;
        }
        s.insert(sum);
        k = sum;
    }
}

vector<int> solution(int n, vector<bool> &is_prime) {
    vector<int> ans;
    for (int i = 2; i < is_prime.size(); i++) {
        if (i > n) {
            break;
        }
        if (!is_prime[i]) {
            continue;
        }
        // 소수이다
        // 상근수 판단
        if (isAnswer(i)) {
            ans.push_back(i);
        }
    }
    return ans;
}

/**
 * 상근수: 각 자리 제곱 합이 결국 1이 되는 수
 * 소수상근수: 소수 + 상근수
 *
 * 먼저 에라토스테네스의 체로 소수 구하고
 * 상근수인지 판단?
 */

int main() {
    int n;

    // 입력
    cin >> n;
    // 연산
    vector<bool> is_prime = isPrime();
    vector<int> ans = solution(n, is_prime);
    // 출력
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}