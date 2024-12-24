#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // for pairs only define simply by ordered_set s
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
template<class T>using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree<pair<int , int > > s; for pairs

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define ll                long long
#define int               ll
#define ld                long double
#define iv(a , n)         vector<int>a(n); for(int i=0;i<n;++i){cin>>a[i];}
#define yes               cout << "YES" << endl;
#define no                cout << "NO" << endl;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<endl;
#define check2(v)         for(auto &i : v){ cout<<i.F<<" "<<i.S<<endl; } 
#define check3(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S<<endl; } 
#define check4(v)         for(auto &i : v){ cout<<i.F.F<<" "<<i.F.S<<" "<<i.S.F<<" "<<i.S.S<<endl; }
#define pb                push_back
#define lb                lower_bound
#define ub                upper_bound
#define bpp               __builtin_popcountll
#define inf               1000000000000000000 // 18 zero's
#define Pi                3.1415926535897932384626
#define EPS               1e-9
#define nl                "\n"

const int MOD = 1000000007 ; // 998244353 
const int LOG = 21 ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor 
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modpower(int x, int y){long long res = 1; x = x % MOD; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int modinv(int x){return modpower(x , MOD - 2) ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.S != b.S){return a.S < b.S ;}return a.F > b.F ;}
vector<int > giveme_it_isprime_or_not(int n){vector<int > isPrime(n+1, 1);isPrime[0]=isPrime[1]=false;for(int i = 2; i * i <= n; ++i){if(isPrime[i] == true){for(int j = 2 * i; j <= n; j += i){isPrime[j] = false;}}} return isPrime;} // Time Complexity - O(n * sqrt(n) * log(n)) 
vector<int> givemeprimes(int n) {int*arr = new int[n + 1](); vector<int> vect; for(int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for(int j = i * i; j <= n; j += i)arr[j] = 1;} return vect;} // can be calculated in O(n) 
vector<vector<int>> givemedivisors(int n){int*arr = new int[n + 1]();vector<vector<int > > vect(n + 1);for(int i = 2; i <= n; ++i){if(arr[i] == 0){for(int j = i; j <= n; j += i){vect[j].pb(i);arr[i] = 1;}}} return vect ;}
vector<int > givemesmallestprimefactors(int n){vector<int > SPF(n + 1);for(int i = 0; i <= n; ++i){SPF[i] = i;}for(int i = 2; i <= n; ++i){if(SPF[i] == i){for(int j = i; j <= n; j += i){if(SPF[j] == j){SPF[j] = i;}}}}return SPF ;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

class Trie {
public:
    struct BITS_TRIE {
        private:
        struct node {
            int start = 0 ;
            int end = 0 ;
            bool flag = false ;
            int cnt = 0 ;
            node* next[2] ;
            node() {
                next[1] = next[0] = NULL ;
            }
        };

        node root ;

        public:
        void insert(int val) {
            node* temp = &root;
            temp->cnt++ ;
            for(int i = 31 ; i >= 0 ; --i) {
                int bit = 1 ;
                if((val & (1 << i)) == 0) {
                    bit = 0 ;
                }

                if(temp->next[bit] == NULL) {
                    temp->next[bit] = new node() ;
                }

                temp = temp->next[bit] ;
                temp->cnt++ ;
            }
        }

        void remove(int val) {
            node* temp = &root;
            temp->cnt-- ;
            for(int i = 31 ; i >= 0 ; --i) {
                int bit = 1 ;
                if((val & (1 << i)) == 0) {
                    bit = 0 ;
                }

                temp = temp->next[bit] ;
                temp->cnt-- ;
            }
        }

        int max_xor(int val) {
            int ans = 0 ;
            node* temp = &root ;
            for(int i = 31 ; i >= 0 ; --i) {
                int bit = 1 ;
                if((val & (1 << i)) == 0) {
                    bit = 0 ;
                }

                int req = 1 - bit ; // what we want to maximize opposite of bit because 1 ^ 0 = 1 and 0 ^ 1 = 1

                if(temp->next[req] == NULL) {
                    temp = temp->next[1 - req] ;
                }
                else if(temp->next[req]->cnt == 0) {
                    temp = temp->next[1 - req] ;
                }
                else {
                    ans += (1 << i) ;
                    temp = temp->next[req] ;
                }
            }

            return ans ;
        }

        int min_xor(int val){
            int ans = 0 ;
            node* temp = &root ;
            for(int i = 31 ; i >= 0 ; --i){
                int bit = 1 ;
                if((val & (1 << i)) == 0){
                    bit = 0 ;
                }

                int req = bit ; // what we want to minimize

                if(temp->next[req] == NULL){
                    ans += (1 << i) ;
                    temp = temp->next[1 - req] ;
                }
                else if(temp->next[req]->cnt == 0){
                    ans += (1 << i) ;
                    temp=temp->next[1 - req] ;
                }
                else{
                    temp = temp->next[req] ;
                }
            }

            return ans ;
        }
    };
};

bool solve(){
    int q ;
    cin >> q ;
    Trie::BITS_TRIE bt ;
    bt.insert(0) ;
    for(int i = 0 ; i < q ; ++i){
        char c ;
        cin >> c ;
        int value ;
        cin >> value ;
        if(c == '+'){
            bt.insert(value) ;
        }
        else if(c == '-'){
            bt.remove(value) ;
        }
        else{
            cout << bt.max_xor(value)  << nl ;
        }
    }
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
    int t = 1 ;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            
        }else{
            
        }
    }
    return 0 ;
}




 // Talk is Cheap. Show me the code 