#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    int c3=0;
    while(t--){
        int a[3];
        for(int i=0;i<3;i++){
            cin >> a[i];
        }
        int c1=0,c0=0;
        
        for(int i=0;i<3;i++){
            if(a[i]==1){
                c1++;
            }else{
                c0++;
            }
        }
        if(c1>=2){
            c3++;
        }
    }
    cout << c3 << endl;
}