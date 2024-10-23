#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pi;

/**
 * https://www.acmicpc.net/problem/30453
 *
 * 해시맵 풀이
 *
 * i: 0 ~ n, j: 0 ~ n 까지 모든 조합을 구함으로써 (a, b) (b, a) 점이 대칭되는 경우를 따로 고려 !!
 * 이렇게 되면 굳이 이미 카운트한 포인트를 check하지 않아도 되는 효과 !!
 *
 * 이때, i가 현재 검사하고 있는 point라고 했을 때, j와의 쌍에서 서로 다른 P 좌표가 나올 때만 카운트 해줘야 함
 * (안 그럼, 같은 key에 대해서 i 번째 좌표가 중복 카운팅 되는 것이므로 !!)
 *
 * 흠 근데 이것도 시간초과...??
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    unordered_map<string, int> cnt_per_p;

    cin >> n;
    vector<pi> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // 조합 구하면서 카운팅
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = points[i].first + points[j].first;
            int y = points[i].second + points[j].second;
            string key = to_string(x) + "," + to_string(y);

            if (cnt_per_p[key] <= i) {
                cnt_per_p[key]++;
            }
            answer = max(answer, cnt_per_p[key]);
        }
    }

    cout << answer;
    return 0;
}