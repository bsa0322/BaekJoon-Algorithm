#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

int sum(string a)
{
	int digit_sum = 0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>=48 && a[i]<=57) digit_sum += (a[i]-'0');	
	}	
	return digit_sum;
}

bool cmp(string a,string b)
{
	if(a.length() != b.length()) return a.length() < b.length();
	else
	{
		int a_sum = sum(a);
		int b_sum = sum(b);
		if(a_sum != b_sum) return a_sum < b_sum;
		else return a < b;
	}
	 
}

int main()
{
	int n; //기타 개수
	cin>>n;
	vector <string> sirial(n);
	for(int i=0;i<n;i++)
	{
		cin>>sirial[i];
	}
	sort(sirial.begin(),sirial.end(),cmp);
	for(int i=0;i<n;i++)
	{
		cout<<sirial[i]<<'\n';
	}
	return 0;
}
