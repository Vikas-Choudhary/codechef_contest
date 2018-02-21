#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>> t;
    while( t-- ){
    int i, size = 0, k = 0, pivot11 = 0, pivot12 = 0;
    ll int x, n, sum, sum1=0;
    cin>> x >> n;
    string s;
    int a[n];
    sum =n * (n+1) * 0.5;
    sum -= x;
    if((sum % 2 == 1 || n == 2)||(x == 2 && n == 3))
        cout << "impossible" <<endl;
    else {
    sum/=2;
    for(i=n;i>=1;i--){
        if(i!=x && sum1 < sum && (sum1 + i) <= sum && (sum - sum1 - i != x)) { sum1 += i; a[i-1] = 1; }
        else if( i!= x && sum1 <= sum){ a[i-1] = 0; }
        else if( i == x) a[i-1] = 2;
    }
 
    for(i=0;i<n;i++){
        if(a[i] == 0) s += "0";
        else if(a[i] == 1) s += "1";
        else if(a[i] == 2) s += "2";
    }
}
    cout<< s << endl;
    }
    return 0;
}




