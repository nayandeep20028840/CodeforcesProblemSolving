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
    string s;
    cin>>s;
    string r;
    cin>>r;
    int cnt_s_0=0;
    int cnt_s_1=0;
    for(int i=0;i<n;++i){
        if(s[i]=='0'){
            cnt_s_0++;
        }
        else{
            cnt_s_1++;
        }
    }
    int i=0;
    // cout<<cnt_s_0<<" "<<cnt_s_1<<endl;
    while(cnt_s_1>0 and cnt_s_0>0 and i<n-1){
        if(r[i]=='0'){
            cnt_s_1-=1;
        }
        else{
            cnt_s_0-=1;
        }
        i++;
    }
    // cout<<cnt_s_0<<" "<<cnt_s_1<<endl;
    if(cnt_s_1>1 || cnt_s_0>1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
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


