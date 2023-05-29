//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> d, string p) 
    {
        vector<string>ret;
        vector<string>ans;
        ans.push_back("-1");
        for(int i=0;i<d.size();i++)
        {
            string k=d[i];
            int a=0,pos=0;
            while(k[a]!='\0')
            {
                if(k[a]>='A'&& k[a]<='Z')
                {
                    if(k[a]==p[pos])
                    pos++;
                    else
                    break;
                }
                if(pos>=p.size())
                {
                    ret.push_back(d[i]);
                    break;
                }
                a++;
            }
        }
        if(ret.size()==0)
        return ans;
        return ret;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends