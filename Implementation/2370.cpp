#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int getVisiblePosterCnt(int &n, vector<pi> &posters) {
    priority_queue<pi, vector<pi>, greater<>> pq; // 최소힙
    int answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        queue<pi> temp_q;
        bool flag = true;
        while (!pq.empty()) {
            int curr_l = pq.top().first;
            int curr_r = pq.top().second;
            pq.pop();

            if (posters[i].first >= curr_l && posters[i].second <= curr_r) {
                // 완전 포함 -> 삭제
                flag = false;
                temp_q.push({curr_l, curr_r}); // 다시 넣기
                break;
            }
            if (posters[i].first <= (curr_r + 1) && posters[i].second >= (curr_l - 1)) {
                // 겹치거나 이어진다면
                posters[i].first = min(posters[i].first, curr_l);
                posters[i].second = max(posters[i].second, curr_r);
            } else {
                // 완전 다른 영역에 있다면
                temp_q.push({curr_l, curr_r}); // 다시 넣기
            }
        }
        if (flag) {
            answer++;
            temp_q.push(posters[i]);
        }
        while (!temp_q.empty()) {
            pq.push(temp_q.front());
            temp_q.pop();
        }
    }
    return answer;
}

int main() {
    int n;

    cin >> n;
    vector<pi> posters(n);
    for (int i = 0; i < n; i++) {
        cin >> posters[i].first >> posters[i].second;
    }

    cout << getVisiblePosterCnt(n, posters);

    return 0;
}