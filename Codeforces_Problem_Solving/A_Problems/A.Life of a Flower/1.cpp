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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll negative=0;
    ll positive =0;
    ll one=1;
    if(n==1){
        if(v[0]==1){
            cout<<2<<'\n';
            return;
        }
    }
    if(n==2){
        if(v[0]==v[1] && v[0]==0){
            cout<<-1<<'\n';
        }
        else if(v[0]==v[1] && v[0]==1){
            cout<<6<<'\n';
        }
        else{
            cout<<2<<'\n';
        }
        return;
    }
    for(int i=1;i<n;i++){
        if(v[i]==0 && v[i]==v[i-1]){
            negative++;
        }
        if(v[i]==1 && v[i]==v[i-1]){
            positive++;
        }
    }
    for(int i=1;i<n-1;i++){
        if(v[i]==1 && v[i+1]!=1 && v[i-1]!=1){
            one++;
        }
        if(v[1]==1 && v[0]==0){
            one++;
        }
        if(v[0]==1 && v[1]==0){
            one++;
        }
        if(v[n-1]==1 && v[n-2]==0){
            one++;
        }
    }
    if(negative>0){
        cout<<-1<<'\n';
    }else{
        cout<<positive*5 + one<<'\n';
    }
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