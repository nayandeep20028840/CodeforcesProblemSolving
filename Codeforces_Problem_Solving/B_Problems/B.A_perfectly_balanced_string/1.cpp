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
    ll n=s.length();
    set<char> s1;
    for (ll i=0;i<n;i++){
        s1.insert(s[i]);
    }
    if (s1.size()==1){
        cout << "YES"<<endl;
        return;
    }
    for(ll i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    ll count[26]{};
    ll maxi=0;
    for(ll i=0;i<n;i++){
        count[s[i]-97]++;
        maxi = max(maxi,count[s[i]-97]);
    }
    for(ll i=0;i<n;i++){
        if(maxi-count[s[i]-97]>1){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(ll i=0;i<n;i++){
        if(s[i]==s[n-1-i]){
            if(count[s[i]-97]==2){
                //for(ll i=1;i<n-1;i++){
                    if(count[s[i-1]-97]==1){
                        cout<<"NO"<<endl;
                        return;
                    }
                //}
            }
        }
    }
    cout<<"YES"<<endl;
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