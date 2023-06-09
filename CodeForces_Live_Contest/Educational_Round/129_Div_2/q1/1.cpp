#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int m;
        cin>>m;
        vector<int>v1(m);
        for(int i=0;i<m;i++){
            cin>>v1[i];
        }
        sort(v1.begin(),v1.end());
        sort(v.begin(),v.end());
        if(v[n-1]>=v1[m-1]){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
        if(v1[m-1]>=v[n-1]){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
    }
 
    return 0;
}