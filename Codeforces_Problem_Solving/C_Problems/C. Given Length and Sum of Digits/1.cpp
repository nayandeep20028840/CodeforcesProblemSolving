#include<bits/stdc++.h>
using namespace std;
 
const long long int mod97 = 1000000007;
const long long int modg = 998244353;
const long long int inf = 1e18;
 
#define ll                long long
#define ld                long double
#define mp                make_pair
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define lb                lower_bound
#define ub                upper_bound
#define ts                to_string
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(dp)          memset(dp,-1,sizeof(dp))
#define bpp               __builtin_popcount
#define bppll             __builtin_popcountll
#define Pi                3.1415926535897932384626
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
char convertIntToChar(int num) {
    char ch = 'a'+num;
    return ch;
}
 
void binaryform(int num){
    for (int i = 10;i >= 0;--i){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
 
void left_right_shift(int num){
    cout << (num>>1) << endl; //if num=5(101) it will return 2(10)
    cout << (num<<1) << endl; //if num=5(101) it will return 10(1010)
}

int binaryTodecimal(string n)
{
    string num = n;
    int decimal_value = 0;
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--){
        if (num[i] == '1'){
            decimal_value += base;
        }
        base = base * 2;
    }
    return decimal_value;
}
 
const int N = 1e5 + 4;
const int M = 1e9 + 7;
 
int main(){
    int m,s;
    cin>>m>>s;
    if(m==1&&s==0)
	{
		cout<<"0 0";
		return 0;
	}
    if(s==1)
	{
		cout<<1;
        for(int i=0;i<m-1;i++){
            cout<<0;
        }
        cout<<" ";
        cout<<1;
        for(int i=0;i<m-1;i++){
            cout<<0;
        }
        cout<<endl;
        return 0;
	}
    if(s==m && s%10!=0 )
	{
        cout<<1;
		for(int i=0;i<m-2;i++){
            cout<<0;
        }
        cout<<s-1;
        cout<<" ";
        cout<<s;
        for(int i=0;i<m-1;i++){
            cout<<0;
        }
        cout<<endl;
        return 0;
	}
    if(s==0){
        cout<<"-1 -1"<<endl;
    }
    else if(s<m){
        cout<<1;
        if(m>2)
        for(int i=0;i<=m-2-1;i++){
            cout<<0;
        }
        // }else{
        //     for(int i=0;i<=m-2;i++){
        //     cout<<0;
        // }

        // }
        // for(int i=1;i<=m-s;i++){
        //     cout<<0;
        // }
        cout<<1;
        cout<<" ";
        cout<<s;
        for(int i=0;i<=m-s;i++){
            cout<<0;
        }
        cout<<endl;
    }
    else if(s>(9*m)){
        cout<<"-1 -1"<<endl;
    }else{
        if(m==1){
            // int sum =0;
            // while(s){
            //     sum = sum + s%10;
            //     s = s/10;
            // }
            cout<<s<<" "<<s<<endl;
        }
        if(m==2){
            if(s<=9){
                cout<<1<<s-1<<" "<<s<<0<<endl;return 0;
            }
            cout<<s-9<<9<<" "<<9<<s-9<<endl;
        }
        string s1="";
        int s3=s;
        if(m>2){
            if(s%9==0){
                cout<<1;
		        for(int i=0;i<m-2;i++){
                    cout<<0;
                }
                cout<<s-1;
                cout<<" ";
                cout<<s;
                for(int i=0;i<m-1;i++){
                    cout<<0;
                }
                cout<<endl;
                return 0;

            }
            if((s%10)==0){
                cout<<s/10;
                int c=0;
                while(s>1){
                    c++;
                    s=s-9;
                }
                for(int i=0;i<m-c-1;i++){
                    cout<<0;
                }
                for(int i=0;i<c;i++){
                    cout<<9;
                }
                cout<<endl;
                // cout<<s1<<" ";
                // reverse(s1.begin(), s1.end());
                // cout<<s1<<" ";
                while(s3>1){
                    cout<<9;
                    s3=s3-9;
                }
                cout<<1;
                for(int i=0;i<m-c-1;i++){
                    cout<<0;
                }
                cout<<endl;
            }else{
                for(int i=0;i<m-2;i++){
                    s1=s1+'1';
                    s= s-1;
                    s3=s3+'1';
                }
                // if(s==9){
                //     int t = s-1;
                //     s1=s1+'1';
                //     s1 += to_string(t);
                //     cout<<s1<<" ";
                //     s3 += to_string(t);
                //     s3=s3+'1';
                //     cout<<s3<<endl;
                //     return 0;
                    
    
    
                // }
                if(s<9){
                    int t = s-1;
                    s1=s1+'1';
                    s1 += to_string(t);
                }else{
                    int t = s-9;
                    s1 += to_string(t);
                    s1=s1+'9';
                }
                // reverse(s1.begin(), s1.end());
                cout<<s1<<" ";
                reverse(s1.begin(), s1.end());
                cout<<s1<<endl;
            }
        }
    }
}
 