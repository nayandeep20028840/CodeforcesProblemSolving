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
int expo(int a, int b ) {int res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;} return res;}
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
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<int> v1(n);
    for(int i=0;i<n-1;++i){
        if(v[i]==v[i+1]){
            continue;
        }else{
            v1.pb(v[i]);
        }
    }
    v1.pb(v[n-1]);
    int count = 0;
    int ans = 0;
    if(v1[1]>v1[0]){
        ans = v1[0] + x;
    }else{
        ans = v1[0] - x;
    }
    for(int i=1;i<v1.size()-1;++i){
        if(abs(v1[i] - ans) <= x){
            continue;
        }else{
            if(v1[i+1]>v1[i]){
                ans = v1[i] + x;
            }else{
                ans = v1[i] - x;
            }
            count++;
        }
    }
    if(abs(v[n-1] - ans) > x){
        count++;
    }
    cout<<count<<'\n';
    return;
}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
    int t;
    cin >> t;  
    //int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        solve();
        //count++;
    }

    return 0;
}
 
 
 
 
 