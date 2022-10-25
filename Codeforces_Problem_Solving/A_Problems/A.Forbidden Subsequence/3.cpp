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
    string s;
    cin>>s;
    string t;
    cin>>t;
    sort(s.begin(),s.end());
    string ss = "";
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1]){
            ss += s[i];
        }
    }
    ss += s[s.length()-1];
    // cout<<ss<<'\n';
    string ans="";
    ll c=0;
    if(ss[0]!=t[0] || ss[1]!=t[1] || ss[2]!=t[2]){
        cout<<s<<'\n';
        return;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]==t[0]){
            ans = ans + s[i];
            c++;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]==t[2]){
            ans = ans + s[i];
            c++;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]==t[1]){
            ans = ans + s[i];
            c++;
        }
    }
    for(int i=c;i<s.length();i++){
        ans += s[i];
    }
    cout<<ans<<'\n';
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