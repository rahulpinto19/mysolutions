//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int candy(vector<int>& ratings) 
    {
        if(ratings.size()==1)
        {
            return 1;
        }
        vector<int>cand1(ratings.size(),1),cand2(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                cand1[i]=cand1[i-1]+1;
            }
            else
            continue;
        }
         for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                cand2[i]=cand2[i+1]+1;
            }
            else
            continue;
        }
        int ans=0;
        for(int i=0;i<ratings.size();i++)
        ans += max(cand1[i],cand2[i]);
        return ans;
    }
    int minCandy(int N, vector<int> &ratings) 
    {
        return candy(ratings);   
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends