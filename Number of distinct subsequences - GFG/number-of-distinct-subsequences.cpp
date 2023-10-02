//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    vector<int>vis(26,0);
	    vector<long>pow(s.size()+1);
	    int mod = 1e9 + 7;

	    pow[0]=1;
	    int flag =0;
	    for(int i=1;i<=s.size();i++)
	    {
            pow[i]=(pow[i-1]*2)%mod;
	        if(vis[s[i-1]-'a']!=0)
	        {
	            pow[i]=(pow[i]-pow[vis[s[i-1]-'a']-1] + mod)%mod;
	        }
	        vis[s[i-1]-'a']=i;
	        
	    }
	   // if(flag)
	   // return pow[s.size()-1]-1;
	    return pow[s.size()];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends