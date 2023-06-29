//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int ans=0,ptr1=0,ptr2=0,ptr=0;
        while(ptr<k && ptr1<n && ptr2<m)
        {
            if(arr1[ptr1]>arr2[ptr2])
            {
                ans=arr2[ptr2];
                ptr2++;
            }
            else
            {
                ans=arr1[ptr1];
                ptr1++;
            }
            ptr++;
        }
        while(ptr<k and ptr2<m)
        {
                ans=arr2[ptr2];
                ptr2++;
                ptr++;
        }
        while(ptr<k and ptr1<n)
        {
             ans=arr1[ptr1];
                ptr1++;
                ptr++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends