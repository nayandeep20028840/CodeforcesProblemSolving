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
    if(s[0]!=s[n-1]){
        cout<<"YES"<<endl;
        return true;
    }
    // int i=1;
    // while(i<n-1){
    //     if(s[i]!=s[0] and s[i]!=s[n-1]){
    //         cout<<"YES"<<endl;
    //         return true;
    //     }
    //     i+=1;
    // }
    cout<<"NO"<<endl;
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


