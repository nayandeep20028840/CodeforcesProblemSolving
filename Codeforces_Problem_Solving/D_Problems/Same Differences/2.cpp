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
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        v[i] = v[i] - (i+1);
    }
    int c=0;
    int t=0;
    sort(v.begin(),v.end());
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<n-1;i++){
        if((v[i+1]-v[i])==0 && v[i]==0){
            v1.pb(0);
        }
        if((v[i+1]-v[i])==0 && v[i]!=0){
            v2.pb(0);
        }
    }
    c=v1.size()+1;
    int c1;
    if(v2.size()>0)
    c1=v2.size() + 1;
    else
    c1=0;
    // for(int i=0;i<n;i++){
    //     if(v[i]==0){
    //         c++;
    //     }
    // }
    int i=1;
    int sum =0;
    while(i<=c){
        sum = sum + (i-1);
        i++;
    }
    cout<<sum+c1<<endl;
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