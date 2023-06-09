#include <iostream>
using namespace std;
int smallest_digit(int n) {
   int min = n % 10; 
   n /= 10; 
   while (n != 0) {
      if (min > n % 10)
         min = n % 10;
      n /= 10;
   }
   cout<<min<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
   int n ;
   cin>>n;
   if(n>=10 && n<100){
       cout<<n%10<<endl;
   }
   else
    smallest_digit(n);
//    return 0;
    }
}