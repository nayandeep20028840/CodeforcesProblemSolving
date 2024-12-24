#include<bits/stdc++.h>
using namespace std;

// Policy based data structures(PBDS) C++ STL
// order_of_key(k): returns count of elements strictly smaller than k 
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// Time complexity: O(logn) for both
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
#define INF               1000000000000000000
#define Pi                3.1415926535897932384626
#define EPS               1e-9
#define nl                "\n"

const int mod97 = 1000000007 ;
const int modg = 998244353 ;
const int N = 2e1 + 1 ;
const int LOG = 21 ;
int SPF[N + 1] ;
vector<bool > isPrime(N + 1 , 1) ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ; // a random number generator (RNG) using the Mersenne Twister algorithm, specifically the mt19937 engine. The purpose of an RNG is to generate a sequence of random numbers.

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);}
int LCM(int a, int b){return (a / GCD(a, b) * b) ;}
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.S != b.S){return a.S < b.S ;}return a.F > b.F ;}
int power(int x, int y){int res = 1 ; while(y > 0) {if(y & 1) res = (res * x) ; x = (x * x) ; y = y >> 1 ;} return res ;}
int modpower(int x, int y){int res = 1; x = x % mod97; while(y > 0){if(y&1) res = (res * x) % mod97; y = y >> 1; x = (x * x) % mod97 ;}return res ;} 
bool isPowerOfTwo(int n){if(n==0) {return false;} return (ceil(log2(n)) == floor(log2(n)));}
void prime(){isPrime[0]=isPrime[1]=false;for(int i = 2; i <= N; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= N; j += i){isPrime[j] = false;}}}}
void spf(){for(int i = 0; i <= N; ++i) SPF[i] = i; for(int i = 2; i <= N; ++i) if(SPF[i] == i) for(int j = i; j <= N; j += i) if(SPF[j] == j) SPF[j] = i;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
void ncrwithoutmod(int n, int r){long long p = 1, k = 1; if (n-r < r) r = n-r; if (r != 0) {while (r) {p *= n; k *= r; long long m = __gcd(p, k);p /= m; k /= m; n--; r--; }} else cout << p << endl; }
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

        node root;

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

        int max_xor(int val) {
            int ans = 0 ;
            node* temp = &root ;
            for(int i = 31 ; i >= 0 ; --i) {
                int bit = 1 ;
                if((val & (1 << i)) == 0) {
                    bit = 0 ;
                }

                int req = 1 - bit ;

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
    };
};

/*

// Trie.

usually apllied on string ----> find string , find prefix in a string , Longest word with all prefix's (T.C -> O(n * len)) , Number of distinct Substring (T.C -> O(n * n))
usually apllied for finding XOR's ----> Maximum XOR of Two numbers in an array , Maximum XOR with an element from array
usually called prefix tree.

*/


// In this question T.C is equal to O(n * len(maximum)) ;
// 1e5 * 2 power 8
// 1e5 * 256 --- > 2e7(1 second)

bool solve(){
    int n ;
    cin >> n ;
    Trie::BITS_TRIE bt ;
    int ans = 0 ;
    int current_XOR = 0 ;
    bt.insert(current_XOR) ;
    for(int i = n - 1 ; i >= 0 ; --i){
        int x ;
        cin >> x ;
        current_XOR = (current_XOR ^ x) ;
        ans = max(ans , bt.max_xor(current_XOR)) ;
        bt.insert(current_XOR) ;
    }
    cout << ans << nl ;
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
    int t;
    cin >> t;  
    //int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            //count++;
        }else{
            // cout << "NO" << endl;
        }
    }
    return 0;
}
 
 
 
 