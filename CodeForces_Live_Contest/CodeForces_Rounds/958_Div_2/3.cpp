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
    vector<int>bit(63,0);
    int cnt=0;
    for(int i=0;i<63;++i){
        if((n&(1ll<<i))){
            bit[i]=1;
            cnt+=1;
        }
    }
    if(cnt==1){
        cout<<1<<endl;
        cout<<n<<endl;
        return true;
    }
    vector<int>ans(cnt+1,n);
    int last=0;
    int one=0;
    int idx=-1;
    for(int i=62;i>=0;--i){
        if((n&(1ll<<i)) and one==1){
            last = (1ll<<i);
            idx=i;
            break;
        }
        else if((n&(1ll<<i)) and one==0){
            one=1;
        }
    }
    ans[0]=last;
    ans[1]=(n^last);
    int j=2;
    for(int i=idx-1;i>=0;--i){
        if((n&(1ll<<i))){
            ans[j]=(n^(1ll<<i));
            j+=1;
        }
    }
    cout<<cnt+1<<endl;
    for(int i=0;i<=cnt;++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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


