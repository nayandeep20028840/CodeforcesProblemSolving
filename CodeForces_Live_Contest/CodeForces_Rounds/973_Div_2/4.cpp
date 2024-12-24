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
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    set<int>s;
    map<int,int>mp;
    s.insert(a[n-1]);
    mp[a[n-1]]+=1;
    for(int i=n-2;i>=0;--i){
        if(a[i]>*s.begin()){
            if(s.size()==1){
                int times=mp[*s.begin()];
                int val=times*(*s.begin());
                int tot=a[i]+val;
                int rem=tot%(n-i);
                if(rem!=0){
                    int mult=tot/(n-i);
                    mp[mult+1]=rem;
                    mp[mult]=(n-i)-rem;
                    s.erase(s.begin());
                    s.insert(mult+1);
                    s.insert(mult);
                }
                else{
                    int mult=tot/(n-i);
                    mp.erase(*s.begin());
                    mp[mult]=(n-i);
                    s.erase(s.begin());
                    s.insert(mult);
                }
            }
            else{
                int val=a[i];
                while(val>*s.begin()){
                    int val1=*s.begin();
                    s.erase(s.begin());
                    int val2=*s.begin();
                    int low=val1;
                    int high=val2+1;
                    int times=mp[val1];
                    while(high-low>1){
                        int mid=(low+high)/2;
                        int val3=(mid-val1)*times;
                        if(val-val3>=mid){
                            low=mid;
                        }
                        else{
                            high=mid;
                        }
                    }
                    int have=(low-val1)*times;
                    val-=have;
                    mp.erase(val1);
                    mp[low]+=times;
                    s.insert(low);
                    if(s.size()==1){
                        times=mp[*s.begin()];
                        int val4=times*(*s.begin());
                        int tot=val+val4;
                        int rem=tot%(n-i);
                        if(rem!=0){
                            int mult=tot/(n-i);
                            mp[mult+1]=rem;
                            mp[mult]=(n-i)-rem;
                            s.erase(s.begin());
                            s.insert(mult+1);
                            s.insert(mult);
                        }
                        else{
                            int mult=tot/(n-i);
                            mp.erase(*s.begin());
                            mp[mult]=(n-i);
                            s.erase(s.begin());
                            s.insert(mult);
                        }
                        val=*s.begin();
                        mp[val]-=1;
                        break;
                    }
                    if(low==val1) break;
                }
                int ex=val-(*s.begin());
                // if(ex!=0){
                    mp[*s.begin()]-=ex;
                    mp[*s.begin()+1]+=ex;
                    s.insert(*s.begin());
                    s.insert(*s.begin()+1);
                    val-=ex;
                    mp[val]+=1;
                // }
                // else{
                //     mp[val]+=1;
                // }
            }
        }
        else{
            mp[a[i]]+=1;
            s.insert(a[i]);
        }
    }
    cout<<(*s.rbegin())-(*s.begin())<<endl;
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


