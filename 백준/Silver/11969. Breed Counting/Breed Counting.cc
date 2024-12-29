#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getPrefixSum(int &n, vector<int> &cow_owners) {
    vector<vector<int>> sum(n + 1, vector<int>(4, 0));
    for (int i = 1; i <= n; i++) {
        sum[i][1] += sum[i - 1][1];
        sum[i][2] += sum[i - 1][2];
        sum[i][3] += sum[i - 1][3];
        sum[i][cow_owners[i]]++;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q, a, b;
    cin >> n >> q;
    vector<int> cow_owners(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> cow_owners[i];
    }

    // 주인 별 누적합 구하기
    vector<vector<int>> sum = getPrefixSum(n, cow_owners);

    // 쿼리 출력
    while (q--) {
        cin >> a >> b;
        for (int i = 1; i <= 3; i++) {
            cout << sum[b][i] - sum[a - 1][i] << ' ';
        }
        cout << '\n';
    }
}