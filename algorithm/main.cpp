#include<iostream>
using namespace std;
int table[1000010];
int main()
{
    int n, mn;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        mn = 100000000;
        if (i % 3 == 0)
        {
            if (mn > table[i / 3]) mn = table[i / 3];
        }
        if (i % 2 == 0)
        {
            if (mn > table[i / 2]) mn = table[i / 2];
        }
        if (mn > table[i - 1]) mn = table[i - 1];
        table[i] = mn + 1;
    }
    cout << table[n] << '\n';
    return 0;
}