#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define ll                long long
#define all(v)            v.begin(),v.end()
#define pb                push_back
#define popb              pop_back
#define pf                push_front
#define popf              pop_front
#define lb                lower_bound
#define ub                upper_bound
#define f                 first
#define s                 second
#define pii               pair<int,int>
#define bpp               __builtin_popcount
#define Pi                3.1415926535897932384626
 
 
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll t=0;
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='0'){
            t = i;
            break;
        }
    }
    ll m=0;
    ll one=0;
    ll count=0;
    ll k=0;
    vector<ll> v;
    for(ll i=0;i<t;i++){
        if(s[i]=='1'){
            one++;
            m=1;
        }
    }
    for(ll i=t;i>=0;i--){
        if(s[i]=='0' && one>0){
            v.pb(i+1);
            count++;
            one--;
            k++;
        }
        else if(s[i]=='1' && one>0){
            one--;
        }
    }
    for(ll i=0;i<t;i++){
        if(s[i]=='1' && count>0){
            v.pb(i+1);
            count--;
            k++;
        }
    }
    cout<<m<<'\n';
    sort(all(v));
    if(m>0){
        cout<<k<<" ";
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<'\n';
    }
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