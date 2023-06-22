//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) 
    {
        // code here
        unordered_map<int,int>val;
        val[5]=0;
        val[10]=0;
        val[20]=0;
        for(int i=0;i<N;i++)
        {
            if(bills[i]==5)
            val[5]++;
            else if(bills[i]==10)
            {
                if(val[5]>=1)
                {
                    val[5]--;
                    val[10]++;
                }
                else
                return 0;
            }
            else
            {
                if(val[10]>=1 && val[5]>=1)
                {
                    val[20]++;
                    val[10]--;
                    val[5]--;
                }
                else if(val[5]>=3)
                {
                    val[5]-=3;
                    val[20]++;
                }
                else 
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends