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
    vector<int>b(n-1);
    for(int i=0;i<n-1;++i){
        cin>>b[i];
    }
    vector<int>a(n);
    a[0]=b[0];
    for(int i=1;i<n-1;++i){
        a[i]=(b[i-1] | b[i]);
    }
    a[n-1]=b[n-2];
    int f=0;
    for(int i=0;i<n-1;++i){
        int val=(a[i]&a[i+1]);
        if(val!=b[i]){
            f=1;
            break;
        }
    }
    if(f){
        cout<<-1<<endl;
        return true;
    }
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
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


