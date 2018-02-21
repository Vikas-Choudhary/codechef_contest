#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,ans,c,i,p,j;
    long int n,k;
	long int a[200000],b[200000];
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(p=0;p<n+k+2;p++)
        b[p]=0;    
		c=0;
		ans=-1;
		for(i=0;i<n;i++){
			cin>>a[i];
	 	    c=a[i];
			b[c]=1;
		}
        c=k;
	    for(j=0;j<n+c+1;j++){
	    	if((b[j]==0)&&(k==0)){
		    ans=j;
		    k--;
		    }    
	    	if((b[j]==0)&&(k>=1))
            k--;
    	}
	
		/*for(p=0;p<n;p++){
			cout<<a[p];
		}
		for(q=0;q<a[n-1]+2;q++){
			cout<<b[q];
		}*/
		cout<<ans<<endl;	
	} 
	return 0;
}
