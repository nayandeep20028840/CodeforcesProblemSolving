#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int t=s.length();
        if(t>10){
            cout << s[0] << t-2 << s[t-1] << endl;
        }else{
            cout << s << endl;
        }
    }
}