//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        vector<string>temp;
        int i=0;
        string k="";
        while(i<s.size())
        {
            if(s[i]=='.')
            {
                temp.push_back(k);
                k="";
            }
            else
            {
                k=k+s[i];
            }
            i++;
        }

        temp.push_back(k);
       reverse(temp.begin(),temp.end());
        string ans="";
        for(int i=0;i<temp.size()-1;i++)
        {
            ans+=temp[i];
            ans+='.';
        }
        //cout<<temp[temp.size()-1];
        ans+=temp[temp.size()-1];
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends