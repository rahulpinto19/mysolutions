//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
        int pos=0;
        for(int i=0;i<n;i++)
        {
            int val = q.front();
            q.pop();
            if(val>0)
            arr[pos++]=val;
            else
            q.push(val);
        }
        while(!q.empty())
        {
            arr[pos++]=q.front();
            q.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends