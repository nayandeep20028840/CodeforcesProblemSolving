#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; 
using namespace __gnu_pbds;
// #pragma GCC optimize("O3")
// #pragma GCC optimize(3, "Ofast", "inline")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
// Policy based data structures(PBDS) C++ STL
// find_by_order(k): returns the iterator of the k-th element in a set (0-index)
// order_of_key(k): returns count of elements strictly smaller than k 
// Time complexity: O(logn) for both
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
template<class T > using pbds_SET = tree< T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_SET<pair<int , int > > s; for pairs
template<class T > using pbds_MULTISET = tree< T , null_type , less_equal<T>, rb_tree_tag, tree_order_statistics_node_update > ; // here T can be anything like pair,vector,map,pair_of_pair // USE it like Tree_MULTISET<pair<int , int > > s; for pairs

bool solve()
{
    int n,k;
    cin>>n>>k;
    int t=k;
    map<vector<int>,int>mp;
    vector<int>p;
    for(int i=0;i<n;++i){
        p.push_back(i+1);
    }
    if(k==1){
        for(int i=0;i<n;++i){
            cout<<p[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    int cnt=0;
    k-=1;
    while(k>0){
        cnt+=1;
        k/=2;
    }
    if(cnt>=n){
        cout<<-1<<endl;
        return true;
    }
    k=t;
    pbds_MULTISET<int>ms;
    for(int i=n;i>=n-cnt;--i){
        ms.insert(i);
    }
    // cout<<cnt<<" ";
    for(int i=n-cnt-1;i<n;++i){
        int val=0;
        int ok=n-(i+1)-1;
        ok=max(ok,0ll);
        int two=(1ll<<ok);
        int t2=(1ll<<ok);
        int kk=k;
        // cout<<ok<<" "<<two<<" "<<endl;
        if(kk<=two || ok<0){
            p[i]=*(ms.find_by_order(0));
            ms.erase(ms.find_by_order(0));
            continue;
        }
        while(kk>0){
            kk-=two;
            val+=1;
            // if(two==0) break;
            two/=2;
            if(two==0) two=1;
        }
        // cout<<*(ms.find_by_order(val-1))<<" ";
        p[i]=*(ms.find_by_order(val-1));
        ms.erase(ms.find_by_order(val-1));
        k-=t2;
    }
    for(int i=0;i<n;++i){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
        {
            
        }
        else
        {
            
        }
    }
    return 0;
}


