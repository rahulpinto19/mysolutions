//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>>ans;
    void help(vector<int>&cand,int target,int pos,vector<int>&sub)
    {
        if(!target)
        {
            ans.push_back(sub);
            return;
        }
        if(target<0 || pos>=cand.size())
        return;
        sub.push_back(cand[pos]);
        target-=cand[pos];
        help(cand,target,pos+1,sub);
        sub.pop_back();
        target+=cand[pos];
        while(pos+1<cand.size() and cand[pos]==cand[pos+1])pos++;
        
        help(cand,target,pos+1,sub);
    }
    vector<vector<int>> combinationSum2(vector<int> &cand, int target) 
    {
        vector<int>sub;
        sort(cand.begin(),cand.end());
        help(cand,target,0,sub);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends