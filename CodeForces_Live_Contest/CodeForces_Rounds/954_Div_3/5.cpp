#include<bits/stdc++.h> 
using namespace std; 

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long>a(n);
        for(long long i=0;i<n;++i){
            cin>>a[i];
        }
        map<long long,vector<long long>>mp;
        for(long long i=0;i<n;++i){
            long long mod=a[i]%k;
            mp[mod].push_back(a[i]);
        }
        long long cnt=0;
        for(auto it:mp){
            if(it.second.size()%2) cnt+=1;
        }
        long long ans=0;
        if((cnt>0 and n%2==0) || cnt>1){
            cout<<-1<<endl;
            continue;
        }
        for(auto it : mp){
            vector<long long> v=it.second;
            long long len=v.size();
            sort(v.begin(),v.end());
            // cout<<len<<" ";
            vector<vector<long long>>dp(len+1,vector<long long>(3,-1));
            function<long long(long long,long long)> rec=[&](long long idx,long long taken)->long long{
                if(idx>=len) return 0;
                if(dp[idx][taken]!=-1) return dp[idx][taken];
                long long ans=0;
                if(taken==0){
                    if(idx+1<len)
                        ans+=min(rec(idx+1,1),v[idx+1]-v[idx]+rec(idx+2,taken));
                    else
                        ans+=rec(idx+1,1);
                }
                else{
                    if(idx+1<len)
                        ans+=v[idx+1]-v[idx]+rec(idx+2,1);
                    else 
                        ans+=0;
                }
                return dp[idx][taken]=ans;
            };
            if(len%2) {
                if(len!=1) ans+=rec(0,0);
            }
            else ans+=rec(0,1);
        }
        cout<<ans/k<<endl;
    }
    return 0;
}


