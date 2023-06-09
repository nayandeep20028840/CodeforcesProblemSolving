Refer 4.cpp for code

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
    if(n%7==0){cout<<n<<endl;return;}
    ll t=n;
    ll t1;
    if(n%7==6){
        cout<<n+1<<endl;
        return;
    }
    if(n%7!=0){
        string s = to_string(t);
        int t2 = n%10;
        // cout<<s<<endl;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                s[i]='7';
                // s.erase(s[i]);
                // s.insert(i,1,'7');
            }else{
                break;
            }
        }
        // cout<<s<<endl;
        int n2 = stoi(s);
        if((10-t2)>=7){
            t1= n2 + 7 - n2%7;
        }else{
            t1= n2 - n2%7;
           
        }
        
        cout<<t1<<endl;
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
