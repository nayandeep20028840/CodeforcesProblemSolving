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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(s=="27" || s=="237" || s=="273"){
        cout << 2 << '\n';
        cout << 27 << '\n';return;
    }
    else if(s=="57" || s=="537" || s=="573"){
        cout << 2 << '\n';
        cout << 57 << '\n';return;
    }
    for(ll i=0;i<n;i++){
        if(s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9' || s[i]=='1'){
            cout<<1<<'\n';
            cout<<s[i]<<'\n';
            return;
        }
    }
    ll m[10];
    for(ll i=0;i<=9;i++){
        m[i]=0;
    }
    for(ll i=0;i<n;i++){
        m[s[i]-'0']++;
    }
    if(m[2]>1){
        cout << 2 << '\n';
        cout << 22 << '\n';
    }
    else if(m[3]>1){
        cout << 2 << '\n';
        cout << 33 << '\n';
    }
    else if(m[5]>1){
        cout << 2 << '\n';
        cout << 55 << '\n';
    }
    else if(m[7]>1){
        cout << 2 << '\n';
        cout << 77 << '\n';
    }else{
        if(s[0]!='2' && m[2]>0){
            cout << 2 << '\n';
            cout << s[0] << 2 << '\n';
        }
        else if(s[0]!='5' && m[5]>0){
            cout << 2 << '\n';
            cout << s[0] << 5 << '\n';
        }
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