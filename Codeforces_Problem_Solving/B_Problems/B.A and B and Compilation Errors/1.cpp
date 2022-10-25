#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define int               long long
#define ld                long double
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.first<<" "<<i.second<<endl; } 
#define pb                push_back
#define popb              pop_back
#define pf                push_front
#define popf              pop_front
#define lb                lower_bound
#define ub                upper_bound
#define pii               pair<int,int>
#define bpp               __builtin_popcount
#define Pi                3.1415926535897932384626
 
int gcd(int a, int b) { if (b == 0) { return a; } return gcd(b, a % b); }
 
long long power(long long a, long long n){
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
bool checkpalindrome(int i){  // check palindrome number in n/2 time complexity
    string s=to_string(i);
    bool flag=0;
    int n=s.length();
    for (int i=0;i<n;i++){
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
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n-1);
    vector<int> c(n-2);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n-1;++i){
        cin>>b[i];
    }
    for(int i=0;i<n-2;++i){
        cin>>c[i];
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    int  ans = 0;
    for(int i=0;i<n-1;++i){
        if(a[i] != b[i]){
            ans++;
            cout<<a[i]<<'\n';
            break;
        }
    }
    if(ans == 0){
        cout<<a[n-1]<<'\n';
    }
    ans = 0;
    for(int i=0;i<n-1;++i){
        if(b[i] != c[i]){
            ans++;
            cout<<b[i]<<'\n';
            return;
        }
    }
    if(ans == 0){
        cout<<b[n-1]<<'\n';
        return;
    }
    return;
}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
    int t = 1;
    // cin >> t;  
    //int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        solve();
        //count++;
    }

    return 0;
}