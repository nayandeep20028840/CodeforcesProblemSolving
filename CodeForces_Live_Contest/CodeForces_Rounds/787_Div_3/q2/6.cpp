#include<bits/stdc++.h>
using namespace std;
 
#define ll                long long


void solve(){
    ll n;
    cin>>n;
    int a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll h;
    if(n==1){
        cout<<0<<endl;return;
    }else{
        h=0;
        for(ll i=n-2;i>=0;i--){
            // if(a[i]>=a[i+1]){ // accepted when written.
                while(a[i]>=a[i+1]){
                        if(a[i]==0 ){
                            cout<<"-1"<<endl;return;
                        }
                        a[i]=a[i]/2;
                        h++;   
                       
                    }
                }
            // }
        }
    cout<<h<<endl;
    
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
    int t;
    cin >> t;  // long long int count = 1;

    while (t--){
        //cout << "Case #" << count << ": ";
        solve();
        //count++;
    }

    return 0;
}