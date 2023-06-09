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
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    ll maxi=INT_MIN;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            // cin>>a[i][j];
            maxi=max(maxi,a[i][j]);
        }
    }
    // if(n>1 && m>1){
    //     if(n==m)
    //     cout<<(m-1)*(n-1)<<'\n';
    //     else
    //     cout<<(max(n,m)-1)*min(n,m)<<'\n';
    // }
    // else if(n==1 && m>1 ){
    //     cout<<n*(m-1)<<'\n';
    // }
    // else if(n>1 && m==1){
    //     cout<<(n-1)*m<<'\n';
    // }else{
    //     cout<<1<<'\n';
    // }
    // cout<<1<<'\n';
    ll t=0;
    ll t1 =0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(maxi==a[i][j]){
                // cout<<((i+1)*(j+1))<<'\n';
                // return;
                t = i;
                t1 = j;
            }
        }
    }
    if(t<n/2 && t1<m/2){
        cout<<((n-t)*(n-t1))<<'\n';
    }
    else if(t<n/2 && t1>=m/2){
        cout<<((n-t)*(t1+1))<<'\n';
    }
    else if(t>=n/2 && t1<m/2){
        cout<<((t+1)*(n-t1))<<'\n';
    }else{
        cout<<((t+1)*(t1+1))<<'\n';
    }
    // if(t<=(n+1)/2){
    //     t=n-t;
    // }
    // if(t1<=(n+1)/2){
    //     t1=n-t1;
    // }
    // cout<<(t*t1)<<'\n';
    // ll t2 = max(n-t,t+1);
    // ll t3 = max(m-t1,t1+1);
    // cout<<t2*t3<<'\n';
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