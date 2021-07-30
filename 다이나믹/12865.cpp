//배수아 c++ 12865 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
vector <ci> bak; //각각의 무게와 가치가 들어갈 벡터 
int table[100010]; //무게가 인덱스고 그 무게일 때 최대 가치가 들어갈 다이나믹 배열 
int main()
{
	ci t;
	int n,k,w,v,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>w>>v;
		bak.push_back(ci(w,v));
	}
	sort(bak.begin(),bak.end()); //무게 작은 것부터 정렬 
	for(int i=0;i<=k;i++) table[i] = -1; //그 무게만큼 만들지 못하는 경우도 있으므로 일단 -1로 초기화 
	table[0] = 0; //무게가 0인 경우는 가치도 0으로 초기화 
	for(int i=0;i<n;i++)
	{
		t = bak[i]; //i번째 물품 
		for(int j=k-1;j>=0;j--) //거꾸로 검사하는 이유는 중복되는 경우를  제거하기 위해 
		{
			//그 무게를 만드는 것이 일단 가능하고, 최대무게 k보다 작거나 같을경우 실행 
			if(table[j] >= 0 && j+t.first <= k) 
			{
				table[j+t.first] = max(table[j+t.first], table[j]+t.second); 
				//현재 j+t.first무게에서의 가치와 j무게의 가치에 i번째 물품의 가치를 더한 것 중 max값을 저장 
				ans = max(ans, table[j+t.first]);
				//ans 값 현재와 table[j+t.first] 중 큰거 저장 
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
