#include<bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("O3")
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long

bool solve()
{
    int n;
    cin>>n;
    string ans="";
    int left=0;
    while(ans.size()<n){
        ans+="1";
        cout<<"? "<<ans<<endl;
        int x;
        cin>>x;
        int t=0;
        while(x==0){
            if(left==1){

            }
            else if(t>0){
                if(t>1){
                    string rans="";
                    for(int i=1;i<ans.size();++i){
                        rans+=ans[i];

                    }
                    ans=rans;
                    ans="1"+ans;
                    cout<<"? "<<ans<<endl;
                    cin>>x;
                }
                else{
                    ans.pop_back();
                    ans="0"+ans;
                    cout<<"? "<<ans<<endl;
                    cin>>x;
                }
                t+=1;
                left=1;
            }
            else{
                ans.pop_back();
                ans+="0";
                cout<<"? "<<ans<<endl;
                cin>>x;
                t+=1;
            }
        }
    }
    cout<<"! "<<ans<<endl;
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
        {
            
        }
        else
        {
            
        }
    }
    return 0;
}


