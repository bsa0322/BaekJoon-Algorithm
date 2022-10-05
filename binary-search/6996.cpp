#include<iostream>
#include<string>
using namespace std;
int main0()
{
	string a, b;
	bool ans = true;
	int t;
	int letter[30] = { 0, };
	cin >> t;
	while (t--)
	{
		ans = true;
		cin >> a >> b;
		for (int i = 0; i < a.length(); i++)
		{
			letter[a[i] - 97]++;
		}
		for (int i = 0; i < b.length(); i++)
		{
			letter[b[i] - 97]--;
		}
		for (int i = 0; i < 26; i++)
		{
			if (letter[i] != 0) ans = false;
			letter[i] = 0;
		}
		if (ans)
		{
			cout << a << " & " << b << " are anagrams.\n";
		}
		else
		{
			cout << a << " & " << b << " are NOT anagrams.\n";
		}
	}
	return 0;
}