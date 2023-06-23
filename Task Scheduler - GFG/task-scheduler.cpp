//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int k, vector<char> &tasks) {
        vector<int>temp(26,0);
        for(auto x:tasks)
        {
            temp[x-'A']++;
        }
        int count=0;
        int maxi=-1;
        for(int i=0;i<26;i++)
        {
            if(temp[i]==maxi)
            count++;
            else if(temp[i]>maxi)
            {
                maxi=temp[i];
                count=1;
            }
        }
        return max(N,(maxi+(maxi-1)*k+count-1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends