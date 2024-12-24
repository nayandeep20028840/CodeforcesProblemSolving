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
    int n,q;
    cin>>n>>q;
    string a;
    cin>>a;
    string b;
    cin>>b;
    vector<int>cnt1(26,0);
    vector<int>cnt2(26,0);
    vector<vector<int>>pf1(n);
    vector<vector<int>>pf2(n);
    for(int i=0;i<n;++i){
        cnt1[a[i]-'a']+=1;
        cnt2[b[i]-'a']+=1;
        pf1[i]=cnt1;
        pf2[i]=cnt2;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=0;
        l-=1;
        r-=1;
        if(l==0){
            for(int i=0;i<26;++i){
                if(pf1[r][i]>pf2[r][i]){
                    ans+=(pf1[r][i]-pf2[r][i]);
                }
            }
        }
        else{
            vector<int>ft(26,0);
            vector<int>se(26,0);
            for(int i=0;i<26;++i){
                ft[i]=pf1[r][i]-pf1[l-1][i];
                se[i]=pf2[r][i]-pf2[l-1][i];
            }
            for(int i=0;i<26;++i){
                if(ft[i]>se[i]){
                    ans+=(ft[i]-se[i]);
                }
            }
        }
        cout<<ans<<endl;
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


