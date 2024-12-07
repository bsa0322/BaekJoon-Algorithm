#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

int getLateWorkTime(int &n, vector<pi> &tasks) {
    int curr_t = tasks[0].first - tasks[0].second; // 이 전 일이 끝나야 하는 최대 시간
    for (int i = 1; i < n; i++) {
        if (curr_t >= tasks[i].first) {
            // 끝내야 하는 시간보다 크다면 -> 갱신
            curr_t = tasks[i].first - tasks[i].second;
        } else {
            curr_t -= tasks[i].second;
            if (curr_t < 0) {
                return -1;
            }
        }
    }
    return (curr_t < 0 ? -1 : curr_t);
}

int main() {
    int n;
    cin >> n;
    vector<pi> tasks(n); // {끝내야 하는 시간, 걸리는 시간 (필요 시간)}
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].second >> tasks[i].first;
    }

    // 끝내야 하는 시간 기준 내림차순 정렬
    sort(tasks.begin(), tasks.end(), greater<>());

    cout << getLateWorkTime(n, tasks);
    return 0;
}