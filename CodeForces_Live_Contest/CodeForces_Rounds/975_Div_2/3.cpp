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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.rbegin(),a.rend());
    int kk=k;
    int extra=0;
    int mx=a[0];
    int idx=n;
    for(int i=1;i<n;++i){
        int need=mx-a[i];
        if(need<=k){
            k-=need;
            extra+=need;
        }
        else{
            idx=i;
            break;
        }
    }
    if(idx==n){
        cout<<n<<endl;
        return true;
    }
    int sum=0;
    for(int i=idx;i<n;++i){
        sum+=a[i];
    }
    int mult=sum/mx;
    sum%=mx;
    if(extra>=sum){
        cout<<idx+mult<<endl;
        return true;
    }
    k=kk;
    int tot=accumulate(a.begin(),a.end(),0ll);
    // for(int i=0;i<n;++i){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // cout<<tot<<endl;
    tot-=a[0];
    // cout<<k<<" "<<tot<<endl;
    for(int i=n-1;i>=1;--i){
        int want=i*mx;
        int have=tot;
        int need=want-have;
        if(have>want){
            have+=a[0];
            for(int j=n-1;j>=1;--j){
                int left=j-have%j;
                if((have+k)/j<mx) continue;
                if(left<=k){
                    cout<<j<<endl;
                    return true;
                }
            }
            cout<<1<<endl;
            return true;
        }
        else if(need<=k){
            have+=a[0];
            for(int j=n-1;j>=1;--j){
                int left=j-have%j;
                if((have+k)/j<mx) continue;
                if(left<=k){
                    cout<<max(i+1,j)<<endl;
                    return true;
                }
            }
            cout<<i+1<<endl;
            return true;
        }
    }
    cout<<1<<endl;
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


