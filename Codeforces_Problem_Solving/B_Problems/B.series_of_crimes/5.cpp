#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
    char a[n][m];
    vector<pair<int,int>> b;
    map<int,int> mm;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='*'){
                mm[i+1]++;
            }
        }
    }
    for(auto i:mm){
        if(i.second==1){
            cout<<i.first<<" ";
        }
    }
     map<int,int> mmm;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='*'){
                mmm[j+1]++;
            }
        }
    }
    for(auto i:mmm){
        if(i.second==1){
            cout<<i.first<<" ";
        }
    }
}