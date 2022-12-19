#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 52;

int alpha(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A';
    return ch - 'a' + 26;
}

char num(int a) {
    if (a >= 0 && a < 26)
        return a + 'A';
    return a - 26 + 'a';
}

void floyd(vector<vector<bool>> &matrix) {
    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            if (i == k || !matrix[i][k])
                continue;
            for (int j = 0; j < SIZE; j++) {
                if (j == k || i == j || !matrix[k][j])
                    continue;
                matrix[i][j] = true;
            }
        }
    }
}

int main() {
    vector<vector<bool>> matrix(SIZE, vector<bool>(SIZE, 0));
    int n;
    string s;

    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        int a = alpha(s[0]);
        int b = alpha(s[5]);
        matrix[a][b] = true;
    }
    for (int i = 0; i < SIZE; i++)
        matrix[i][i] = true;

    floyd(matrix);
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) continue;
            if (matrix[i][j]) cnt++;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) continue;
            if (matrix[i][j]) {
                char p = num(i);
                char q = num(j);
                cout << p << " => " << q << '\n';
            }
        }
    }
    return 0;
}