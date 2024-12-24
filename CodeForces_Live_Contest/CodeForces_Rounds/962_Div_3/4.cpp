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
    int n,x;
    cin>>n>>x;
    int ans=0;
    for(int a=1;a<=x-2;a++){
        int bc = n + (a * a) - (a * x);
        int b=1;
        int tot=1;
        while(1 and bc>0){
            int ft=bc/b;
            int se=bc/ft;
            int dif=1;
            if(se>=b) dif=se-b+1;
            tot*=dif;
            tot*=ft;
            tot*=3;
            ans+=tot;
            if(ft==1) break;
            cout<<a+b<<" ";
            if((a+b)>=x) break;
            b+=1;
        }
    }
    cout<<ans<<endl;
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


