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

bool solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n+m+1);
    vector<int>b(n+m+1);
    for(int i=0;i<n+m+1;++i){
        cin>>a[i];
    }
    for(int i=0;i<n+m+1;++i){
        cin>>b[i];
    }
    set<int>pro_shi,pro_galat;
    set<int>test_shi,test_galat;
    int pro=n;
    int test=m;
    int sum=0;
    for(int i=1;i<n+m+1;++i){
        if(a[i]>b[i]){
            if(pro>0){
                pro-=1;
                sum+=a[i];
                pro_shi.insert(i);
            }
            else{
                test-=1;
                sum+=b[i];
                test_galat.insert(i);
            }
        }
        else{
            if(test>0){
                test-=1;
                sum+=b[i];
                test_shi.insert(i);
            }
            else{
                pro-=1;
                sum+=a[i];
                pro_galat.insert(i);
            }
        }
    }
    pro=0;
    test=0;
    cout<<sum<<" ";
    for(int i=1;i<n+m+1;++i){
        if(a[i]>b[i]){
            if(a[i-1]>b[i-1]){
                if(pro<n){
                    pro+=1;
                    sum-=a[i];
                    sum+=a[i-1];
                }
                else{
                    test+=1;
                    sum-=b[i];
                    sum+=b[i-1];
                }
            }
            else{
                if(test<m){
                    test+=1;
                    sum+=b[i-1];
                    if(pro<n){
                        sum-=a[i];
                        if(test_galat.size()>0){
                            pro_shi.insert(*(test_galat.begin()));
                            sum+=a[*(test_galat.begin())];
                            sum-=b[*(test_galat.begin())];
                            test_galat.erase(test_galat.begin());
                        }
                        else if(test_shi.size()>0){
                            pro_galat.insert(*prev(test_shi.end()));
                            sum+=a[*prev(test_shi.end())];
                            sum-=b[*prev(test_shi.end())];
                            test_shi.erase(prev(test_shi.end()));
                        }
                    }
                    else{
                        sum-=b[i];
                    }
                }
                else{
                    pro+=1;
                    sum+=a[i-1];
                    sum-=a[i];
                }
            }
        }
        else{
            if(b[i-1]>a[i-1]){
                if(test<m){
                    test+=1;
                    sum-=b[i];
                    sum+=b[i-1];
                }
                else{
                    pro+=1;
                    sum-=a[i];
                    sum+=a[i-1];
                }
            }
            else{
                if(pro<n){
                    pro+=1;
                    sum+=a[i-1];
                    if(test<m){
                        sum-=b[i];
                        if(pro_galat.size()>0){
                            test_shi.insert(*(pro_galat.begin()));
                            sum+=b[*(pro_galat.begin())];
                            sum-=a[*(pro_galat.begin())];
                            pro_galat.erase(pro_galat.begin());
                        }
                        else if(pro_shi.size()>0){
                            test_galat.insert(*prev(pro_shi.end()));
                            sum+=b[*prev(pro_shi.end())];
                            sum-=a[*prev(pro_shi.end())];
                            pro_shi.erase(prev(pro_shi.end()));
                        }
                    }
                    else{
                        sum-=a[i];
                    }
                }
                else{
                    test+=1;
                    sum+=b[i-1];
                    sum-=b[i];
                }
            }
        }
        while(test_galat.size()>0 and *(test_galat.begin())<=i) test_galat.erase(test_galat.begin());
        while(pro_galat.size()>0 and *(pro_galat.begin())<=i) pro_galat.erase(pro_galat.begin());
        while(test_shi.size()>0 and *(test_shi.begin())<=i) test_shi.erase(test_shi.begin());
        while(pro_shi.size()>0 and *(pro_shi.begin())<=i) pro_shi.erase(pro_shi.begin());
        cout<<sum<<" ";
    }
    cout<<endl;
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
    int count = 1 ;
    while (t--){
        //cout << "Case #" << count << ": ";
        // if(count==868){
        //     int n,m;
        //     cin>>n>>m;
        //     vector<int>a(n+m+1);
        //     vector<int>b(n+m+1);
        //     cout<<n<<""<<m<<"";
        //     for(int i=0;i<n+m+1;++i){
        //         cin>>a[i];
        //         cout<<a[i]<<"";
        //     }
        //     for(int i=0;i<n+m+1;++i){
        //         cin>>b[i];
        //         cout<<b[i]<<"";
        //     }
        //     cout<<endl;
        // }
        if(solve()){
            //count++ ;
        }else{
            // no 
        }
        count+=1;
    }
    return 0 ;
}


