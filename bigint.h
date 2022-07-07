#include<bits/stdc++.h>
using namespace std;
#ifndef bigint_h
#define bigint_h

string remove_front_zeroes(string ans)
{
     if(ans=="0")return ans;
                    int ind=0;
                    for(ind=0;ind<(ans.size()-1);ind++)
                    {
                            if(ans[ind]!='0')break;
                    }
            
            return ans.substr(ind,ans.size()-ind);
}

         string addposStrings(string num1, string num2) {
        reverse(num2.begin(),num2.end()); // reverse the num2
            reverse(num1.begin(),num1.end());  // reverse the num1
            string ans=""; // declare the result as string
            int carry=0; // carry variable
            int sum=0; // sumof digits
            for(int i=0;i<(max(num1.size(),num2.size()));i++)
            {
                    if(i>=num1.size())
                    {
                           sum = (num2[i]-'0')+carry;   
                    }
                    else if(i>=num2.size())
                    {
                     sum = (num1[i]-'0')+carry;
                    }
                    else
                    {
                              sum = (num1[i]-'0')+(num2[i]-'0')+carry; 
                    }
                    int dig= sum%10;
                    
                    ans+=(to_string(dig));
                    carry=sum/10;                 
            }
            
            ans+=to_string(carry);
            reverse(ans.begin(),ans.end());

            return remove_front_zeroes(ans);
          
    }
    string multiplyposString(string num1, string num2) {
        string mul1,mul2;
            if(num1.size()<num2.size())
            {
                    mul1=num1;
                    mul2=num2;
            }
            else
            {
                    mul1=num2;
                    mul2=num1;
            }
            
            vector<string > v(mul1.size());
            reverse(mul1.begin(),mul1.end());
            int variable=0;
           for(int i=0;i<mul1.size();i++)
           {
                  string a  ="0";
                  for(int j=0;j<(mul1[i]-'0');j++)
                  {
                          a =addposStrings(a,mul2);
                  }
                   for(int cnt =0;cnt<i;cnt++)
                   {
                           a+='0';
                   }
                   
                   v[i]=a;
                   
                   
           }
            string ans="0";
            for(int i=0;i<mul1.size();i++)
            {
                 ans = addposStrings(ans,v[i]);   
            }
            
           return remove_front_zeroes(ans);
    }
    bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if(str1!="0")
    {
        int ind=0;
                    for(ind=0;ind<(str1.size()-1);ind++)
                    {
                            if(str1[ind]!='0')break;
                    }
            
            str1= str1.substr(ind,str1.size()-ind); 
    }
      if(str2!="0")
    {
        int ind=0;
                    for(ind=0;ind<(str2.size()-1);ind++)
                    {
                            if(str2[ind]!='0')break;
                    }
            
            str2= str2.substr(ind,str2.size()-ind); 
    }
    int flag1=0;
    if (isSmaller(str1, str2))
    {
       // cout<<1<<endl;
        flag1=1;
        swap(str1, str2);
    }
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
      string ans =str;
    ans= remove_front_zeroes(ans);
            if(flag1==1)
            {
                //cout<<1;
                ans= ("-" +ans);
            }
 
    return ans;
}
string longDivision(string number, string divisor)
{
    // As result can be very large store it in string
    string ans;
 
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    string temp = ""  ;
    temp+=number[idx];
    //cout<<temp<<endl;
   
    string a="";
    while (isSmaller(temp , divisor))
    {
        a="";
       a+=number[++idx];
        temp = addposStrings(multiplyposString(temp,to_string(10)) , a);
    }
        
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx) {
        // Store result in answer i.e. temp / divisor
        int i;
        for(i=1;i<=9;i++)
        {
            if(multiplyposString(divisor,to_string(i))==temp)continue;
            else if(!isSmaller(multiplyposString(divisor,to_string(i)),temp))break;
        }
        ans += to_string(i-1);
    
        //cout<<temp<<endl;
        
        // Take next digit of number
        a="";
        a+=number[++idx];
        if(isSmaller(temp,divisor))
        {
            temp = addposStrings( multiplyposString(temp,"10"),a);
        }
        else temp = addposStrings(multiplyposString(findDiff(temp,multiplyposString(to_string(i-1),divisor)) ,"10"),a);
       // cout<<temp<<endl;
    }
 
    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";
 
    // else return ans
    return ans;
}

#endif