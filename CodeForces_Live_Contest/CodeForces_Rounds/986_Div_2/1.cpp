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
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int times=1000;
    int i=0;
    int aa=a;
    int bb=b;
    a=0;
    b=0;
    while(times>0){
        if(s[i]=='N'){
            b+=1;
        }
        else if(s[i]=='E'){
            a+=1;
        }
        else if(s[i]=='S'){
            b-=1;
        }
        else if(s[i]=='W'){
            a-=1;
        }
        i+=1;
        i%=n;
        times-=1;
        if(a==aa && b==bb){
            cout<<"YES"<<endl;
            return true;
        }
    }
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


