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
            val = max(l.val , r.val) ;  // may change
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
        fill(tree.begin(),tree.end(), Node()) ;
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
    string s;
    cin>>s;
    int n=s.size();
    vector<int>pf(n,0);
    int sum=0;
    map<int,vector<int>>mp;
    for(int i=0;i<n;++i){
        sum+=(s[i]=='(');
        sum-=(s[i]==')');
        if(sum<0){
            cout<<0<<endl;
            return true;
        }
        pf[i]=sum;
    }
    sum=0;
    SGT sgt(n,pf);
    int ans=0;
    for(int i=0;i<n;++i){
        sum+=(s[i]=='(');
        sum-=(s[i]==')');
        vector<int>v;
        if(mp[sum].size()>0){
            for(auto &j:mp[sum]){
                v.push_back(j);
            }
        }
        int len=v.size();
        cout<<len<<" ";
        // cout<<sum<<" ";
        int low=-1;
        int high=len;
        while(high-low>1 and len>0){
            int mid=(high+low)/2;
            int idx=v[mid];
            int f=0;
            int val1=pf[idx];
            // cout<<val<<" ";
            int tot_open=sgt.make_query(val1+1,i).val;
            // cout<<tot_open<<" ";
            int rem=tot_open-val1;
            if(val1<sum || (rem>val1)) f=1;
            if(f>0){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        cout<<high<<endl;
        ans+=max(0ll,len-high);
        mp[sum].push_back(i);
    }
    cout<<ans<<endl;
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


