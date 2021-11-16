#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
    return a.first>b.first;
}
int main()
{
    int i,v,w,d,n,k,m,p=0;
    vector<pair<int,pair<int,int>>> ve;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>v>>w;
        d=v/w;
        ve.push_back(make_pair(d,make_pair(v,w)));
    }
    cin>>k;
    sort(ve.begin(),ve.end(),compare);
    for(i=0;i<n && k>0;i++)
    {
        if(k>ve[i].second.second)
        {
            m=ve[i].second.second;
        }
        else
        {
            m=k;
        }
        k=k-m;
        p=p+m*ve[i].first;
    }
    cout<<p;
    return 0;
}