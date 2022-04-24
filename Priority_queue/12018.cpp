#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    //freopen("input.txt","r",stdin);

    vector<int> v, result;

    int n, m, p, l, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p >> l;
        v.assign(p, 0);
        for (int i = 0; i < p; i++) {
            cin>>v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        if (v.size() < l) result.push_back(1);
        else result.push_back(v[l - 1]);
    }

    sort(result.begin(),result.end());

    for(int i=0;i< result.size();i++)
    {
        //cout<<result[i]<<'\n';
        m = m - result[i];
        if(m < 0) break;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
