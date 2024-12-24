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
    n*=2;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt1=count(a.begin(),a.end(),1);
    int cnt0=count(a.begin(),a.end(),0);
    int mn=cnt1%2;
    int mx=0;
    if(cnt1<=n/2) mx=cnt1;
    else{
        int rem=cnt1-n/2;
        mx=n/2;
        mx-=rem;
    }
    cout<<mn<<" "<<mx<<endl;
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


