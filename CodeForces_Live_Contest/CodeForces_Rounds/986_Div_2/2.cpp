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
    int n,b,c;
    cin>>n>>b>>c;
    // cout<<(long double)b*(long double)c<<endl;
    if(b==0 and c==0){
        if(n==1){
            cout<<0<<endl;
        }
        else if(n==2){
            cout<<1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    else if(b==0 and c>0){
        if(n-2<=c){
            if(c>=n){
                cout<<n<<endl;
            }
            else{
                cout<<n-1<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
    }
    else{
        int low=-1;
        int high=n+1;
        while(high-low>1){
            int mid=(high+low)/2;
            // cout<<b<<" "<<c<<" ";
            double val=(double)mid*(double)b+c;
            // cout<<mid<<" "<<low<<" "<<high<<" "<<val<<endl;
            if(val<n){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        // cout<<(int)low<<" ";
        // if(low<0) low=0;
        low+=1;
        cout<<(int)(n-low)<<endl;
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


