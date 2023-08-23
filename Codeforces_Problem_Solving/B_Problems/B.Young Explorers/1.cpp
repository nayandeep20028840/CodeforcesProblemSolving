#include<bits/stdc++.h>

using namespace std;



#define MAX 10000
#define INF 1e100
#define isset(n,i) ((n>>i)&1LL)

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define sor(A) sort(A.begin(),A.end())
#define rsor(A) sort(A.rbegin(),A.rend())
#define all(A) A.begin(),A.end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef pair<long long ,int> pli;
#define VI  vector<int>
#define VLL  vector<long long>
#define VVI vector<vector<int>>
#define VS  vector<string>
#define VVS vector<vector<string>>
#define X first
#define Y second



#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}



//BEGINTEMPLATE_BY_ACRUSH_TOPCODER

#define SZ(X) ((int)(X.size()))//NOTES:SIZE(

#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(

#define two(X) (1<<(X))//NOTES:two(

#define twoL(X) (((unsigned long long)(1))<<(X))//NOTES:twoL(

#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(

#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(

const double pi=acos(-1.0);//NOTES:pi

const double eps=1e-11;//NOTES:eps

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(

template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(

template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr

template<class T> inline string bin(T n,int pos=62) { string s; T i,one=1,two=2; for (i = (one << (pos-1)); i > 0; i = (i>>1) ) s += ((n & i)?"1":"0"); return s; }


int lsb(unsigned int v){
	int r;           // result goes here
	static const int MultiplyDeBruijnBitPosition[32] =
	{
	  0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
	  31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
	};
	r = MultiplyDeBruijnBitPosition[((uint32_t)((v & -v) * 0x077CB531U)) >> 27];
	return r+1;
}


template<class T> inline int msb(T n){return (n==0)?0:(1+msb(n>>1));}//NOTES:msb(
template<class T> inline T getbit(T n,int pos){return ((n&(1<<pos))?1:0);}//NOTES:getbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline void setbit(T &n,int p){ n = n | (1LL<<p); }


// Can also use popcount for CPU access
// int  __builtin_popcount(unsigned int)
// int  __builtin_popcountll(long long)

//Numberic Functions

template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

bool isequal(vector<int> a,vector<int> b){
	REP(i,a.size()) if(a[i]!=b[i]) return false;
	return true;
}

template<class T>
bool allequal(vector<T> a){
	sor(a);
	return a[0]==a[a.size()-1];
}



template<class T1,class T2>
void printpairs(vector< pair<T1,T2> > p){
    for(auto t:p){
        cout << "(" << t.first << " " << t.second << ")  ";
    }
    cout << endl;
}


template<class T>
void printvec(vector<T> a){
	REP(i,a.size())cout << a[i] << " ";
	cout<< endl;
}

void printarray(int *a,int n){
	REP(i,n)cout << *(a+i) << " ";
	cout<< endl;
}



template<typename T>
void printmatrix(vector< vector<T> > a,int n,int m,int width=5){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << setw(width) << a[i][j] ;
		}
		cout << endl;
	}
}


template<typename T>
void readmatrix(vector< vector<T> > &a,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
}


template<class T>
void printsubarray(vector<T> a,int start ,int end){
	if(start<0 or end>a.size()-1) cout << "Out of bounds" << endl;
	for(int i=start;i<=end;i++)cout << a[i] << " ";
	cout<< endl;
}

bool isprime(int n){
	if(n<2) return false;
	if(n==2) return true;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}


// Error checking

#define error(args...) { vector<string> _v; split(#args, ',', _v); err(_v.begin(), args); cerr<< endl; }

void split(const string& s, char c, vector<string>& result) {
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        result.push_back(x);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ' ';
    err(++it, args...);
}


/*
vector<vector<ll>> a(n, vector<ll>(m,0) );
readmatrix(a,n,m);
printmatrix(a,n,m);
*/

void yup(){ cout << "Yes" << endl; }
void nope(){ cout << "No" << endl; }
void Yup(){ cout << "YES" << endl; }
void Nope(){ cout << "NO" << endl; }




template<typename T>
void readvec(vector<T>& a,int size){
	T tmp;
	a.clear();
	REP(i,size){
		cin>>tmp;
		a.push_back(tmp);
	}
}

//ENDTEMPLATE_BY_ACRUSH_TOPCODER

void solvecase(){
    int n;
    VI a;
    cin >> n;
    readvec(a,n);
    sor(a);
    VI d(n+2,0);
    for(int i=0;i<n;i++){
        if(i+1-a[i]>=0)
            d[i+1] = max( d[i] , d[i+1-a[i]] + 1 );
        else
            d[i+1] = d[i];
    }
    for(int i = 0 ; i < n + 1 ; ++i){
        cout << d[i] << " " ;
    }
    cout << endl ;
    cout << d[n] << endl;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cases=1;
  cin >> cases;
  while(cases--){
	  solvecase();
  }
  return 0;
}










