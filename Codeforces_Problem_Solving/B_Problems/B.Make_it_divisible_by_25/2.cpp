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
    string s;
    cin>>s;
    ll n = s.length();
    ll t1=0;
    ll t2=1000000000;
    ll t4=0;
    ll t5=1000000000;
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='0'){
            t1=i;
            break;
        }
    }
    if(t1!=0){
    for(ll i=t1-1;i>=0;i--){
            if(s[i]=='5' || s[i]=='0'){
                t2 = t1 - i - 1;
                break;
            }
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='5'){
            t4=i;
            break;
        }
    }
    if(t4!=0){
    for(ll i=t4-1;i>=0;i--){
            if(s[i]=='2' || s[i]=='7'){
                t5 = t4 - i - 1;
                break;
            }
    }}
    ll ans = t2 + n - 1 - t1;
    ll ans1 = t5 + n - 1 -t4;
    cout<<min(ans,ans1)<<endl;
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