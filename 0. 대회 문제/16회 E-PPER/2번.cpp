#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int k;
	int numbers[50]={0,};
	vector <string> ans;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>numbers[i];
		if(numbers[i]==6 || numbers[i]==28 || numbers[i]==496 || numbers[i]==8128)
		{
			ans.push_back("YES");
		}
		else ans.push_back("NO");
	}
	for(int i=0;i<k;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
