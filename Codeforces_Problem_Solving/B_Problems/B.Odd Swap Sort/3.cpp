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
 
 
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
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
    vector<ll> v(n);
    vector<ll> even;
    vector<ll> odd;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(v[i]&1){
            odd.pb(v[i]);
        }else{
            even.pb(v[i]);
        }
    }
    vector<ll> sorted_even(even);
    vector<ll> sorted_odd(odd);
    sort(sorted_even.begin(),sorted_even.end());
    sort(sorted_odd.begin(),sorted_odd.end());
    for(ll i=0;i<sorted_even.size();i++){
        if(even[i]!=sorted_even[i]){
            cout<<"NO"<<'\n';
            return;
        }
    }
    for(ll i=0;i<sorted_odd.size();i++){
        if(odd[i]!=sorted_odd[i]){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';


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