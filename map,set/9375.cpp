#include <iostream>
#include <map>
using namespace std;

int main()
{
    string name, clothe;
    int t, n, ans=1;
    cin>>t;
    while(t--)
    {
        ans = 1;
        cin>>n;
        map <string,int> mp;
        while(n--)
        {
            cin>>name>>clothe;
            mp[clothe]++;
        }
        map<string,int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); iter++)
        {
            ans *= (iter->second+1);
        }
        ans -= 1;
        cout<<ans<<'\n';
    }
    return 0;
}
