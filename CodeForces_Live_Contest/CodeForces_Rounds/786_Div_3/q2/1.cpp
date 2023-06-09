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
 
 
void convertnumbertobinary(int num){
    for (int i = 10;i >= 0;--i){
        cout << ((num >> i) & 1);
    }
    cout << endl;
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
    char c = 's[0]';
    char c1 = 's[1]';
    // string s1 = "abcdefghijklmnopqrstuvwxyz";
    int s1[26];
    // int sum=0;
    for(int i=0;i<26;i++){
        s1[i] =  i*26;
    }
    int t;
    for(int i=0;i<26;i++){
        if('s[0]'==s1[i]){
            t=s1[i];
            break;
        }
    }
    // string s2 = "abcdefghijklmnopqrstuvwxyz";
    int s2[26];
    for(int i=0;i<26;i++){
        s2[i] =  i;
    }
    int t1;
    for(int i=0;i<26;i++){
        if('s[1]'==s2[i]){
            t1=s2[i];
        }
    }
    cout<<t+t1<<endl;

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