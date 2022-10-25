#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
 
#define ll                long long
#define all(v)            v.begin(),v.end()
#define pb                push_back
#define popb              pop_back
#define pf                push_front
#define popf              pop_front
#define lb                lower_bound
#define ub                upper_bound
#define pii               pair<int,int>
#define bpp               __builtin_popcount
#define Pi                3.1415926535897932384626
 
 
long long power(long long int a, long long int n)
{
if (n == 0)return 1; if (n % 2 == 0) {long long val = power(a, n / 2); val = (val * val); return val;}
else {long long val = power(a, n / 2); val = ((val * val) * a) ; return val;}
}
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
 
bool checkpalindrome(ll i){  // check palindrome number in n/2 time complexity
    string s=to_string(i);
    bool flag=0;
    int n=s.length();
    for (ll i=0;i<n;i++){
        if (s[i]!=s[n-1-i]){
            flag=1;
            break;
        }
    }
    if(flag){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    ll a;
    cin >> a;
    for(ll i = 0; i <= 10; i+=2){
        ll max = 1 << (i+1);
        for(ll mask = 0; mask < max; ++mask){
            ll x = 0;
            ll r = 1;
            ll n4, n7;
            n4 = n7 = 0; 
            for(ll j = 0; j < i; ++j){
                if((mask & (1 << j))){
                    x += r*7;
                    ++n7;
                }else{
                    x += r*4;
                    ++n4;
                }
                r *= 10;
            }
            if(n4 == n7){
                if(x >= a){
                    cout << x << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}