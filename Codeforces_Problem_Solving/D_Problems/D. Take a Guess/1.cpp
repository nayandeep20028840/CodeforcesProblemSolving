#include<bits/stdc++.h> 
using namespace std; 

int query_or(int x , int y){
    int res;
    cout << "or " << x << " " << y << endl ;
    cin >> res;
    return res;
}
int query_and(int x , int y){
    int res;
    cout << "and " << x << " " << y << endl ;
    cin >> res;
    return res;
}

int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int > ans ;
    vector<int > AND;
    vector<int > OR;
    for(int i = 2 ; i <= n ; ++i){
        OR.push_back(query_or(1 , i));
        AND.push_back(query_and(1 , i));
    }
    int a23_2 = query_or(2 , 3);
    int a23 = query_and(2 , 3);
    int one = ((OR[0] & OR[1])) - a23 + ((AND[0] & AND[1]));
    ans.push_back(one);
    for(int i = 1 ; i < n ; ++i){
        int val = (OR[i - 1] ^ one) + AND[i - 1];
        ans.push_back(val);
    }
    sort(ans.begin() , ans.end());
    cout << "finish " << ans[k-1] << endl;
    return 0 ;
}




