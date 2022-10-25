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
    ll w,h;
    cin>>w>>h;
    ll t = 2;
    ll max_horizontal = INT_MIN;
    while(t--){
        ll k;
        cin>>k;
        ll horizontal_array[k];
        for(ll i=0;i<k;i++){
            cin>>horizontal_array[i];
        }
        // ll max_horizontal = INT_MIN;
        sort(horizontal_array, horizontal_array + k);
        max_horizontal = max(max_horizontal, (horizontal_array[k-1] - horizontal_array[0]));
    }
    t=2;
    ll max_vertical = INT_MIN;
    while(t--){
        ll k;
        cin>>k;
        ll vertical_array[k];
        for(ll i=0;i<k;i++){
            cin>>vertical_array[i];
        }
        // ll max_vertical = INT_MIN;
        sort(vertical_array, vertical_array + k);
        max_vertical = max(max_vertical, (vertical_array[k-1] - vertical_array[0]));
    }
    ll ans = max((max_horizontal*h) , (max_vertical*w));
    cout<<ans<<'\n';
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