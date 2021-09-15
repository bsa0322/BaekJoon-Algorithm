#include <iostream>
#include <vector>

using namespace std;

int ans;

/**
 * [에너지 모으기 문제]
 * 구슬(x) 하나를 고름 (첫 번째와 마지막은 고를 수 없음)
 * x번째 에너지 구슬 제거
 * Wx-1 * Wx+1 의 에너지를 모음
 * N을 1 감소시키고, 다시 구슬을 1번부터 번호매김
 * 모을 수 있는 에너지의 양의 최댓값을 구하여라
 *
 * [풀이]
 * 우선 모든 경우의 수 고려
 * 가지치기 -> 안해도 될 것 같기도? 우선 안하고 해보자
 */

void f(int sum, vector<int> w, int num) {
    if(num != 0)
        w.erase(w.begin() + num);

    if (w.size() <= 3) { //에너지 구슬이 2개 이하 -> 더 이상 고를 수 없음
        //cout << "더 이상 못 골라 " << sum << '\n';
        ans = max(ans, sum);
        return;
    }
    for (int i = 2; i < w.size() - 1; i++) { //처음과 마지막 선택 불가이므로
        int s = w[i - 1] * w[i + 1];
        //cout << w[i] << ' ' << w[i - 1] << ' ' << w[i + 1] << ' ' << sum << ' ' << s << '\n';
        f(sum + s, w, i);
    }
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    //연산
    f(0, w, 0);

    //출력
    cout << ans << '\n';

    return 0;
}
