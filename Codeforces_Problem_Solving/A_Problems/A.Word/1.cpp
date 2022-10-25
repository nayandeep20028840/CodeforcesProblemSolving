#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s{}, new_s{};
    int upper_case{}, lower_case{};
    cin >> s;
    for(int i=0;i<s.length();i++){
        if (isupper(s[i])){
            upper_case ++;
        }else{
            lower_case ++;
        }
    }
    if (upper_case>lower_case){
        for (int i=0;i<s.length();i++){
            new_s += toupper(s[i]);
        }
    }else{
        for (int i = 0; i < s.length(); i++){
            new_s += tolower(s[i]);
        }
    }
    cout << new_s;
}