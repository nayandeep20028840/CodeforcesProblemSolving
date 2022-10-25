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
    ll n = s.length();
    string ss = "";
    for(ll i=n-1;i>0;i--){
        if((s[i] == '1' && s[i-1] == '9') || (s[i] == '9' && s[i-1] == '1')){
            // ll t = (s[i] - '0') + (s[i-1] - '0');
            // cout<<t<<'\n';
            if(n==2)
            s.clear();
            else
            s.erase(i-2,i);
            // s.erase(i-1,i);
            // cout<<s<<'\n';
            // ll t = 10;
            string sss = "10";
            // cout<<sss<<'\n';
            s.insert(i-1, sss);
            cout<<s<<'\n';
            // cout<<0<<'\n';
            return;
        }
        if((s[i] - '0') + (s[i-1] - '0') > 9){
            ll t = (s[i] - '0') + (s[i-1] - '0');
            // cout<<t<<'\n';
            s.erase(i-1,i+1);
            // s.erase(i-1,i);
            // cout<<s<<'\n';
            string sss = to_string(t);
            // cout<<sss<<'\n';
            s.insert(i-1, sss , 0 , 2);
            cout<<s<<'\n';
            return;
        }
    }
    for(ll i=0;i<2;i++){
        ll t = (s[0] - '0') + (s[1] - '0');
        // cout<<t<<'\n';
        // s.erase(0,1);
        s.erase(0,2);
        // cout<<s<<'\n';
        string sss = to_string(t);
        // cout<<sss<<'\n';
        s.insert(0, sss);
        cout<<s<<'\n';
        return;
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