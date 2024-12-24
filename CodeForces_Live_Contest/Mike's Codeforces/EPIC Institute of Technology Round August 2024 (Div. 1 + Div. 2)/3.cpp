#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long

bool solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>p;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int f=0;
    int mult1 = (x1-x2)*(x1-x2);
    int mult2 = (y1-y2)*(y1-y2);
    long double dist = sqrtl(mult1+mult2);
    // cout<<dist<<" ";
    for(int i=0;i<n;++i){
        mult1 = (p[i].first-x2)*(p[i].first-x2);
        mult2 = (p[i].second-y2)*(p[i].second-y2);
        long double cal = sqrtl(mult1+mult2);
        // cout<<cal<<" ";
        if(dist>=cal){
            f=1;
            break;
        }
    }
    // cout<<endl;
    if(f) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
        {
            
        }
        else
        {
            
        }
    }
    return 0;
}


