#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll init(vector<ll> &tree, ll node, ll st, ll ed, vector<ll> &target, int height) {
    if (st == ed) {
        return tree[node] = target[st];
    }
    //[st,ed/2] [ed/2+1,ed]구간의 합들을 현재 node에 저장
    if (node * 2 + 1 < height) {
        return tree[node] = init(tree, node * 2, st, (st + ed) / 2, target, height) +
                            init(tree, node * 2 + 1, (st + ed) / 2 + 1, ed, target, height);
    }
}

void change(vector<ll> &tree, ll node, ll st, ll ed, ll index, ll num, int height) {
    if (st > index || index > ed) { //index 포함 안할 경우 리턴
        return;
    }
    if(tree[node])
        tree[node] += num;
    if (node * 2 + 1 < height) {
        //왼쪽 구간
        change(tree, node * 2, st, (st + ed) / 2, index, num, height);
        //오른쪽 구간
        change(tree, node * 2 + 1, (st + ed) / 2 + 1, ed, index, num, height);
    }
}

ll sum(vector<ll> &tree, ll node, ll st, ll ed, ll l, ll r, int height) {
    if (st > r || ed < l)
        return 0;
    if (l <= st && r >= ed) {
        return tree[node];
    }
    if (node * 2 + 1 < height) {
        return sum(tree, node * 2, st, (st + ed) / 2, l, r, height) + sum(tree, node * 2 + 1, (st + ed) / 2 + 1, ed, l, r, height);
    }
}

int main() {
    int n, m, k;
    ll a, b, c;
    //입력
    cin >> n >> m >> k;
    int height = ceil(log2(n)) + 1; //세그먼트 트리 높이
    vector<ll> tree((1 << height) + 1, 0); //세그먼트 트리
    vector<ll> target(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> target[i];
    }
    //세그먼트 트리 초기화
    init(tree, 1, 0, n - 1, target, (1 << height));
//    for (int i = 1; i <= (1 << height); i++)
//        cout << tree[i] << ' ';
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) { //수 바꾸기
            change(tree, 1, 0, n - 1, b - 1, c - target[b - 1], (1 << height));
            target[b - 1] = c;
//            for (int i = 1; i <= (1 << height); i++)
//                cout << tree[i] << ' ';
//            cout<<"=====================\n";
        } else { //구간합
            cout << sum(tree, 1, 0, n - 1, b - 1, c - 1, (1 << height)) << '\n';
        }
    }
    return 0;
}