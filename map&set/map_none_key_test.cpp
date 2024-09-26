#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	int a = m["no_key"];
	cout << a;
} 
