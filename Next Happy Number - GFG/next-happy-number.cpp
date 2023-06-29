//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
bool set(int a, int *dp)
{
    if (a == 1)
        return 1;
    int sum = 0;
    while (a)
    {
        int p = a % 10;
        sum += (p * p);
        a /= 10;
    }
    if (dp[sum] == 1)
        return 0;
    dp[sum] = 1;
    set(sum, dp);
}
int nextHappy(int N){
    int dp[1000] = {0};

    int k = N;
    while (k++)
    {
        if (set(k, dp))
            {

                return k;
            }
    }
    return k;
    }    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends