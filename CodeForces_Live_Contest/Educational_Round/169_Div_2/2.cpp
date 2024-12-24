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
    int l,r;
    cin>>l>>r;
    int L,R;
    cin>>L>>R;
    if(L<=l){
        int temp1=L;
        int temp2=R;
        L=l;
        R=r;
        l=temp1;
        r=temp2;
    }
    // cout<<l<<" "<<r<< " "<<L<<" "<<R<<endl;
    if(l<L){
        if(r<R and r>=L){
            cout<<r-L+2<<endl;
        }
        else if(r==R and r>=L){
            cout<<r-L+1<<endl;
        }
        else if(r<L){
            cout<<1<<endl;
        }
        else if(r>R){
            cout<<R-L+2<<endl;
        }
        else if(r==R){
            cout<<R-L+1<<endl;
        }
    }
    else if(l==L){
        if(r<R and r>=L){
            cout<<r-L+1<<endl;
        }
        else if(r==R and r>=L){
            cout<<r-L<<endl;
        }
        else if(r<L){
            cout<<1<<endl;
        }
        else if(r>R){
            cout<<R-L+1<<endl;
        }
        else if(r==R){
            cout<<R-L<<endl;
        }
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


