#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
const long long int inf = 1e18;
 
#define ll                long long
#define ld                long double
#define mp                make_pair
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define lb                lower_bound
#define ub                upper_bound
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(dp)          memset(dp,-1,sizeof(dp))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define Pi                3.1415926535897932384626
 
char convertIntToChar(int num) {
    char ch = 'a'+num;
    return ch;
}
 
const int N = 1e5 + 4;
const int M = 1e9 + 7;
 
void solve(){
    int n;
    cin>>n;
    int a[n],b[n],arr[2*n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }   
    int i=0,j=0,k=0;  
    while(i<n){  
        arr[k] = a[i];  
        i+=1;  
        k+=1;  
    }  
    while(j<n){  
        arr[k]=b[j];  
        j+=1;  
        k+=1;  
    }  
    sort(arr,arr+n+n); 
    int h=0,sum=0;
    while(h<n-1){
        sum=sum+abs(arr[h+1]-arr[h]);
        h++;
    }
    int sum1=0;
    int h1=n;
    while(h1<2*n-1){
        sum1=sum1+abs(arr[h1+1]-arr[h1]);
        h1++;
    }
    cout<<sum+sum1<<endl;
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