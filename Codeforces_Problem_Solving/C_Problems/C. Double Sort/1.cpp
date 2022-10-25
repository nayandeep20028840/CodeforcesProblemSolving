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
    vector<int> a(n);
    vector<int> b(n);
    vector<int> a1(n);
    vector<int> b1(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a1[i]=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        b1[i]=b[i];
    }
    ll ans=0;
    sort(a1.begin(),a1.end());
    sort(b1.begin(),b1.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((a[j]<=a[i] && b[j]<b[i]) || (a[j]<a[i] && b[j]<=b[i])){
                swap(a[j],a[i]);
                swap(b[j],b[i]);
                ans++;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1-1-i;j>=0;j--){
            if((a[j]>=a[i] && b[j]>b[i]) || (a[j]>a[i] && b[j]>=b[i])){
                swap(a[j],a[i]);
                swap(b[j],b[i]);
                ans++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=a1[i] || b[i]!=b1[i]){ 
            cout<<-1<<'\n';
            return;
        }
    }
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