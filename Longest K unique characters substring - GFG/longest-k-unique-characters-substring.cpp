//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        int ans = 0; 
        int end =0,start =0,cnt=0;
        unordered_map<char,int>mp;
        while(end<s.size())
        {
            
            if(mp[s[end]]==0)
            {
                cnt++;
            }
            mp[s[end]]++;
            //char a = s[start];
            while(cnt>k and start<=end)
            {
                mp[s[start]]--;
                if(mp[s[start]]==0)
                {cnt--; mp.erase(s[start]);}
                start++;
                // cout<<start<<"s "<<endl;
            }
                // cout<<end<<" "<<start<<endl;
            ans = max(ans,end-start+1);
            end++;
        }
        // for(auto x:mp)
        // cout<<x.first<<" "<<x.second<<endl;
        if(cnt<k)
        return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends