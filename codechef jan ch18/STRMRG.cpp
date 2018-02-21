#include<bits/stdc++.h>
#define ll long long
using namespace std;
  
int max(int a, int b)
{
    return (a > b)? a : b;
}
  
int lcs( string s1, string s2, int x, int y)
{
   int L[x+1][y+1];
   int i, j;
  
   for (i=0; i<=x; i++)
   {
     for (j=0; j<=y; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0; 
  
       else if (s1[i-1] ==s2[j-1]) 
        { 
            L[i][j] = L[i-1][j-1] + 1;
        }
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   return L[x][y];
}
  
int main(){
 int t;
 cin>>t;
 while(t--){
    
    int n, m, x=0, y=0, ans=0, k, l;
    cin>> n >> m;
    x=n;
    y=m;
    char a[n], b[m], c;
    string s1 ,s2;
    cin>>a >> b;
    for(k=0;k<n;k++){
    	  if(a[k]!=a[k+1] && k<n-1)
		  s1+=a[k];
          if(k==n-1)
            s1+=a[k];
    }
     for(k=0;k<m;k++){
        if(b[k]!=b[k+1] && k<n-1)
		  s2+=b[k];
        if(k==n-1)
            s2+=b[k];
    }
    x=s1.length();
    y=s2.length();
    l=x+y-lcs(s1,s2,x,y);
    cout<<l<<endl;
    
}
return 0;   
}
