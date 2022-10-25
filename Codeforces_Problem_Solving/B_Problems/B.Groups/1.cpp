#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define ll                long long
#define all(v)            v.begin(),v.end()
#define pb                push_back
#define popb              pop_back
#define pf                push_front
#define popf              pop_front
#define lb                lower_bound
#define ub                upper_bound
#define f                 first
#define s                 second
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
    ll a[n][5];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    ll a1=0,b=0,c=0;
    for(ll i=0;i<5;i++){
        for(ll k=i+1;k<5;k++){
            for(ll j=0;j<n;j++){
                if(a[j][i]==1 && a[j][k]==0){
                    a1++;
                }
                else if(a[j][i]==0 && a[j][k]==1){
                    b++;
                }
                else if(a[j][i]==1 && a[j][k]==1){
                    c++;
                }
            }
            // cout<<a1<<" "<<b<<" "<<c<<" ";
            if((a1+b+c)== n && a1<=(n/2) && b<=(n/2)){
                cout<<"YES"<<'\n';
                return;
            }
            a1=0,b=0,c=0;
        }
    }
    cout<<"NO"<<'\n';
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