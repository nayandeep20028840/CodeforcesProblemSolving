#include<bits/stdc++.h>
using namespace std;

// Policy based data structures(PBDS) C++ STL
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// order_of_key(k): returns count of elements strictly smaller than k 
// Time complexity: O(logn) for both
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // for pairs only define simply by ordered_set s
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
template<class T>using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree<pair<int,int>> s; for pairs

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
vector<int > giveme_it_isprime_or_not(int n){vector<int > isPrime(n+1, 1);isPrime[0]=isPrime[1]=false;for(int i = 2; i <= n; ++i){if(isPrime[i] == true){for(int j = 2*i; j <= n; j += i){isPrime[j] = false;}}} return isPrime;}
vector<int> givemeprimes(int n) {int*arr = new int[n + 1](); vector<int> vect; for(int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for(int j = i * i; j <= n; j += i)arr[j] = 1;} return vect;}
vector<vector<int>> givemedivisors(int n){int*arr = new int[n + 1]();vector<vector<int > > vect(n + 1);for(int i = 2; i <= n; ++i){if(arr[i] == 0){for(int j = i; j <= n; j += i){vect[j].pb(i);arr[i] = 1;}}} return vect ;}
vector<int > givemesmallestprimefactors(int n){vector<int > SPF(n + 1);for(int i = 0; i <= n; ++i){SPF[i] = i;}for(int i = 2; i <= n; ++i){if(SPF[i] == i){for(int j = i; j <= n; j += i){if(SPF[j] == j){SPF[j] = i;}}}}return SPF ;} // SPF is the smallest prime number that divides a given number without leaving a remainder
int sqrtprecision(int l,int r,int target){while(r-l>EPS){int mid=(l+(r-l)/2);if(mid*mid<target)l=mid;else r=mid;}return l+(r-l)/2;}
void ncrwithoutmod(int n, int r){long long p = 1, k = 1; if (n-r < r) r = n-r; if (r != 0) {while (r) {p *= n; k *= r; long long m = __gcd(p, k);p /= m; k /= m; n--; r--; }} else cout << p << endl; }
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 

const int NN = 2e6+1 ; // warning don't exceed 1e7+1e6 ;
int block_size ;
vector<int > v(NN) ;
vector<int > freq(NN) ;
vector<int > xor_freq(NN) ;
vector<int > count_freq(NN) ;
int answer = 0 ;

struct Query { // name of the structure
    int l , r , idx ;

    Query(int _l , int _r , int _idx) : l(_l) , r(_r) , idx(_idx) { // These lines initialize the member variables with the values passed as arguments to the constructor.

    } // defining a constructor for a structure. The constructor initializes three member variables: l, r, and idx, presumably within the context of that structure.

    bool operator<(Query other) const // sort the queries
    {
        return make_pair(l / block_size, r) <            // jaadu
                make_pair(other.l / block_size, other.r);
    }
};

void remove(int idx) { // TODO: remove value at idx from data structure
    answer -= count_freq[xor_freq[idx]] ;
    answer = max(0ll , answer) ;
}  
void add(int idx) {  // TODO: add value at idx from data structure
    answer += count_freq[xor_freq[idx]] ;
}    
int get_answer() { // TODO: extract the current answer of the data structure
    return answer ;
}  

vector<int > mo_s_algorithm(vector<Query > queries , int n) {
    vector<int > answers(queries.size()) ;
    sort(queries.begin(), queries.end()) ;

    // TODO: initialize data structure

    int cur_l = 0 ;
    int cur_r = n - 1 ;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l-- ;
            add(cur_l) ;
        }
        while (cur_r < q.r) {
            cur_r++ ;
            add(cur_r + 1) ;
        }
        while (cur_l < q.l) {
            remove(cur_l) ;
            cur_l++ ;
        }
        while (cur_r > q.r) {
            remove(cur_r + 1) ;
            cur_r-- ;
        }
        answers[q.idx] = get_answer() ;
    }
    return answers ;
}

/*

    Time complexity : very important O(Q * logQ) for sorting +(plus) Q * root(n)
    for all query combined maximum range covered is root(n)

    define block_size as
    {
        int sq = sqrtl(n) ;
        block_size = sqrtl(n) + (n % sq == 0 ? 0 : 1) ;
    }

    vector<Query > queries ;
    vector<int > got_it = mo_s_algorithm(queries) ;
    for(int i = 0 ; i < q ; ++i){
        cout << got_it[i] << " " ;
    }
    cout << nl ;

*/

bool solve(){
    int n , m , k ;
    cin >> n >> m >> k ;
    xor_freq.clear() ;
    count_freq.clear() ;
    for(int i = 0 ; i < n ; ++i) cin >> v[i] ;
    freq[0] = 1 ;
    int x = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        xor_freq[i] = (x ^ v[i - 1]) ;
        x = (x ^ v[i - 1]) ;
        answer += freq[x ^ k] ;
        freq[x] += 1 ;
        count_freq[xor_freq[i] ^ k] += 1 ;
    }
    cout << answer << nl ;
    for(int i = 0 ; i < n ; ++i){
        cout << xor_freq[i] << " " ;
    }
    cout << xor_freq[n] << nl ;
    for(int i = 0 ; i < n ; ++i){
        cout << count_freq[i] << " " ;
    }
    cout << nl ;
    int sq = sqrtl(n) ;
    block_size = sqrtl(n) + (n % sq == 0 ? 0 : 1) ;
    vector<Query > queries ;
    for(int i = 0 ; i < m ; ++i){
        int l , r ;
        cin >> l >> r ;
        l -- ; r -- ;
        queries.push_back(Query(l , r , i)) ;
    }
    vector<int > got_it = mo_s_algorithm(queries , n) ;
    for(int i = 0 ; i < m ; ++i){
        cout << got_it[i] << nl ;
    }
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    freopen("error.txt", "w", stderr);
//#endif 
    int t = 1;
    //cin >> t;  
    //int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        if(solve()){
            //count++;
        }else{
            // no 
        }
    }
    return 0;
}




 // Talk is Cheap. Show me the code 
