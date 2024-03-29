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
    ll n;
    cin>>n;
    if(n%2!=0){
        cout<<-1<<endl;
        return;
    }
    ll t = n/4;
    ll t1 = n/6;
    ll t2 = n%4;
    ll t3 = n%6;
    if(n==2){
        cout<<-1<<endl;
        return;
    }
    if(n==4){
        cout<<1<<" "<<1<<endl;return;
    }
    if(n==8){
        cout<<2<<" "<<2<<endl;return;
    }
    if(n==6){
        cout<<1<<" "<<1<<endl;return;
    }  
    if(t2==0 && t3==0){
        cout<<t1<<" "<<t<<endl;return;
    }
    if(t2!=0 && t3==0){
        cout<<t1<<" "<<(n-6)/4 + 1<<endl;
        return;
    }
    if(t2==0 && t3!=0){
        cout<<((n-8)/6) + 2 <<" "<<t<<endl;
        return;
    }
    if(t2!=0 && t3==2){
        cout<<(n-8)/6 + 2<<" "<<(n-6)/4 + 1<<endl;
        return;
    }
    if(t2!=0 && t3==4){
        cout<<(n-4)/6 + 1<<" "<<(n-6)/4 + 1<<endl;
        return;
    }
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