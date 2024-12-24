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
    if(a>b) swap(a,b);
    vector<int>c(n);
    set<int>s;
    for(int i=0;i<n;++i){
        cin>>c[i];
        s.insert(c[i]);
    }
    int len=s.size();
    while(len>0 and s.size()>1){
        int first=*(s.begin());
        s.erase(s.begin());
        int second=*(s.begin());
        int last=*(prev(s.end()));
        int diff=last-first;
        int mult=diff/b;
        int close=last-(mult*b + first);
        int add=first;
        int val=mult*b + first;
        int t=1;
        while(t<10){
            int val1=first+t*b;

            t+=1;
        }
        len-=1;
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


