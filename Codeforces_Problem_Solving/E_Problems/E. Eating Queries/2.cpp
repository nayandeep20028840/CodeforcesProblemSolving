#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define ll                long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define lb                lower_bound
#define ub                upper_bound
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define bpp               __builtin_popcount
#define Pi                3.1415926535897932384626
 
 
void convertnumbertobinary(int num){
    for (int i = 10;i >= 0;--i){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
 
bool checkpalindrome(ll i){  // check palindrome number in n/2 time complexity
    string s=to_string(i);
    bool flag=0;
    int n=s.length();
    for (ll i=0;i<n;i++){
        if (s[i]!=s[n-1-i]){
            flag=1;
            break;
        }
    }
    if(flag){
        return 0;
    }else{
        return 1;
    }
}

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    ll sum=0;
    vector<ll> v2;
    for(ll i=0;i<n;i++){
        sum+=v[i];
        v2.pb(sum);
    }
    // for(auto i : v2){
    //     cout<<i<<" ";
    // }
    // cout<<'\n';
    vector<ll> v3(q);
    for(ll i=0;i<q;i++){
        cin>>v3[i];
        int ans = lower_bound(v2.begin(), v2.end(), v3[i]) - v2.begin() + 1;
        if(ans>n){
            ans = -1;
        }
        cout<<ans<<'\n';
    }
    // for(auto i : v3){
    //     cout<<i<<" ";
    // 
    // cout<<'\n';
    // ll c=0;
    // for(ll i=0;i<q;i++){
    //     for(ll j=0;j<n;j++){
    //         if(v2[j]>=v3[i]){
    //             c++;
    //             cout<<(j+1)<<'\n';
    //             break;
    //             // i++;
    //         }
    //     }
    //     if(c==0)
    //     cout<<-1<<'\n';
    //     c=0;
        // i++;
    // }
    return;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
    int t;
    cin >> t;  // long long int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        solve();
        //count++;
    }

    return 0;
}