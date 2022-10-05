//배수아 c++ 2470 
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long int liquid[100010];
int main()
{
	long long int n, l, r, sum, ans=10000000000, id1, id2;
	//ans값은 두 용액의 차이 중 0에 젤 가까운 것이 저장될 값으로 일단 맥시멈값으로 초기화 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>liquid[i];
	}
	sort(liquid,liquid+n); //용액 오름차순으로 정렬 
	l = 0; 
	r = n-1;
	//용액의 최솟값과 최대값부터 검사 
	while(l < r) //l이 r보다 작을동안만 실행 
	{
		sum = liquid[l] + liquid[r];
		if(abs(sum) < abs(ans)) //sum이 ans보다 0에 더 가까우면 ans 갱신 
		{
			ans = sum;
			id1 = l; //출력하기 위해 index 저장 
			id2 = r; //출력하기 위해 index 저장 
		}
		
		if(sum < 0) l++; //sum이 0보다 작다면 0에 더 가깝도록 sum이 커져야 하므로 l을 증가 
		else r--; //sum이 0보다 크거나같다면 0에 더 가깝도록 sum이 작아져야 하므로 r을 감소 
	}
	cout<<liquid[id1]<<' '<<liquid[id2]<<'\n';
	return 0;
}
