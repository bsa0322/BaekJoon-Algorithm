#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue <int> q;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    while(q.size() != 1)
    {
        if(!q.empty())
        {
            q.pop();
        }
        if(q.size() == 1) break;
        if(!q.empty())
        {
            int x = q.front();
            q.push(x);
            q.pop();
        }
    }
    cout<<q.front()<<'\n';
    return 0;
}