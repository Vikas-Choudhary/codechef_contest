#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
{
    string inp;
    int x,y;
    cin>>inp;
    cin>>x>>y;
    int cb=0;
    int ca=0;
    vector<char> out;
    int apples= count(inp.begin(),inp.end(),'a');
    int bananas= count(inp.begin(),inp.end(),'b');
    while(apples>0 || bananas >0)
{
    if(apples>bananas)
{
        while(ca<x && apples>0 && apples>bananas)
        {
            out.push_back('a');
            ca+=1;
            cb=0;
            --apples;
        }
        if(bananas>0)
        {
            out.push_back('b');
            cb+=1;
            ca=0;
            --bananas;
        }
        else
            {
                if(apples>0 || bananas>0)
                {
                    ca=cb=0;
                    out.push_back('*');
                }
            }
}
    else
    {
         while(cb<y && bananas>0 &&bananas>apples)
        {
            out.push_back('b');
            cb+=1;
            ca=0;
            --bananas;
        }
 
        if(apples>0)
        {
            out.push_back('a');
            ca+=1;
            cb=0;
            --apples;
 
        }
         else
            {
                if(apples>0 || bananas>0)
                {
                    ca=cb=0;
                    out.push_back('*');
                }
            }
    }
}
vector<char> :: iterator it;
for(it=out.begin();it<out.end();it++)
    cout<<*it;
cout<<endl;
}
}
