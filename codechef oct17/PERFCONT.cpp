#include<iostream>
using namespace std;
int main(){
	int t,n,i,c1,k,c2;
	long long int p;
	cin>>t;
	while(t--){
		cin>>n>>p;
		int a[n];
		c1=0,c2=0;
		for(i=0;i<n;i++){
			cin>>a[i];
			if(a[i]<=(p/10))
			c1+=1;
			if(a[i]>=p/2)
			c2+=1;
		}
		if(c1==2&&c2==1)
		cout<<"yes"<<endl;
		else 
		cout<<"no"<<endl;
	}
	return 0;
} 
