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
    int n = s.length();
    int t=0,t1,t2,t3=0,t4,t5,t6;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            t++;
            t1=i;
            break;
        }
        // if(s[i]=='5'){
        //     t1=i;
        // }
    }
    for(int i=n-2;i>=0;i--){
        if(t>0){
            if(s[i]=='5' || s[i]=='0'){
                t2 = t1 - i - 1;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='5'){
            t3++;
            t4=i;
            break;
        }
        // if(s[i]=='5'){
        //     t1=i;
        // }
    }
    for(int i=n-2;i>=0;i--){
        if(t3>0){
            if(s[i]=='2' || s[i]=='7'){
                t5 = t4 - i - 1;
            }
        }
    }
    cout<<min(t5,t2)<<endl;
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