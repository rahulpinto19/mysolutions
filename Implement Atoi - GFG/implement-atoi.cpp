//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool ischar(char a)
    {
        if(a>'9'||a<'0')
        return 1;
        return 0;
    }
    /*You are required to complete this method */
    int atoi(string str)
    {
        int sum=0;
        int i=0;
        int sign=1;
        if(str[i]=='-'|| str[i]=='+')
        {sign=-1; i++;}
        for(i;i<str.size();i++)
        {
            if(ischar(str[i]))
            return -1;
            else 
            sum=sum*10 +int(str[i]-'0');
        }
        return sign*sum;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends