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
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // sort(v.begin(),v.end());
    sort(v,v+n);
    vector<int> v1;
    if(n%2==0){
        for(int i=0;i<n/2;i++){
                v1.pb(v[i]);
                v1.pb(v[(n/2)+i]);
            }
    }
    if(n%2!=0){
        v1.pb(v[0]);
        for(int i=0;i<n/2;i++){
            v1.pb(v[(n/2)+i]);
            v1.pb(v[i+1]);
            // for(int i=n/2 + 1;i<n;i++){
                // v1.pb(v[(n/2)+i]);
            // }
        }
        // v1.pb(v[0]);
    }
    
    int c=0;
    for(int i=1;i<n-1;i++){
        if(((v1[i]>v1[i-1] && v1[i]>v1[i+1] ) || (v1[i]<v1[i-1] && v1[i]<v1[i+1]))){
            c++;
        }
    }
    if(c==(n-2)){
        cout<<"YES"<<endl;
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
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