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
    ll a1,b1,n;
    cin>>a1>>b1>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    ll sum=0;
    if(n==1){
        if(a1>a[0] || b1>=b[0]){
            cout<<"YES"<<'\n';
            return;
        }else{
            cout<<"NO"<<'\n';
            return;
        }
    }
    for(ll i=0;i<n;i++){
        
        while(b[i]>0){
            if(b1<=0){
            cout<<"NO"<<'\n';
            return;
        }
            b1 -=a[i];
            b[i] -=a1;
        
        // cout<<b1<<'\n';
        // if((b1<=0 && i==(n-1) && a1>=a[i] && b[i]<=0)){
        //     cout<<"YES"<<'\n';
        //     return;
        // }
        // if((b1==0 && i==(n-1) && a1>=a[i])){
        //     cout<<"YES"<<'\n';
        //     return;
        // }
        
        }
    }
    
    
    // cout<<b1<<'\n';
    cout<<"YES"<<'\n';
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