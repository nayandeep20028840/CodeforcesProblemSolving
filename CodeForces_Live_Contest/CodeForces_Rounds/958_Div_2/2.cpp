#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long

bool solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    string s="";
    int zero=0;
    for(int i=0;i<n;++i){
        if(str[i]=='0') {
            zero+=1;
        }
        else{
            if(zero>0) s.push_back('0');
            s.push_back(str[i]);
            zero=0;
        }
    }
    if(zero>0) s.push_back('0');
    int cnt0=count(s.begin(),s.end(),'0');
    int cnt1=count(s.begin(),s.end(),'1');
    if(cnt1>cnt0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        if (solve()){
            
        }else{
            
        }
    }
    return 0;
}


