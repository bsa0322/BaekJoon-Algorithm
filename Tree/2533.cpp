//
// Created by BaeSuA on 2022-11-20.
//

/**
 * 얼리 아답터가 아닌 사람들은 자신의 모든 친구가 얼리 아답터일 때만 아이디어 받아들임
 * 모든 두 정점 사이에 이들을 잇는 경로가 존재하면서 사이클이 존재하지 않는 경우 -> 트리!
 * 최소 얼리 아답터 수
 *
 * [해결 전략]
 * 정점이 가장 많이 연결된 정점..??
 * 얼리어답터 o/x 인 경우 dp
 * dp에는 해당 정점을 루트로 가지는 서브 트리의 얼리어답터 개수 저장
 * - 해당 정점이 얼리 어답터가 아니라면 ? 자식 노드는 무조건 얼리어답터여야 함
 * - 해당 정점이 얼리 어답터라면? 자식 노드가 얼리어답터 o/x 인 경우 중 더 작은 값 저장
*/

/**
 * dp에는 해당 정점을 루트로 가지는 서브 트리의 얼리어답터 최소 개수 저장
 * dp[x][0] : x 정점이 얼리어답터가 아닐 때
 * dp[x][1] : x 정점이 얼리어답터 일 때
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<vector<int>> dp;

pair<int, int> solution(int node) {
    if (dp[node][0] != -1) {
        return {dp[node][0], dp[node][1]};
    }

    dp[node][0] = 0;
    dp[node][1] = 1;
    for (int i = 0; i < tree[node].size(); i++) {
        if (dp[tree[node][i]][0] != -1) {
            continue;
        }
        pair<int, int> temp = solution(tree[node][i]);
        dp[node][0] += temp.second;
        dp[node][1] += min(temp.first, temp.second);
    }
    return {dp[node][0], dp[node][1]};
}


int main() {
    int n, u, v;

    cin >> n;
    tree.assign(n + 1, vector<int>(0));
    dp.assign(n + 1, vector<int>(2, -1));
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    pair<int, int> ans = solution(1);
    cout << min(ans.first, ans.second);

    return 0;
}