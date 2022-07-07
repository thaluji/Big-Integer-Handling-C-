#include<bits/stdc++.h>
#include "bigint.h"
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
   
    
   
    
   cout<<addposStrings(a,b)<<endl;
     
    cout<<findDiff(a,b)<<endl;
    //cout<<findDiff(b,a)<<endl;
    cout<<multiplyposString(a,b)<<endl;
    cout<<multiplyposString(longDivision(a,b),b)<<endl;
    return 0;
}