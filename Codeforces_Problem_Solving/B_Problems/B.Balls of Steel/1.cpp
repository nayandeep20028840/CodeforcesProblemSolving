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
#define pii               pair<int,int>
#define bpp               __builtin_popcount
#define Pi                3.1415926535897932384626
 
 
long long power(long long int a, long long int n)
{
if (n == 0)return 1; if (n % 2 == 0) {long long val = power(a, n / 2); val = (val * val); return val;}
else {long long val = power(a, n / 2); val = ((val * val) * a) ; return val;}
}
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
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> p(n);
    for(ll i=0;i<n;i++){
        cin>>p[i].first;
        cin>>p[i].second;
    }
    sort(all(p));
    // if(n%2){
    //     ll mid = n/2;
    //     for(ll i=0;i<n;i++){
    //         for(ll j=0;j<n;j++){
    //             if((k*k)<((p[i].first - p[j].first)*(p[i].first - p[j].first) + (p[i].second - p[j].second)*(p[i].second - p[j].second))){
    //                 cout<<-1<<'\n';
    //                 return;
    //             }
    //         }
    //     }
    //     cout<<1<<'\n';
    // }
    // else{
        ll mid = n/2;
        ll count = 0;
        ll count1 = 0;
        ll mini = INT_MAX;
        ll mini2 = INT_MAX;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if((k)<(abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second))){
                    count++;
                }
            }
            mini = min(mini,count);
            count=0;
        }
        mid = mid - 1;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if((k)<(abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second))){
                    count1++;
                }
            }
            mini2 = min(mini2,count1);
            count1=0;
        }
        if(mini>0 && mini2>0){
            cout<<-1<<'\n';
        }else{
            cout<<1<<'\n';
        }
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