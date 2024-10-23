#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, pi> ppi;

/**
 * 꼭 정수만 다루는 건 아닌가 ?? -> 실수도 포함
 * -> 나누기 2 한 값 말고 더한 값으로만 확인
 * -> 했더니 시간초과..! 일단 접근은 맞다는건데..
 * -> unordered_map, key는 string으로
 * -> 흠 이것도 시간초과...?
 * -> check 하는 부분이 오래 걸리는 듯 싶다 ! 비트마스킹으로 해결..? -> 2^3000 ...? 불가능 ..
 * -> string 으로 해결해보자
 * -> 그래도 시간초과..
 * 로컬에서 3000개 데이터 만들어서 테스트해보니
 *  terminate called after throwing an instance of 'std::bad_alloc'
 *  what():  std::bad_alloc
 * 이런 에러가 떴다.
 * -> check 가 시간이 오래 걸린 게 아니라, 메모리를 더 이상 할당을 못해서 사실상 메모리 초관데 시간 초과가 난 듯??
 * -> check 방식을 바꾸자. 인접리스트처럼 각 포인트별로 해당하는 key 를 넣기로 !!
 * -> 메모리 초과는 안 나는데 시간초과
 * -> 조합 미리 구해놓고, 카운트 나중에 하는 방식으로 수정!
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    vector<pi> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // 조합 리스트 저장
    vector<ppi> sum_points;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x = points[i].first + points[j].first;
            int y = points[i].second + points[j].second;
            sum_points.push_back({{x, y},
                                  {i, j}});
        }
    }

    // 정렬
    sort(sum_points.begin(), sum_points.end());

    // 카운트
    int curr_x = sum_points[0].first.first, curr_y = sum_points[0].first.second;
    int curr_answer = (sum_points[0].second.first == sum_points[0].second.second ? 1 : 2);
    int answer = curr_answer;
    vector<bool> check(n, false); // 체크 배열
    check[sum_points[0].second.first] = check[sum_points[0].second.second] = true;
    for (int i = 1; i < sum_points.size(); i++) {
        int new_x = sum_points[i].first.first;
        int new_y = sum_points[i].first.second;
        int new_p1 = sum_points[i].second.first;
        int new_p2 = sum_points[i].second.second;

        if (curr_x == new_x && curr_y == new_y) {
            // 아직 같은 포인트
            if (!check[new_p1]) {
                check[new_p1] = true;
                curr_answer++;
            }
            if (!check[new_p2]) {
                check[new_p2] = true;
                curr_answer++;
            }
        } else {
            check.assign(n, false);
            check[new_p1] = check[new_p2] = true;
            curr_answer = (new_p1 == new_p2 ? 1 : 2);
            curr_x = new_x;
            curr_y = new_y;
        }

        answer = max(answer, curr_answer);
    }

    cout << answer;

    return 0;
}