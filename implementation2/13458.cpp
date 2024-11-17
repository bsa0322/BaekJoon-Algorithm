#include<iostream>
using namespace std;
long long int num[1000000];
int main()
{
    int n,i,j;
    long long int answer,b,c;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cin>>b>>c;
    //총감독관 우선 한 시험장마다 무조건 배치
    for(i=0;i<n;i++)
    {
        num[i]=num[i]-b;
    }
    answer=n;
    //부감독관 배치
    for(i=0;i<n;i++)
    {
        if(num[i] <= 0) continue;
        if(num[i]%c==0)
        {
            answer+=(num[i]/c);
        }
        else
        {
            answer+=(num[i]/c+1);
        }
    }
    cout<<answer<<'\n';
    return 0;
}