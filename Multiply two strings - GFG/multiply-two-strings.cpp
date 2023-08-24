//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string n1, string n2) 
    {
        if(n1=="0"||n2=="0")
        return "0";
        int p = 0;
        int q = 0;
        if(n1[0]=='-')
        p++;
        if(n2[0]=='-')
        q++;
        vector<int>v(n1.size()+n2.size(),0);
        for(int i=n1.size()-1;i>=p;--i)
        {
            for(int j=n2.size()-1;j>=q;--j)
            {
                v[i+j+1] += (n1[i]-'0')*(n2[j]-'0');
                v[i+j] += v[i+j+1]/10;
                v[i+j+1]%=10;
            }
        }
       // return "";
        int pos = 0;
        while(pos<v.size() and v[pos]==0)
        ++pos;
        string ans = "";
        if(p!=q)
        ans.push_back('-');
        while(pos<v.size())
        {ans.push_back(v[pos++]+'0');}
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends