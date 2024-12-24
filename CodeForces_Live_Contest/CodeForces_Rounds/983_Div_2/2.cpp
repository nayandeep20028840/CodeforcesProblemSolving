#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long

/*

1 2 3 4 5 6 7 8 9


*/

bool solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>ans;
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return true;
    }
    if(k==1 || k==n){
        cout<<-1<<endl;
        return true;
    }
    for(int i=2;i<n;++i){
        if(i==k){
            if(i%2==0){
                ans.push_back(1);
                ans.push_back(i);
                ans.push_back(i+1);
            }
            else{
                ans.push_back(1);
                ans.push_back(2);
                ans.push_back(i);
                ans.push_back(i+1);
                ans.push_back(i+2);
            }
            break;
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
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


