#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD = 1000000007 ; // 998244353 
const long long inf = 1000000000000000000LL; // 18 zero's // LLONG_MAX = 9223372036854775807 - 19 digits
#define int long long

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return ((long long)a / (long long)GCD(a, b) * (long long)b) ;}
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.first != b.first){return a.first < b.first ;}return a.second > b.second ;}

// Function to get the sum of submatrix from (row1, col1) to (row2, col2)
int getSubmatrixSum(const vector<vector<int>>& prefixSum, int row1, int col1, int row2, int col2) {
    int sum = prefixSum[row2][col2];
    if (row1 > 0) sum -= prefixSum[row1-1][col2];
    if (col1 > 0) sum -= prefixSum[row2][col1-1];
    if (row1 > 0 && col1 > 0) sum += prefixSum[row1-1][col1-1];
    return sum;
}


bool solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat[i][j];
        }
    }
    vector<vector<char>>oneszeros(n,vector<char>(m));
    int sum1=0;
    int sum0=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>oneszeros[i][j];
            if(oneszeros[i][j]=='1'){
                sum1+=mat[i][j];
            }
            else{
                sum0+=mat[i][j];
            }
        }
    }
    vector<vector<int>>countones(n,vector<int>(m,0));
    vector<vector<int>>onesum(n,vector<int>(m,0));
    vector<vector<int>>zerosum(n,vector<int>(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(oneszeros[i][j]=='1'){
                countones[i][j] = 1;
            }
            if (i > 0) countones[i][j] += countones[i-1][j];
            if (j > 0) countones[i][j] += countones[i][j-1];
            if (i > 0 && j > 0) countones[i][j] -= countones[i-1][j-1];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(oneszeros[i][j]=='1'){
                onesum[i][j] = mat[i][j];
            }
            if (i > 0) onesum[i][j] += onesum[i-1][j];
            if (j > 0) onesum[i][j] += onesum[i][j-1];
            if (i > 0 && j > 0) onesum[i][j] -= onesum[i-1][j-1];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(oneszeros[i][j]=='0'){
                zerosum[i][j] = mat[i][j];
            }
            if (i > 0) zerosum[i][j] += zerosum[i-1][j];
            if (j > 0) zerosum[i][j] += zerosum[i][j-1];
            if (i > 0 && j > 0) zerosum[i][j] -= zerosum[i-1][j-1];
        }
    }
    int dummysum1=sum1;
    int dummysum0=sum0;
    int diff=abs(sum1-sum0);
    int gcd=0;
    for(int i=0;i<=n-k;++i){
        for(int j=0;j<=m-k;++j){
            int sumone = getSubmatrixSum(onesum, i, j, i + k - 1, j + k - 1);
            int sumzero = getSubmatrixSum(zerosum, i, j, i + k - 1, j + k - 1);
            int onecount = getSubmatrixSum(countones, i, j, i + k - 1, j + k - 1);
            int tot=k*k;
            int zerocount=tot-onecount;
            int countdiff=abs(onecount-zerocount);
            // sum1-=sumone;
            // sum0-=sumzero;
            
            // cout<<sumone<<" "<<sumzero<<endl;
            // cout<<diff<<" "<<countdiff<<endl;
            gcd=GCD(gcd,countdiff);
            if((gcd>0 and diff%gcd==0) || (gcd==0 and diff==0)){
                cout<<"YES"<<endl;
                return true;
            }
        }
    }
    cout<<"NO"<<endl;
    return true ;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    freopen("error.txt", "w", stderr);
//#endif 
    int t ;
    cin >> t ;  
    //int count = 1 ;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            //count++ ;
        }else{
            // no 
        }
    }
    return 0 ;
}


