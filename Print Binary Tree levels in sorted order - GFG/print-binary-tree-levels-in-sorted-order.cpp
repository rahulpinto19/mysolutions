//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        vector<vector<int>>ans;
        int pos =0;
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            int j;
            for(j=pos;j<pos+pow(2,i) and j<n;j++)
            {
                temp.push_back(arr[j]);    
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            if(j>=n)
            break;
            pos=j;
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
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends