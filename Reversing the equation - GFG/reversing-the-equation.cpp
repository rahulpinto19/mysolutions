//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            int i=0,j;
            string ans="";
            string temp="";
            char a;
            vector<int>num;
            vector<char>operate;
            while(i<s.size())
            {

                if( s[i]<'0' || s[i]>'9' )
                {
                    if(temp.size())
                    {
                    int k=stoi(temp);
                    num.push_back(k);
                    }
                    operate.push_back(s[i]);
                    temp=""; 
                }
                else
                {
                    temp+=s[i];
                }
                i++;
            }
             num.push_back(stoi(temp));
             for(auto l:num)
             {
                 //cout<<l<<endl;
             }
            i=num.size()-1;j=operate.size()-1;
            
        while(i>=0 || j>=0)
            {
                if(i>=0)
                {
                    ans=ans+to_string(num[i]);
                }
                i--;
                if(j>=0)
                {
                    ans=ans+operate[j];
                }
                j--;
                
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends