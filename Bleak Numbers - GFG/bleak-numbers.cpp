//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int cnt(int n)
    {
        int bits =0;
        while(n)
        {
            bits = n%2 ?bits+1 : bits;
            n/=2;
            
        }
        return bits;
    }
	int is_bleak(int n)
	{
	    for(int i =n-30;i<=n;i++)
	    {
	        if(i+cnt(i) == n)
	        return 0;
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends