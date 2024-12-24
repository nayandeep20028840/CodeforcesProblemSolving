// Lazy Segment Tree with Range Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template<typename Node, typename Update>
struct LazySGT {
    vector<Node > tree ; // no change
    vector<bool > lazy ; // no change
    vector<Update > updates ; // no change
    vector<int > arr ; // type may change
    int n ;
    int sz ; // 2^k where k is the least integer which satisfy 2^k >= n
    LazySGT(int array_len , vector<int > &a) { // change if type updated
        arr = a ;
        n = array_len ;
        sz = 1 ;
        while(sz < 2 * n){
            sz = (sz << 1) ;
        }
        tree.resize(sz) ; fill(all(tree) , Node()) ;
        lazy.resize(sz) ; fill(all(lazy) , false) ;
        updates.resize(sz) ; fill(all(updates) , Update()) ;
        build(0 , n - 1 , 1) ;
    }
    void build(int start , int end , int index) { // Never change this
        if (start == end)   {
            tree[index] = Node(arr[start]) ; // no changes
            return ;
        }
        int mid = (start + end) / 2 ;
        build(start , mid, 2 * index) ;
        build(mid + 1 , end , 2 * index + 1) ;
        tree[index].merge(tree[2 * index] , tree[2 * index + 1]) ;
    }
    void pushdown(int index , int start , int end){
        if(lazy[index]){
            int mid = (start + end) / 2 ; 
            apply(2 * index , start , mid , updates[index]) ;
            apply(2 * index + 1 , mid + 1 , end , updates[index]) ;
            updates[index] = Update() ;
            lazy[index] = 0 ;
        }
    }
    void apply(int index , int start , int end , Update& u){
        if(start != end){
            lazy[index] = 1 ; // no changes
            updates[index].combine(u , start , end) ; // it is applied on non array elements that is the parent elements on the array elements 
        }
        u.apply(tree[index] , start , end) ; // it is applied on one element only change according to the question 
    }
    void update(int start, int end, int index, int left, int right, Update &u) {  // Never Change this // O(logn) 
        if(start > right || end < left)
            return ;
        if(start >= left && end <= right){
            pushdown(index , start , end) ;
            apply(index , start , end , u) ;
            return ;
        }
        pushdown(index , start , end) ; // doing for both query and updates 
        int mid = (start + end) / 2 ;
        update(start , mid , 2 * index , left , right , u) ;
        update(mid + 1 , end , 2 * index + 1 , left , right , u) ;
        tree[index].merge(tree[2 * index] , tree[2 * index + 1]) ;
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
        if (start > right || end < left)
            return Node(); // warning it is for query answers only what should be the output answer
        if (start >= left && end <= right){
            pushdown(index , start , end) ;
            return tree[index] ;
        }
        pushdown(index , start , end) ; // doing for both query and updates 
        int mid = (start + end) / 2 ;
        Node l , r , ans ;
        l = query(start , mid , 2 * index , left , right) ;
        r = query(mid + 1 , end , 2 * index + 1 , left , right) ;
        ans.merge(l , r) ;
        return ans ;
    }
    void make_update(int left, int right, int val) {  // pass in as many parameters as required
        Update new_update = Update(val) ; // may change
        update(0 , n - 1 , 1 , left , right , new_update) ;
    }
    Node make_query(int left, int right) {
        return query(0 , n - 1 , 1 , left , right) ;
    }
    int first(){
        return tree[1].val ;
    }
    void output(){
        for(int i = 0 ; i < sz ; ++i){
            cout << tree[i].val <<  " " ;
        }
    }
    void output2(){
        for(int i = 0 ; i < sz ; ++i){
            cout << updates[i].val <<  " " ;
        }
    }
};

struct Node1 {
    int val ; // may change
    Node1() { // Identity element
        val = 0 ;    // may change // warning it is for query answers only what should be the output answer 
        // val = power(2 , 30) - 1 ;    // may change
        // val = INF ;    // may change
        // val = -INF ;    // may change
    }
    Node1(int p1) {  // Actual Node
        val = p1 ; // may change
    }
    void merge(Node1 &l , Node1 &r) { // Merge two child nodes
        val = (l.val + r.val) ;  // may change
    }
};

struct Update1 {
    int val ; // may change
    Update1(){ // Identity update
        val = 0 ;
    }
    Update1(int val1) { // Actual Update
        val = val1 ;
    }
    void apply(Node1 &a, int start, int end) { // apply update to given node
        a.val = val * (end - start + 1) ; // may change
        // a.val += val * (end - start + 1) ; // may change
        // a.val = val ; // may change
        // a.val += val ; // may change
    }
    void combine(Update1& new_update , int start , int end){
        val = new_update.val ;
        // val += new_update.val ;
    }
};


/*

How to define our segment tree in the main function
vector<int > arr = {1 , 2 , 3 , 4} ;

LazySGT<Node1 , Update1> LAZY_SEGMENT_TREE = LazySGT<Node1 , Update1 > (n , v) ;

*/