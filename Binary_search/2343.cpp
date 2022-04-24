//배수아 c++ 2343 
#include<iostream>
using namespace std;
long long int lesson[100010];
int main()
{
	long long int n,m,l=0,r=0,mid=0,cnt,sum,chk,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>lesson[i];
		r+=lesson[i];
	}
	//모든 레슨의 합을 오른쪽 값으로 이분탐색 시작
	//이분탐색이 될 값은 블루레이의 크기임 
	while(l <= r)
	{	
		mid = (l+r)/2; // 현재 블루레이의 크기 (l과r의 중간값) 
		chk=0; // 블루레이의 크기보다 한 레슨의 용량이 큰 경우 판단하기위한 체크변수 
		cnt=0; // 현재 블루레이로 만들어지는 그룹 수 카운트 변수 
		sum=0; // 그룹 수 나누기 위해 그룹 내 레슨 합 더할 변수 
		for(int i=0;i<n;i++)
		{
			if(lesson[i] > mid) 
			{
				chk = 1;
				break;
			}
			sum+=lesson[i];
			if(sum > mid)
			{
				sum = lesson[i];
				cnt++;
			}
		}
		if(sum <= mid) cnt++; 
		else cnt+=2;
		
		/*현재 블루레이로 만들어지는 그룹이 문제에서 요구하는 그룹(m)보다 크거나
		블루레이의 크기보다 한 레슨의 용량이 큰 경우 있을 시 블루레이의 크기를
		키워야 하므로 l을 증가*/  
		if(cnt > m || chk == 1) 
		{
			l = mid+1;
		} 
		
		/*현재 블루레이로 만들어지는 그룹이 m보다 작거나 같을 경우 
		블루레이의 크기를 줄여야 하므로 r을 감소*/ 
		else
		{
			r = mid-1;
			ans = mid; //m과 같은 경우도 포함되므로 ans값을 여기서 계속 저장 
		}
		
	}
	
	cout<<ans<<'\n';
	return 0;
}
