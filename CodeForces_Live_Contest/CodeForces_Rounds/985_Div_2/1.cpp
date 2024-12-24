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
    int l,r,k;
    cin>>l>>r>>k;
    if(k==1){
        cout<<r-l+1<<endl;
        return true;
    }
    int low=l-1;
    int high=r+1;
    while(high-low>1){
        int mid=(high+low)/2;
        if(mid*k<=r){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    cout<<low-l+1<<endl;
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


