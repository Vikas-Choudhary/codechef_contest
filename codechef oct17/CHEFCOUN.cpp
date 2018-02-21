#include <bits/stdc++.h>
using namespace std;
int main(){
	long int k,n,t,a,r,i,l,m,sum,extra;
	cin>>t;
    sum=0,extra=0;
	long int N=2*4294967295;
    long int arr[100000];
	while(t--){
		cin>>n;
		i=n*(n+1)*0.5;
		a=(N-i-1)/(n+1);
		r=N-(n+1)*a-1-i;
        if(r%2==0)
            k=r/2;
        else
            k=1+r/2;
        for(l=0;l<n;l++){
            arr[l]=a+l+1;
            sum+=arr[l];
	        }
          for(m=0;m<n;m++){
            if(arr[n-1-m]>100000){
                extra=arr[n-1-m]-100000;
                arr[3+m]+=extra;
                arr[n-1-m]=100000;
            } 
        }
        sum=0;
        arr[1]+=k;
        arr[2]+=r-k;
        for(m=0;m<n-1;m++){
           cout<<arr[m]<<" ";
        }
        cout<<arr[n-1]<<endl;
    }
	return 0;
} 
