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
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    ll c=0;
    ll column=0,column1=0;
    // cout<<c<<endl;
    if(m==1){cout<<"1 1"<<endl;return;}
    else if(m==2){
        for(ll i=0;i<n;i++){
            // for(ll j=m-1;j>m/2;j--){
                if(a[i][1]<a[i][0]){
                    c++;
                    column=1;
                    column1=0;
                }
                if(a[i][1]==a[i][0]){
                    c++;
                }
            // }
        }
    }
    else{
        int t=0;
        for(ll i=0;i<n;i++){
            for(ll j=m-1;j>m/2;j--){
                if(a[i][j]<a[i][(m-1)-j]){
                    c++;
                    column=j;
                    column1=(m-1)-j;
                    t++;
                }
                if(a[i][j]==a[i][(m-1)-j]){
                    c++;
                }
            }
        }
    }
    // cout<<c<<endl;
    if(c==0){
    cout<<"1 1"<<endl;}
    else if(c>n || c<n)
    cout<<"-1"<<endl;
    else if(c==n)
    cout<<column1+1<<" "<<column+1<<endl;
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