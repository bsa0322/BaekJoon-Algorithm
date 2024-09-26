#include <iostream>
#include <set>

using namespace std;

/**
 * https://www.acmicpc.net/problem/2941
 */

int main() {
    set<string> croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    int answer = 0;
    string input;
    cin >> input;

    for (int i = 0; i < input.length();) {
        if (croatia.find(input.substr(i, 2)) != croatia.end()) {
            answer++;
            i += 2;
            continue;
        }
        if (croatia.find(input.substr(i, 3)) != croatia.end()) {
            answer++;
            i += 3;
            continue;
        }
        answer++;
        i++;
    }

    cout << answer;
    return 0;
}