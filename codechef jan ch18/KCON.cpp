#include<bits/stdc++.h>
using namespace  std;
#define ll long long
int msa(ll int a[], ll int size)
{
    ll int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (ll int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main(){
int t;
cin>>t;
while(t--){
        ll int n,k,ans=0,sum=0,flag=0,flagn=0;
        cin>>n>>k;
        ll int i,j,a[n],b[2*n];
        for(i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
            b[n+i]=a[i];
            if(a[i]<0)flag=1;
            if(a[i]>=0)flagn=1;
            sum+=a[i];
        }
        if(flagn==0){
            sort(a,a+n);
            ans=a[n-1];
        }
        else if(flag==0)
        ans=sum*k;
        else if(flag==1){
            if(k==1){
                ans = msa(a, n);
            }
            else if(k==2){
            ans = msa(b ,2*n);
            }
            else if(sum>0)
            {
               flagn=sum*(k-2);
               ans=flagn;
               sum=flagn;
               for(i=0;i<n;i++){
                sum+=a[i];
                ans=max(ans,sum);
               }
                sum=ans;
               for(i=n-1;i>=0;i--){
                sum+=a[i];
                ans=max(ans,sum);
               }
            sum = msa(b,2*n);
            ans=max(ans,sum);
            }
            else
            {
            ans = msa(b,2*n);
            }
}
 
cout<<ans<<endl;
}
return 0;
}
