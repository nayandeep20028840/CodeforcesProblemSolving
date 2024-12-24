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
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>a(n);
    vector<int>b(m);
    map<int,int>mp;
    int cnt=1;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mp[a[i]]=cnt;
        a[i]=cnt;
        cnt+=1;
    }
    for(int i=0;i<m;++i){
        cin>>b[i];
        b[i]=mp[b[i]];
    }
    vector<pair<int,int>>p;
    for(int i=0;i<q;++i){
        int x,y;
        cin>>x>>y;
        y=mp[y];
        p.push_back({x,y});
    }
    vector<set<int>>s(n+5);
    s[0].insert(-2);
    s[n+1].insert(m+2);
    s[n+2].insert(m+3);
    for(int i=1;i<=n;++i){
        s[i].insert(m);
        // s[i].insert(m+1);
    }
    for(int i=0;i<m;++i){
        s[b[i]].insert(i);
    }
    set<int>wrong;
    for(int i=2;i<=n;++i){
        if(*s[i].begin()<*s[i-1].begin()){
            wrong.insert(i);
            wrong.insert(i-1);
        }
    }
    if(wrong.size()==0){
        cout<<"YA"<<endl;
    }
    else{
        cout<<"TIDAK"<<endl;
    }
    // cout<<wrong.size()<<endl;
    
    for(int i=0;i<q;++i){
        int prev_para=b[p[i].first-1];
        s[prev_para].erase(s[prev_para].find(p[i].first-1));
        s[p[i].second].insert(p[i].first-1);
        int cur_para=p[i].second;
        b[p[i].first-1]=cur_para;
        // cout<<prev_para<<" "<<cur_para<<endl;
        if(*s[prev_para].begin()>*s[prev_para-1].begin() and *s[prev_para].begin()<*s[prev_para+1].begin()){
            if(wrong.size()>0){
                if(wrong.find(prev_para)!=wrong.end()){
                    wrong.erase(wrong.find(prev_para));
                }
            }
            if(prev_para-1>0){
                if(*s[prev_para-2].begin()<*s[prev_para-1].begin() and *s[prev_para-1].begin()<*s[prev_para].begin()){
                    if(wrong.size()>0){
                        if(wrong.find(prev_para-1)!=wrong.end()){
                            wrong.erase(wrong.find(prev_para-1));
                        }
                    }
                }
                else{
                    if(prev_para-1>=1 and prev_para-1<=m) wrong.insert(prev_para-1);
                }
            }
            else{
                if(wrong.size()>0){
                    if(wrong.find(prev_para-1)!=wrong.end()){
                        wrong.erase(wrong.find(prev_para-1));
                    }
                }
            }
            if(prev_para+1<=m){
                if(*s[prev_para].begin()<*s[prev_para+1].begin() and *s[prev_para+1].begin()<*s[prev_para+2].begin()){
                    if(wrong.size()>0){
                        if(wrong.find(prev_para+1)!=wrong.end()){
                            wrong.erase(wrong.find(prev_para+1));
                        }
                    }
                }
                else{
                    if(prev_para+1>=1 and prev_para+1<=m) wrong.insert(prev_para+1);
                }
            }
            else{
                if(wrong.size()>0){
                    if(wrong.find(prev_para+1)!=wrong.end()){
                        wrong.erase(wrong.find(prev_para+1));
                    }
                }
            }
        }
        else{
            if(prev_para>=1 and prev_para<=m) wrong.insert(prev_para);
            if(prev_para-1>0){
                if(*s[prev_para-2].begin()<*s[prev_para-1].begin() and *s[prev_para-1].begin()<*s[prev_para].begin()){
                    if(wrong.size()>0){
                        if(wrong.find(prev_para-1)!=wrong.end()){
                            wrong.erase(wrong.find(prev_para-1));
                        }
                    }
                }
                else{
                    if(prev_para-1>=1 and prev_para-1<=m) wrong.insert(prev_para-1);
                }
            }
            else{
                if(wrong.size()>0){
                    if(wrong.find(prev_para-1)!=wrong.end()){
                        wrong.erase(wrong.find(prev_para-1));
                    }
                }
            }
            if(prev_para+1<=m){
                if(*s[prev_para].begin()<*s[prev_para+1].begin() and *s[prev_para+1].begin()<*s[prev_para+2].begin()){
                    if(wrong.size()>0){
                        if(wrong.find(prev_para+1)!=wrong.end()){
                            wrong.erase(wrong.find(prev_para+1));
                        }
                    }
                }
                else{
                    if(prev_para+1>=1 and prev_para+1<=m) wrong.insert(prev_para+1);
                }
            }
            else{
                if(wrong.size()>0){
                    if(wrong.find(prev_para+1)!=wrong.end()){
                        wrong.erase(wrong.find(prev_para+1));
                    }
                }
            }
        }
        if(*s[cur_para].begin()>*s[cur_para-1].begin() and *s[cur_para].begin()<*s[cur_para+1].begin()){
            if(wrong.size()>0){
                if(wrong.find(cur_para)!=wrong.end()){
                    wrong.erase(wrong.find(cur_para));
                }
            }
            if(cur_para-1>0){
                if(*s[cur_para-2].begin()<*s[cur_para-1].begin() and *s[cur_para-1].begin()<*s[cur_para].begin()){
                    if(wrong.size()>0){
                        if(wrong.find(cur_para-1)!=wrong.end()){
                            wrong.erase(wrong.find(cur_para-1));
                        }
                    }
                }
                else{
                    if(cur_para-1>=1 and cur_para-1<=m) wrong.insert(cur_para-1);
                }
            }
            else{
                if(wrong.size()>0){
                    if(wrong.find(cur_para-1)!=wrong.end()){
                        wrong.erase(wrong.find(cur_para-1));
                    }
                }
            }
            if(cur_para+1<=m){
                if(*s[cur_para].begin()<*s[cur_para+1].begin() and *s[cur_para+1].begin()<*s[cur_para+2].begin()){
                    if(wrong.size()>0){
                        if(wrong.find(cur_para+1)!=wrong.end()){
                            wrong.erase(wrong.find(cur_para+1));
                        }
                    }
                }
                else{
                    if(cur_para+1>=1 and cur_para+1<=m) wrong.insert(cur_para+1);
                }
            }
            else{
                if(wrong.size()>0){
                    if(wrong.find(cur_para+1)!=wrong.end()){
                        wrong.erase(wrong.find(cur_para+1));
                    }
                }
            }
        }
        else{
            if(cur_para>=1 and cur_para<=m) wrong.insert(cur_para);
            if(cur_para-1>0){
                if(*s[cur_para-2].begin()<*s[cur_para-1].begin() and *s[cur_para-1].begin()<*s[cur_para].begin()){
                    if(wrong.size()>0){
                        if(wrong.find(cur_para-1)!=wrong.end()){
                            wrong.erase(wrong.find(cur_para-1));
                        }
                    }
                }
                else{
                    if(cur_para-1>=1 and cur_para-1<=m) wrong.insert(cur_para-1);
                }
            }
            else{
                if(wrong.size()>0){
                    if(wrong.find(cur_para-1)!=wrong.end()){
                        wrong.erase(wrong.find(cur_para-1));
                    }
                }
            }
            if(cur_para+1<=m){
                if(*s[cur_para].begin()<*s[cur_para+1].begin() and *s[cur_para+1].begin()<*s[cur_para+2].begin()){
                    if(wrong.size()>0){
                        if(wrong.find(cur_para+1)!=wrong.end()){
                            wrong.erase(wrong.find(cur_para+1));
                        }
                    }
                }
                else{
                    if(cur_para+1>=1 and cur_para+1<=m) wrong.insert(cur_para+1);
                }
            }
            else{
                if(wrong.size()>0){
                    if(wrong.find(cur_para+1)!=wrong.end()){
                        wrong.erase(wrong.find(cur_para+1));
                    }
                }
            }
        }
        cout<<wrong.size()<<endl;
        if(wrong.size()<=0){
            cout<<"YA"<<endl;
        }
        else{
            cout<<"TIDAK"<<endl;
        }
    }
    // cout<<endl;
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

