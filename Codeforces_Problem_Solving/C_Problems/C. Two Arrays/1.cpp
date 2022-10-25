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
    int n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> v1(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    if(n==1){
        if((v1[0]-v[0])>1 || (v[0]-v1[0])>0){
            cout<<"NO"<<endl;return;
        }else{
            cout<<"YES"<<endl;return;
        }
    }
    int c=0;
    int t=0;
    for(int i=0;i<n;i++){
        t = t + abs(v[i])-abs(v1[i]);
        if(abs(v[i]-v1[i])>1){
            c++;
        }
    }
    if(c>1 || t>0 || t<0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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