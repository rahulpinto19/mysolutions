//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int check(string k)
    {
        int start=0,end=k.size()-1;
        while(start<=end)
        {
            if(k[start]!=k[end])
            {
                return 1;
            }
            start++;
            end--;
        }
        return 0;
    }
    string longestPalin (string s) 
    {
        int n=s.length();
    if(n==1)
    return s;
    while(n-1)
    {for(int i=0;i<s.length()-n+1;i++)
    {
        {
            int flag=check(s.substr(i,n));
            if(!flag)
            {
                return s.substr(i,n);
            }
        }
    }
        n--;
    }    
    
    return s.substr(0,1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends