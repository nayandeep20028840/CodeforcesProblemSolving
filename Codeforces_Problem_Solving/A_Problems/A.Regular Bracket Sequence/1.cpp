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
    string s;
    cin>>s;
    ll n = s.length();
    ll sum = 0;
    ll count = 0;
    if(n%2==1 || s[n-1]=='('){
        cout<<"NO"<<'\n';
        return;
    }
    for(ll i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='?'){
            sum += 1;
        }
        else if(s[i]==')'){
            sum += -1;
        }
        if(sum<0){
            cout<<"NO"<<'\n';
            return;
        }
        if(s[i]=='?'){
            count++;
        }
    }
    ll sum2 = 0;
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='('){
            sum2 += 1;
        }
        else if(s[i]==')' || s[i]=='?'){
            sum2 += -1;
        }
        if(sum2>0){
            cout<<"NO"<<'\n';
            return;
        }
        if(s[i]=='?'){
            count++;
        }
    }
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