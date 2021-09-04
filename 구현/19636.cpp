#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
string ans;
int weight[10001];
int energyeat[10001];
int gicho[10001];
int A[10001];
int energysoby[10001];
int main()
{
    int T, d, e, a, i, j, dw, dg;
    cin >> weight[0] >> energyeat[0] >> T;
    gicho[0] = energyeat[0];
    energysoby[0] = gicho[0] + A[0];
    cin >> d >> e >> a;

    ans = "";
    for (i = 1;i <= d;i++)
    {
        energyeat[i] = e;
        A[i] = a;
        gicho[i] = gicho[i - 1];
        energysoby[i] = gicho[i] + A[i];
        dw = energyeat[i] - energysoby[i];
        weight[i] = weight[i - 1] + dw;

        if (weight[i] <= 0 || gicho[i] <= 0)
        {
            ans = "Danger Diet";
            cout << ans << '\n';
            break;
        }
    }
    if (ans == "")
    {
        cout << weight[d] << " " << gicho[d] << '\n';
    }

    ans = "";
    for (i = 1;i <= d;i++)
    {
        energyeat[i] = e;
        A[i] = a;
        gicho[i] = gicho[i-1];
        energysoby[i] = gicho[i] + A[i];
        dw = energyeat[i] - energysoby[i];
        weight[i] = weight[i - 1] + dw;

        if (abs(dw) > T)
        {
            if (dw < 0)
            {
                dw -= 1;
            }
            dg = dw / 2;
            gicho[i] += dg;
        }

        if (weight[i] <= 0 || gicho[i] <= 0)
        {
            ans = "Danger Diet";
            cout << ans << '\n';
            break;
        }
    }

    if (ans == "")
    {
        if (energyeat[0] - (gicho[d] + A[0]) > 0)
        {
            ans = "YOYO";
        }
        else ans = "NO";

        cout << weight[d] <<" "<< gicho[d] <<" "<< ans << '\n';
    }

    return 0;
}