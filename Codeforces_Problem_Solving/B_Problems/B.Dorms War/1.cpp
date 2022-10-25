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
    string s;
    cin>>s;
    ll k;
    cin>>k;
    char array_of_char[k];
    for(ll i=0;i<k;i++){
        cin>>array_of_char[i];
    }
    ll maxi = INT_MIN;
    ll mini = INT_MAX;
    ll ans = 0;
    for(ll i=n-1;i>=0;i--){
        for(ll j=0;j<k;j++){
            if(array_of_char[j] == s[i]){
                ans = i;
                i=-1;
                break;
            }
        }
    }
    ll c = -1;
    for(ll i=0;i<ans-1;){
        c=0;
        for(ll j=0;j<k;j++){
            if(s[i+1] == array_of_char[j]){
                c++;
                i++;
            }else{
                i++;
            }
        }
    }
    if(c==-1){
        cout<<0<<'\n';return;
    }
    cout<<ans-(c*2)<<'\n';
    // maxi = c;
    // ll t = (ans - c);
    // mini = (min((maxi),t));
    // maxi = (max((maxi),t));
    // if(ans==0){
    //     cout<<0<<'\n';
    // }else{
    //     cout<<(ans + 1) - ((maxi + mini - 1)/mini)<<'\n';
    // }
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