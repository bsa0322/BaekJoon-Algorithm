#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(string p) {
    int m = p.length(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) { //i: 접미사(뒷부분), j: 접두사(앞부분)
        while (j > 0 && p[i] != p[j]) //서로 다르면 j - 1의 pi값만큼 당겨서 가져온다
            j = pi[j - 1];
        if (p[i] == p[j]) //앞부분과 뒷부분이 계속 같으면 j와 i동시에 뒤로 땡기고 pi는 증가 (접미사 = 접두사이기 때문에 j개수로 저장)
            pi[i] = ++j;
    }
    return pi;
}

bool kmp(string s, string p) {
    vector<int> ans;
    vector<int> pi = getPi(p); //pi구하는 함수 불러서 구하기
    int n = s.length(), m = p.length(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) //서로 다를 경우 접미사=접두사가 같은 부분만큼 건너뛰기
            j = pi[j - 1];
        if (s[i] == p[j]) { //같을 경우
            if (j == m - 1) //p 전체를 모두 비교 완료한 상태면 바로 true 리턴
                return true;
            j++; //아니라면 p의 인덱스 값인 j 증가
        }
    }
    return false;
}

int main() {
    string s, p;
    //입력 & 연산 & 출력
    cin >> s >> p;
    cout << kmp(s, p);
    return 0;
}