#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if(parent[x] == -1)
        return parent[x] = x-1;
    return parent[x] = find(parent[x]);
}

/**
 * 1 ~ g(i)번째 중 하나에 도킹하는 문제
 * -> 최대한 뒤쪽에 도킹하면 되는 것 아닌가...?
 * -> 78% 에서 시간초과 ㅋ
 *
 * 그럼 유니온 파인드를 사용해야만 풀리는 문제... 모르겠똬
 * find 활용해서 다음 도킹 위치 찾는 문제!!!
 *
 */

int main() {
    int g, p, input, ans = 0;

    //입력
    cin >> g >> p;
    parent.assign(g + 1, -1);
    while (p--) {
        cin >> input;
        if(find(input) == -1)
            break;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}