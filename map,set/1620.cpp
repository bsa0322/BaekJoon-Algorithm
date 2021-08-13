#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, int> pocket;
string pockets[100001];
int main()
{
	cin.tie(0);
	string pocketmon;
	int n,m,num;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>pocketmon;
		pocket.insert(make_pair(pocketmon,i));
		pockets[i]=pocketmon;
	}
	for(int i=0;i<m;i++)
	{
		cin>>pocketmon;
		//포켓몬 이름으로 입력 
		if(pocketmon[0] >= 60 && pocketmon[0] <= 90)
		{
			map<string,int>::iterator iter = pocket.find(pocketmon);
			cout<<iter->second<<'\n';
		}		
		//숫자 입력
		else
		{
			num = stoi(pocketmon);	
			pocketmon = pockets[num];
			cout<<pocketmon<<'\n';
		} 
	}	
	return 0;
}
