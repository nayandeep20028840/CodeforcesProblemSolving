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
    int n,k;
    cin>>n>>k;
    int ans=0;
    int st=n;
    if(k==0){
        cout<<0<<endl;
        return true;
    }
    k-=st;
    ans+=1;
    st-=1;
    while(k>0){
        ans+=1;
        k-=st;
        if(k<=0) break;
        k-=st;
        ans+=1;
        st-=1;
    }
    cout<<ans<<endl;
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


