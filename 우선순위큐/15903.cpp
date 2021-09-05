#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    int n, m, a;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    while (!pq.empty() && m-- > 0) {
        long long int card1 = pq.top();
        pq.pop();
        if (pq.empty()) break;
        long long int card2 = pq.top();
        pq.pop();
        pq.push(card1 + card2);
        pq.push(card1 + card2);
    }

    long long int ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
    return 0;
}
