#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,n) for(int i=0;i<=n;i++)
#define CIN(n) scanf("%d",&n)
#define COUT(n) printf("%d",n)
#define nextline printf("\n")
#define pb push_back
vector<int> *cycles =new vector<int>[100005];
vector<int> *connection = new vector<int>[100005];
inline int minpath(int x,int y,int c1)
{
	int p;
	if(y<x)
	{
		p=x;
		x=y;
		y=p;
	}
	int sumf=0;
	int sumb=0;
  for(int i=x;i<y;i++)
  {
  	sumf+=cycles[c1][i];
  }
  for(int i=1;i<x;i++)
  {
  	sumb+=cycles[c1][i];
  }
  for(int i=y;i<cycles[c1].size();i++)
  {
  	sumb+=cycles[c1][i];
  }
   return sumf<sumb?sumf:sumb;
}
 
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{    
		
	  
		int N,Q;
		cin>>N>>Q;
		int MINPATH[N+1];
        int singlepath[N+1];
        int sumMINPATH[N+1];
        int sumsinglePath[N+1];
	    for(int i=1;i<=N;i++)
	    {
	    	int n;
	    	cin>>n;
	    	cycles[i].pb(n);
	    	FOR(j,n)
	    	{
	    		int x;
	    		cin>>x;
	    		cycles[i].pb(x);
	    	}
 
	    }
	    for(int i=1;i<=N;i++)
	    {
	    	int v1,v2,w;
	    	cin>>v1>>v2>>w;
	    	connection[i].pb(v1);
	    	connection[i].pb(v2);
	    	connection[i].pb(w);
	    }
 
	    MINPATH[1]=minpath(connection[N][1],connection[1][0],1);
	    sumMINPATH[1]=MINPATH[1];
	    sumsinglePath[0]=0;
	    for(int i=1;i<=N;i++)
		{
			if(i>1){
			MINPATH[i]=minpath(connection[i-1][1],connection[i][0],i);
			sumMINPATH[i]=MINPATH[i]+sumMINPATH[i-1];}
		        singlepath[i]=connection[i][2];
			sumsinglePath[i]=singlepath[i]+sumsinglePath[i-1];
		}
		sumsinglePath[0]=0;
		
	
	    FOR(j,Q)
	    {
	    	int v1,v2,c1,c2;
	    	cin>>v1>>c1>>v2>>c2;
	    	int temp;
	    	if(c1>c2)
	    	{
	    		temp=c1;
	    		c1=c2;
	    		c2=temp;
	    		temp=v1;
	    		v1=v2;
	    		v2=temp;
	    	}
	    	
	    	    
               int C1v1,C1v2,C2v1,C2v2;
               
               
               
               	if(c1==1)
               	{
                 C1v1=connection[N][1];
                 C1v2=connection[1][0];
                 C2v1=connection[c2-1][1];
                 C2v2=connection[c2][0];
               	}
               	else
               	{
                 C1v1=connection[c1-1][1];
                 C1v2=connection[c1][0];
                 C2v1=connection[c2-1][1];
                 C2v2=connection[c2][0]; 
               	}
               
               
                int anssum1=0;
                int anssum2=0;
               anssum1+=abs(sumsinglePath[c2-1]-sumsinglePath[c1-1]);
               anssum1+=abs(sumMINPATH[c2-1]-sumMINPATH[c1]);
               anssum2+=abs(sumsinglePath[c2-1]-sumsinglePath[N]);
               anssum2+=abs(sumMINPATH[N]-sumMINPATH[c2]);
               if(c1!=1)
               	 anssum2+=sumMINPATH[1];
               anssum2+=sumsinglePath[c1-1];
               if(c1>1)
                anssum2+=abs(sumMINPATH[c1-1]-sumMINPATH[1]);
               
               anssum1+= minpath(v1,C1v2,c1)+minpath(v2,C2v1,c2);
               
               anssum2+=minpath(v1,C1v1,c1)+minpath(v2,C2v2,c2);
              
               if(anssum1<=anssum2)
               	cout<<anssum1<<endl;
               else
               	cout<<anssum2<<endl;
                
 
	    			
	    }
       for(int i=0;i<=N;i++)
       {
       	  cycles[i].clear();
          connection[i].clear();
       }
 
		}
		
return 0;
}
 
