#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            cout << "1+" ;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='2'){
            cout << "2+" ;
        }
    }
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='3'){
            count++;
        }
        
    }
    for(int j=1;j<count;j++){
        cout << "3+" ;
    }
    cout << "3" << endl;

    
}