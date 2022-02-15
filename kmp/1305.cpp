//전광판에는 같은 내용의 문구가 무한 반복
//전광판에 한번에 보이는 최대 문자수 L
//시간이 1초 지날 때마다 문자는 한 칸씩 옆으로 이동
//가능한 광고의 길이 중 가장 짧은 것
#include <iostream>
#include <vector>

using namespace std;

//접두사=접미사 가장 긴 길이를 문자열 전체 길이에서 뺀다
//예외: abaabab 정답: 5
//문자열 전체 길이에서 마지막 인덱스 pi값을 뺀다
int solution(int l, vector<char> &adv) {
    vector<int> pi(l, 0);
    int pre = 0;
    for (int i = 1; i < l; i++) { //i = 접미사
        while (pre > 0 && adv[pre] != adv[i]) {
            pre = pi[pre - 1];
        }
        if (adv[pre] == adv[i]) {
            pi[i] = ++pre;
        }
        //cout << pi[i] << ' ';
    }
    //cout << '\n';
    return l - pi[l - 1];
}

int main() {
    int l;

    //입력
    cin >> l;
    vector<char> adv(l);
    for (int i = 0; i < l; i++)
        cin >> adv[i];
    //연산 & 출력
    cout << solution(l, adv);
    return 0;
}