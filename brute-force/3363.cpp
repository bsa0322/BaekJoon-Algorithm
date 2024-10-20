#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, bool> pi;

const int N = 3; // 식 개수
const int M = 4; // 저울 하나에 올라가는 동전 개수
const int C = 12; // 동전 개수
const string IMPOSSIBLE = "impossible";
const string INDEFINITE = "indefinite";

// 가짜 동전인지 확인
bool isFakeCoin(int coin, bool relation, vector<vector<int>> &coins, vector<char> &relations) {
    for (int i = 0; i < N; i++) {
        bool is_exist = false; // 부등호 있을 땐 나와야 함
        for (int j = 0; j < M * 2; j++) {
            int coin_num = coins[i][j];
            if (relations[i] == '=' && coin_num == coin) {
                // 등호 있으면 -> 가짜 동전 아님
                return false;
            } else if (relations[i] != '=' && coin_num == coin) {
                is_exist = true;
                bool curr_relation;
                if (j < M) {
                    curr_relation = relations[i] == '>';
                } else {
                    curr_relation = relations[i] == '<';
                }
                if (relation != curr_relation) {
                    // 관계가 다르다면 -> 가짜 동전 아님
                    return false;
                }
            }
        }
        if (relations[i] != '=' && !is_exist) {
            return false;
        }
    }
    return true;
}

// 가짜 동전 리스트 구하기
vector<pi> findFakeCoins(vector<vector<int>> &coins, vector<char> &relations) {
    vector<pi> fake_coins;
    for (int i = 1; i <= C; i++) {
        // 무거운 경우
        if (isFakeCoin(i, true, coins, relations)) {
            fake_coins.emplace_back(i, true);
        }

        // 가벼운 경우
        if (isFakeCoin(i, false, coins, relations)) {
            fake_coins.emplace_back(i, false);
        }
    }
    return fake_coins;
}

int main() {
    vector<vector<int>> coins(N, vector<int>(M * 2, 0));
    vector<char> relations(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M * 2; j++) {
            if (j == M) {
                cin >> relations[i];
            }
            cin >> coins[i][j];
        }
    }

    // 동전 12개에 대해서 각각 가볍고 무거운 경우 모두 해보기
    vector<pi> fake_coins = findFakeCoins(coins, relations);

    // 디버깅
//    for (int i = 0; i < fake_coins.size(); i++) {
//        cout << fake_coins[i].first << ' ' << fake_coins[i].second << '\n';
//    }

    // 출력
    if (fake_coins.size() == 1) {
        // 가짜 동전 딱 1개 있음!
        cout << fake_coins[0].first << (fake_coins[0].second ? '+' : '-');
    } else if (fake_coins.size() == 0) {
        // 가짜 동전 되는 게 하나도 없다면 -> 모순
        cout << IMPOSSIBLE;
    } else {
        // 가짜 동전 되는 게 여러 개 있다면 -> 알 수 없음
        cout << INDEFINITE;
    }
    return 0;
}