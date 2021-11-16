#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int i,j,s,e,n;
    vector<pair<int,int>> v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s>>e;
        v.push_back(make_pair(e,s));
    }
    sort(v.begin(),v.end());
    int ce=-1,count=0;
    for(i=0;i<n;i++)
    {
        if(ce<v[i].second)
        {
            ce=v[i].first;
            count++;
        }
    }
    cout<<count;
    return 0;
}