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
    string t;
    cin>>t;
    for(int i=0;i<n;++i){
        if(s[i]=='0' and t[i]=='1'){
            cout<<"NO"<<endl;
            return true;
        }
        else if(s[i]==t[i] and s[i]=='0'){

        }
        else{
            cout<<"YES"<<endl;
            return true;
        }
    }
    cout<<"YES"<<endl;
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


