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
    int n,q;
    cin>>n>>q;
    vector<string>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int>BG;
    vector<int>BR;
    vector<int>BY;
    vector<int>GR;
    vector<int>GY;
    vector<int>RY;
    for(int i=0;i<n;++i){
        if(a[i]=="BG") BG.push_back(i);
        if(a[i]=="BR") BR.push_back(i);
        if(a[i]=="BY") BY.push_back(i);
        if(a[i]=="GR") GR.push_back(i);
        if(a[i]=="GY") GY.push_back(i);
        if(a[i]=="RY") RY.push_back(i);
    }
    // cout<<("BR"<"GY")<<endl;
    while(q--){
        int x,y;
        cin>>x>>y;
        x-=1;
        y-=1;
        string ft=a[x];
        string se=a[y];
        if(ft>se) swap(ft,se);
        if(x>y) swap(x,y);
        int ans=1e9;
        // cout<<ft<<" "<<se<<endl;
        if(ft=="BG" and se=="RY"){
            // search BR,BY,GR,GY
            if(BR.size()>0){
                auto it=upper_bound(BR.begin(),BR.end(),x)-BR.begin();
                if(it==BR.size()){
                    int idx=BR[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=BR[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=BR[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=BR[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(BY.size()>0){
                auto it=upper_bound(BY.begin(),BY.end(),x)-BY.begin();
                if(it==BY.size()){
                    int idx=BY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=BY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=BY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=BY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(GR.size()>0){
                auto it=upper_bound(GR.begin(),GR.end(),x)-GR.begin();
                if(it==GR.size()){
                    int idx=GR[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=GR[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=GR[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=GR[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(GY.size()>0){
                auto it=upper_bound(GY.begin(),GY.end(),x)-GY.begin();
                if(it==GY.size()){
                    int idx=GY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=GY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=GY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=GY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
        }
        else if(ft=="BR" and se=="GY"){
            // search BG,BY,GR,RY
            if(BG.size()>0){
                auto it=upper_bound(BG.begin(),BG.end(),x)-BG.begin();
                if(it==BG.size()){
                    int idx=BG[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=BG[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=BG[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=BG[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(BY.size()>0){
                auto it=upper_bound(BY.begin(),BY.end(),x)-BY.begin();
                if(it==BY.size()){
                    int idx=BY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=BY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=BY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=BY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(GR.size()>0){
                auto it=upper_bound(GR.begin(),GR.end(),x)-GR.begin();
                if(it==GR.size()){
                    int idx=GR[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=GR[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=GR[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=GR[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(RY.size()>0){
                auto it=upper_bound(RY.begin(),RY.end(),x)-RY.begin();
                if(it==RY.size()){
                    int idx=RY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=RY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=RY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=RY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
        }
        else if(ft=="BY" and se=="GR"){
            // search BG,BR,GY,RY
            if(BG.size()>0){
                auto it=upper_bound(BG.begin(),BG.end(),x)-BG.begin();
                if(it==BG.size()){
                    int idx=BG[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=BG[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=BG[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=BG[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(BR.size()>0){
                auto it=upper_bound(BR.begin(),BR.end(),x)-BR.begin();
                if(it==BR.size()){
                    int idx=BR[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=BR[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=BR[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=BR[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(GY.size()>0){
                auto it=upper_bound(GY.begin(),GY.end(),x)-GY.begin();
                if(it==GY.size()){
                    int idx=GY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=GY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=GY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=GY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
            if(RY.size()>0){
                auto it=upper_bound(RY.begin(),RY.end(),x)-RY.begin();
                if(it==RY.size()){
                    int idx=RY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else if(it==0){
                    int idx=RY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
                else{
                    int idx=RY[it];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                    idx=RY[it-1];
                    ans=min(ans,abs(idx-x)+abs(idx-y));
                }
            }
        }
        else{
            ans=min(ans,abs(y-x));
        }
        if(ans==1e9) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
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


