#include <bits/stdc++.h>

using namespace std;

signed main(signed argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(atoi(argv[1]));

//     // generate test cases with same format as given in problem
    int t = 20;
    cout << t << endl;
    while(t--){
        // int n = rand() % 10 + 1 ;    
        // int m = rand() % 10 + 1 ;
        // int k = rand() % 10 + 1 ;
        // cout << n << " " << m << " " << k << '\n';
        int n = rand() % 20 + 1;
        cout << n << endl;
        for(int i = 0 ; i < n ; ++i){
            cout << rand() % 2000000  << " ";
        }
        cout << endl;
    }
    return 0;
}

