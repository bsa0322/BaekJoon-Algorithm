#include <iostream>
#include <vector>
#include <map>

using namespace std;

string getToeJump(vector<int> &direc_index, vector<string> &input, map<string, string> &toe_jump) {
    for (auto toe: toe_jump) {
        bool flag = true;
        int idx = 0;
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].length(); j++) {
                if (toe.second[direc_index[idx++]] != input[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            return toe.first;
        }
    }
    return "?";
}

int main() {
    map<string, string> toe_jump; // 방향 'S' 기준 토 점프 정보
    toe_jump["T"] = ".OP.";
    toe_jump["F"] = "I..P";
    toe_jump["Lz"] = "O..P";

    map<char, vector<int>> direc_index; // 방향 'S' 기준 인덱스 방향
    direc_index['S'] = {0, 1, 2, 3};
    direc_index['N'] = {3, 2, 1, 0};
    direc_index['W'] = {2, 0, 3, 1};
    direc_index['E'] = {1, 3, 0, 2};

    char direc;
    vector<string> input(2);
    cin >> direc;
    for (int i = 0; i < 2; i++) {
        cin >> input[i];
    }

    cout << getToeJump(direc_index[direc], input, toe_jump);
    return 0;
}