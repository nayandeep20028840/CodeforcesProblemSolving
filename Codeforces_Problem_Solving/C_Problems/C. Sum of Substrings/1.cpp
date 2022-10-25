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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    // for(int i=n-1;i>=(n-k);){
    //     if(s[i]=='0'){
    //         s.erase(i,1);
    //         // s.clear();
    //         i--;
    //     }else{
            
    //     }
    // }
    for(int i=n-1;i>(n-k);i--){
        if(s[i]=='0' && s[i-1]=='1'){
            swap(s[i],s[i-1]);
        }
    }
    int sum=0;
    string s1="";
    // vector<int> v;
    for(int i=0;i<n-1;i++){
        s1 = s1 + s[i];
        s1 = s1 + s[i+1];
        sum = sum + stoi(s1);
        s1.clear();
    }
    cout<<sum<<endl;
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