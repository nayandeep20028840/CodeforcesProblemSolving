#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin >> n >> m;
    string s;
    vector<int,int> m1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[j]=='*'){
                m1[i+1]++;
            }
        }
    }
    for(auto i:m1){
        if(i.second==1){
            cout<<i.first<<" ";
        }
    }
    vector<int,int>m2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]=='*'){
                m1[j+1]++;
            }
        }
    }
    for(auto j:m1){
        if(j.second==1){
            cout<<j.first<<" ";
        }
    }
    return 0;
}