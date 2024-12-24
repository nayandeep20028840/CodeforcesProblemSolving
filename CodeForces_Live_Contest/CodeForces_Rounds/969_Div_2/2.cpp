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
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int mx=*max_element(a.begin(),a.end());
    for(int i=0;i<m;++i){
        char c;
        cin>>c;
        int l,r;
        cin>>l>>r;
        if(r>=mx and l<=mx){
            if(c=='-') mx-=1;
            else mx+=1;
        }
        cout<<mx<<" ";
    }
    cout<<endl;
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


