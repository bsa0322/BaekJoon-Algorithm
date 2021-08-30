#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<int, int> ci;

int main()
{
    int n, x;

    //입력
    cin >> n;

    vector <ci> v;
    vector <int> ans(n, 0); //좌표압축값 저장될 벡터
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(ci(x, i)); //first: 좌푯값, second: index 값, 나중에 정렬해서 순서가 바뀌므로 인덱스 값을 미리 저장
    }

    //연산
    sort(v.begin(), v.end()); //좌푯값 기준으로 오름차순 정렬
    for (int i = 1; i < n; i++)
    {
        if (v[i - 1].first == v[i].first) //전의 좌푯값과 현재의 좌푯값이 같다면
        {
            ans[v[i].second] = ans[v[i - 1].second]; //전 좌푯값의 좌표압축값을 현재 좌푯값의 좌표압축값에도 저장
        }
        else //전의 좌푯값과 현재의 좌푯값이 다르다면
        {
            ans[v[i].second] = ans[v[i - 1].second] + 1; //전 좌푯값의 좌표압축값 + 1
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}