#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getSubMax(int node, int start, int end, int &left, int &right, vector<int> &tree) {
    if (start >= left && end <= right) {
        // 구간 모두 해당된다면
        return tree[node];
    }
    int ans = 0;
    int mid = (start + end) / 2;
    if (left <= mid) {
        // 왼쪽 구간 탐색
        ans = max(ans, getSubMax(node * 2, start, mid, left, right, tree));
    }
    if (right > mid) {
        // 오른쪽 구간 탐색
        ans = max(ans, getSubMax(node * 2 + 1, mid + 1, end, left, right, tree));
    }
    return ans;
}

int initSegmentTree(int node, int start, int end, vector<int> &num, vector<int> &tree) {
    if (start == end) {
        // 리프 노드
        return tree[node] = num[start];
    }
    int mid = (start + end) / 2;
    int left = initSegmentTree(node * 2, start, mid, num, tree);
    int right = initSegmentTree(node * 2 + 1, mid + 1, end, num, tree);
    return tree[node] = max(left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // 세그먼트 트리 구성
    int h = ceil(log2(n)); // 트리 높이
    int size = (1 << (h + 1)) - 1; // 노드 개수
    vector<int> tree(size + 1, 0); // 1 번 부터 시작
    initSegmentTree(1, 0, n - 1, num, tree);

    // 출력
    for (int i = 0; i < n - 2 * m + 2; i++) {
        int right = i + 2 * m - 2;
        cout << getSubMax(1, 0, n - 1, i, right, tree) << ' ';
    }
    return 0;
}