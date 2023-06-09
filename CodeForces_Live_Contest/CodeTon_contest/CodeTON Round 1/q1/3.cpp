#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--){
        int n,a[n],b[n],c[n];
        cin >> n;
        int i,j,k;
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        for(j=0;j<n;j++){
            cin >> b[j];
        }
        for(k=0;k<n;k++){
            cin >> c[k];
        }
        if(abs((a[i]-a[k])+abs(a[k]-a[j])==abs(a[i]-a[j]))){
            cout << i << j;
        }
    }
}