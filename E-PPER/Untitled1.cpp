//���α׷��ӽ������� main�Լ� �� ����¹��� �ʿ����� �ʽ��ϴ�. ��� solution�Լ��� �ۼ��ϸ� �˴ϴ�.
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
