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
    // vector<int> v;
    // vector<int> v1;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    } 
    for(int i=1;i<n;i++){
        if(a[i]==1){
            cout<<"-1"<<endl;return;
        }
    }  
    sort(a,a+n);
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            c++;
        }
    }
    if(c==n){
        cout<<"0"<<endl;return;
    }
    int h=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i]>b[i+1]){
                b[i]=b[i]/2;
                h++;
            }
        }
    }
    cout<<h<<endl;
    
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