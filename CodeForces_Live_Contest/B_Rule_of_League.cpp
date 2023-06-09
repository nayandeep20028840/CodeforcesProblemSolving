#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , x , y ;
        cin >> n >> x >> y ;
        int t = 0;
        int t1 = 1;
        int nn = n;
        if((n - 1) == x &&( y == 0) || ((n - 1) == y  && x == 0) ){
            for(int i = 0 ; i < n - 1 ; ++i){
                cout << 1 << " ";
            }
            cout << '\n';
        }
        else if(x > 0 &&( y == 0)){
            if(((n - 1) % x) == 0 &&(( y == 0))){
                for(int i = 0 ; i < n - 1 ; ++i){
                    if(t < x){
                        cout << t1 << " ";
                        t++;
                    }else{
                        t1 = t1 + x + 1;
                        cout << t1 << " ";
                        t = 0;
                    }
                }
                cout << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        else if(y > 0 && x == 0){
            if(((n - 1) % y) == 0 && x == 0){
                t = 0;
                t1 = 1;
                for(int i = 0 ; i < n - 1 ; ++i){
                    if(t < y){
                        cout << t1 << " ";
                        t++;
                    }else{
                        t1 = t1 + y + 1;
                        cout << t1 << " ";
                        t = 0;
                    }
                }
                cout << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        else{
            cout << -1 << '\n';
        }
    }
}