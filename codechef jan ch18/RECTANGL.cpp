#include<bits/stdc++.h>
using namespace  std;
int main(){
int t,a,b,i;
cin>>t;
int arr[4];
while(t--){
a=0;b=0;
for(i=0;i<4;i++)
cin>>arr[i];
for(i=0;i<4;i++){
if(a==0)a=arr[0];
else if(b==arr[i]) b=-1;
else if(a==arr[i]) a=-1;
else  b=arr[i];
}
if(a==-1&&b==-1)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
return 0;
}
