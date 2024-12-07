#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

// 세그먼트 트리에서 (left ~ right) 구간 합 구하기
ll getSubSum(int node, int start, int end, int &left, int &right, vector<ll> &tree) {
    if (start >= left && end <= right) {
        // 구간 모두 해당된다면
        return tree[node];
    }
    ll ans = 0;
    int mid = (start + end) / 2;
    if (left <= mid) {
        // 왼쪽 구간 탐색
        ans += getSubSum(node * 2, start, mid, left, right, tree);
    }
    if (right > mid) {
        // 오른쪽 구간 탐색
        ans += getSubSum(node * 2 + 1, mid + 1, end, left, right, tree);
    }
    return ans;
}

// update_diff = target_value - origin
void updateSegmentTree(int node, int start, int end, int &target, ll &update_diff, vector<ll> &tree) {
    tree[node] += update_diff; // 현재 구역에 차이 반영
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    if (target <= mid) {
        // 왼쪽 구역 탐색
        updateSegmentTree(node * 2, start, mid, target, update_diff, tree);
    } else {
        // 오른쪽 구역 탐색
        updateSegmentTree(node * 2 + 1, mid + 1, end, target, update_diff, tree);
    }
}

ll initSegmentTree(int node, int start, int end, vector<ll> &num, vector<ll> &tree) {
    if (start == end) {
        // 리프 노드
        return tree[node] = num[start];
    }
    int mid = (start + end) / 2;
    ll left = initSegmentTree(node * 2, start, mid, num, tree);
    ll right = initSegmentTree(node * 2 + 1, mid + 1, end, num, tree);
    return tree[node] = left + right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, a, b;
    ll c;

    cin >> n >> m >> k;
    vector<ll> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // 세그먼트 트리 구성
    int h = ceil(log2(n)); // 트리 높이
    int size = (1 << (h + 1)) - 1; // 노드 개수
    vector<ll> tree(size + 1, 0); // 1 번 부터 시작
    initSegmentTree(1, 0, n - 1, num, tree);

    // 출력
    int mk = m + k;
    while (mk--) {
        cin >> a >> b >> c;
        if (a == 1) {
            // b번째 수 c로 바꾸기
            int target = b - 1;
            ll update_diff = c - num[target];
            num[target] = c;
            updateSegmentTree(1, 0, n - 1, target, update_diff, tree);
        } else {
            // b ~ c 구간 합 출력
            int left = b - 1;
            int right = c - 1;
            cout << getSubSum(1, 0, n - 1, left, right, tree) << '\n';
        }
    }
    return 0;
}