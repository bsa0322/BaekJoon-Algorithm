#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef pair<int,int> cc; //나온횟수, 길이 
typedef pair<string,cc> ci;
struct cmp{
	bool operator()(ci x,ci y)
	{
		if(x.second.first > y.second.first) return 0;
		else if(x.second.first == y.second.first && x.second.second > y.second.second) return 0;
		else if(x.second.first == y.second.first && x.second.second == y.second.second && x.first < y.first) return 0;
		return 1;
	}
};
map <string,int> words;
string eng[100001];
priority_queue<ci, vector<ci>, cmp> pq;
int main()
{
	ci t;
	map<string, int>::iterator it;
	string word;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>word;
		if(word.length() >= m)
		{
			it = words.find(word);
			if(it != words.end())
			{
				words[word]++;
			}
			else words[word]=1;
		}
	}
	for(it=words.begin();it!=words.end();it++)
	{
		pq.push(ci((*it).first,cc((*it).second, (*it).first.length())));
	}
	while(!pq.empty())
	{
		t=pq.top();
		cout<<t.first<<'\n';
		pq.pop();
	}
	return 0;
}
