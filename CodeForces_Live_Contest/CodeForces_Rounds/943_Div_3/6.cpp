#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Policy based data structures(PBDS) C++ STL
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// order_of_key(k): returns count of elements strictly smaller than k 
// Time complexity: O(logn) for both
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T > using pbds_SET = tree< T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_SET<pair<int , int > > s; for pairs
template<class T > using pbds_MULTISET = tree< T , null_type , less_equal<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_MULTISET<pair<int , int > > s; for pairs

#define nl                "\n"
#define ll                long long // typedef array<int , 2> p ; pair h ye
#define int               ll
#define yes               cout << "YES" << nl ;
#define no                cout << "NO" << nl ;
#define all(v)            v.begin(),v.end()
#define F                 first
#define S                 second
#define check1(v)         for(auto &i : v){ cout<<i<<" "; } cout<<nl ;
#define check2(v)         for(auto &i : v){ cout<<i.F<<" "<<i.S<<nl ; } 
#define pb                push_back
#define bpp               __builtin_popcountll
#define inf               1000000000000000000 // 18 zero's
#define Pi                3.1415926535897932384626
#define EPS               1e-9

const int MOD = 1000000007 ; // 998244353 // 10000000069LL // 3006703054056749LL 
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2}; 
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1}; 

int GCD(int a, int b){if(b == 0){return a;} return GCD(b, a % b);} // Euclidean algorithm for computing the greatest common divisor
int LCM(int a, int b){return ((long long)a / (long long)GCD(a, b) * (long long)b) ;}
int modpower(int x, int y, int m){long long res = 1; x = x % m; while(y > 0){if(y&1) res = (res * (long long)x) % MOD; y = y >> 1; x = ((long long)x * (long long)x) % MOD ;}return res ;} 
int mod_ADDITION(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_SUBTRACTION(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_MULTIPLICATION(int a, int b, int m) {a = a % m; b = b % m; return ((((long long)a * (long long)b) % m) + m) % m;}
int mod_DIVISION(int a, int b, int m){a %= m , b %= m; return mod_MULTIPLICATION(a , modpower(b , m - 2 , MOD) , m);}
long long power(long long x, long long y){long long res = 1 ; while(y > 0) {if(y & 1) res = (res * (long long)x) ; x = ((long long)x * (long long)x) ; y = y >> 1 ;} return res ;}
int modinv(int x){return modpower(x , MOD - 2 , MOD) ;} 
bool comparatorfunction(pair<int,int> &a, pair<int,int> &b){if(a.F != b.F){return a.F < b.F ;}return a.S > b.S ;}


/*

How to define our segment tree in the main function
vector<int > arr = {1 , 2 , 3 , 4} ;

SGT st(n , arr);

*/

struct SGT {
    struct Node {
        int val ; // may change
        Node() { // Identity element
            val = 0 ;    // may change // warning it is for query answers only what should be the output answer 
            // val = power(2 , 30) - 1 ;    // may change
            // val = INF ;    // may change
            // val = -INF ;    // may change
        }
        Node(int p1) {  // Actual Node
            val = p1 ; // may change
        }
        void merge(Node &l , Node &r) { // Merge two child nodes
            val = (l.val ^ r.val) ;  // may change
        }
    };
    struct Update { // note if mentioned about update then only it is used 
        int val ; // may change
        Update(int p1) { // Actual Update
            val = p1 ; // may change
        }
        void apply(Node &a) { // apply update to given node
            a.val = val ; // may change
        }
    };

    vector<Node > tree ; // it will change according to the node 
    vector<int > arr ; // type may change 
    int n , s ;
    int sz ; // 2^k where k is the least integer which satisfy 2^k >= n
    SGT(int array_len, vector<int> &a) { // change if type updated
        arr = a ;
        n = array_len ; 
        s = 1 ;
        while(s < 2 * n) {
            s = (s << 1);
        }
        tree.resize(s); 
        fill(all(tree), Node()) ;
        build(1 , 0 , n - 1) ;
    }
    void build(int index, int start, int end)  // Never change this
    {
        if(start == end){
            tree[index] = Node(arr[start]) ; // may change 
            return ;
        }
        int mid = (start + end) / 2 ;
        build(2 * index, start, mid) ;
        build(2 * index + 1, mid + 1, end) ;
        tree[index].merge(tree[2 * index] , tree[2 * index + 1]) ;
    }
    void update( int index, int start, int end, int query_index, Update &u)  // Never Change this
    {
        if(start == end){
            u.apply(tree[index]) ;
            return ;
        }
        int mid = (start + end) / 2 ;
        if(mid >= query_index)
            update(2 * index, start, mid, query_index, u);
        else
            update(2 * index + 1, mid + 1, end, query_index, u) ;
        tree[index].merge(tree[2 * index], tree[2 * index + 1]) ;
    }
    Node query(int index, int start, int end, int left, int right) { // may change 
        if(start > right || end < left) // may change // both if statements can be removed
            return Node() ;
        if(start >= left && end <= right) // may change // both if statements can be removed
            return tree[index] ; 
        int mid = (start + end) / 2 ; 
        Node l , r , ans ; 
        l = query(2 * index , start , mid , left, right) ; 
        r = query(2 * index + 1 , mid + 1 , end , left , right) ; 
        ans.merge(l , r) ; 
        return ans ; 
    }
    void make_update(int index, int val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(1 , 0 , n - 1 , index , new_update) ;
    }
    Node make_query(int left , int right) { // may change
        return query(1 , 0 , n - 1 , left , right) ; // may change
    }
    int first(){
        return tree[1].val ;
    }
    void output(){
        for(int i = 1 ; i < s ; ++i){
            cout << tree[i].val <<  " " ;
        }
        cout << "\n" ;
    }
};


bool solve(){
    int n , q ;
    cin >> n >> q ;
    vector<int > a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i] ;
    }
    SGT sgt(n , a) ;
    while(q--){
        int l,r;
        cin>>l>>r;
        l -= 1;
        r -= 1;
        if(l + 1 == r){
            if(a[l] == a[r]) yes
            else no
        }
        else{
            int ok = sgt.make_query(l+1,r-1).val;
            if((ok ^ a[l]) == a[r]) yes
            else if(a[l] == (ok ^ a[r])) yes
            else no
        }
    }
    cout<<nl;
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


