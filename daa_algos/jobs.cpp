#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}
int main()
{
    int n,p,d,md=0,pro=0,i,j,count=0;
    vector<pair<int,int>> v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p>>d;
        v.push_back(make_pair(p,d));
        if(d>md)
        {
            md=d;
        }
    }
    sort(v.begin(),v.end(),compare);
    int arr[md];
    for(i=0;i<md;i++)
    {
        arr[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=v[i].second-1;j>=0;j--)
        {
            if(arr[j]==-1)
            {
                arr[j]=v[i].first;
                pro=pro+v[i].first;
                count++;
                break;
            }
        }
    }
    cout<<count<<" "<<pro;
    return 0;
}