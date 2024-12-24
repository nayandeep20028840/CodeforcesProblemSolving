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
    int b,c,d;
    cin>>b>>c>>d;
    int ans=0;
    int tot=0;
    for(int i=61;i>=0;--i){
        if(((b>>i)&1)>0 and ((c>>i)&1)==0){
            ans|=(1ll<<i);
            tot|=(1ll<<i);
        }
    }
    for(int i=61;i>=0;--i){
        if(((b>>i)&1)>0 and ((c>>i)&1)==0){
            continue;
        }
        else if(((b>>i)&1)==0 and ((c>>i)&1)==0){
            if(ans+(1ll<<i)<=d){
                ans|=(1ll<<i);
                tot|=(1ll<<i);
            }
        }
        else if(((b>>i)&1) and ((c>>i)&1)){
            if(ans+(1ll<<i)<=d){
                ans|=(1ll<<i);
            }
            else{
                tot|=(1ll<<i);
            }
        }
    }
    if(ans==d){
        cout<<tot<<endl;
        return true;
    }
    cout<<-1<<endl;
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


