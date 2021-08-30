#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> ci;

int cntEmploy(int n, vector <ci> rank)
{
    //서류심사가 1등인 0번 인덱스 사람은 무조건 합격이므로 1번 인덱스부터 검사
    //다음 인덱스 사람은 우선 서류심사는 아래 사람들보다 무조건 위
    //따라서 그 전 사람들보다 면접심사가 높으면 합격
    int ans=1, mx=rank[0].second;
    for(int i=1;i<n;i++)
    {
        //전 사람 중 가장 순위 높은 값보다 높을 경우 합격
        if(mx > rank[i].second)
        {
            //가장 높은 면접심사 계속 갱신해서 반복문 1회만 돌림
            mx=rank[i].second;
            ans++;
        }
    }
    return ans;
}

int main()
{
    int t, n, ans;
    vector <ci> rank;

    //입력
    cin>>t;
    while(t--)
    {
        cin>>n;
        rank.assign(n, ci(0,0));
        for(int i = 0; i < n; i++)
            cin>>rank[i].first>>rank[i].second;

        //연산
        //first값인 서류심사 순위 기준으로 정렬
        //왼쪽 오름차순 정렬이므로 cmp함수 필요 없음
        sort(rank.begin(),rank.end());
        ans = cntEmploy(n, rank);

        //출력
        cout<<ans<<'\n';
    }
    return 0;
}
