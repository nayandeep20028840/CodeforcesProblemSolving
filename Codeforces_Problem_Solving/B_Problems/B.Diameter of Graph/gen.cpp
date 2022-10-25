#include <bits/stdc++.h>

using namespace std;

signed main(signed argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(atoi(argv[1]));

//     // generate test cases with same format as given in problem
    int t = 5;
    while(--t){
        int n = rand() % 10 + 1 ;    
        int m = rand() % 10 + 1 ;
        int k = rand() % 10 + 1 ;
        cout << n << " " << m << " " << k << '\n';
//     // for(int i = 0 ; i < n ; ++i){
//     //     for(int j = 0 ; j < m ; ++j){
//     //         // cout << rand() % 10 ;
//     //     }
//     //     cout << '\n';
//     // }
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int rnd(int a, int b , int c){
//     // return a + rand() % (b - a + 1);
//     cout << rand() % a , " " , rand() % b , " " , rand() % c << '\n';
// }
// int main() {
//     int w = rnd(1, 100 , 100);
//     cout<<w<<endl;
// }