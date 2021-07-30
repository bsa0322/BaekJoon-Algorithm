//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ci;
vector <ci> v;
int s[1001];
int e[1001];
int answer;
int main() {
	int n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
		v.push_back(ci(e[i],s[i]));
	}
	sort(v.begin(),v.end());
	cout<<v[0].first<<'\n';
	return 0;
}
