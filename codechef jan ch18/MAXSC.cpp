#include<bits/stdc++.h>
#define ll long long
using namespace  std;
int main(){
int t;
cin>>t;
while(t--){
        ll int i,j,N,ans=0,sum=0;
        cin>>N;
    ll int a[N][N];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        cin>>a[i][j];
     sort(a[i],a[i]+N);
    }

    for(i=N-1;i>=0;i--){
    if(i==N-1){sum=a[N-1][N-1];ans=sum;}
    else if(i<N-1 && ans>=0){
            j=N-1;
        while(a[i][j]>=ans && j>0){
            j-=1;
            if(j==0 && a[i][j]>=ans)
                ans=-1;
        }
        if(ans!=-1)
        {sum+=a[i][j];ans=a[i][j];}
    }
}
if(ans==-1)
    cout<<"-1"<<endl;
else
    cout<<sum<<endl;
}
return 0;
}
