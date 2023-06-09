#include<bits/stdc++.h>
#define ll  long long int
using namespace std;
int main()
{
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
     int x,h=0;
     cin>>x;
 
     string v;
    cin>>v;
    for(int k=1;k<v.size();k++)
    {if(v[k]=='1'&&v[k-1]=='0'&&v[k+1]=='0')
    {h++;
 
    }
    if(v[k]=='0'&&v[k-1]=='0')
    {
        h=h+2;
    }
    }
    cout<<h<<"\n";
    }
    }