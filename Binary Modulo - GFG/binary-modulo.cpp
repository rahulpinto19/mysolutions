//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            int ans=s[s.length()-1]-'0';
           // cout<<ans<<endl;
            long long int  k=1;
            for(int i=s.length()-2;i>=0;i--)
            {
                int p=(s[i]-'0');
                k*=2;
                k%=m;
                ans+=(k*p);
                ans%=m;
            }
            return ans%m;
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
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends