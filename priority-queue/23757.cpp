//
// Created by BaeSuA on 2022-09-25.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m, gift, child;

    cin >> n >> m;
    priority_queue<int> pq; //최대 힙
    for (int i = 0; i < n; i++) {
        cin >> gift;
        pq.push(gift);
    }
    for (int i = 0; i < m; i++) {
        cin >> child;
        if (pq.top() < child) { //실망
            cout << 0;
            return 0;
        }
        int num = pq.top();
        pq.pop();
        pq.push(num - child);
    }
    cout << 1;
    return 0;
}