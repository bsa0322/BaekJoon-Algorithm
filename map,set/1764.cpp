#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <string> s, ans;
    string name;
    int n, m;
    cin>>n>>m;
    while(n--)
    {
        cin>>name;
        s.insert(name);
    }
    while(m--)
    {
        cin>>name;
        if(s.find(name) != s.end())
        {
            ans.insert(name);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto iter=ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << '\n';
    }
    return 0;
}