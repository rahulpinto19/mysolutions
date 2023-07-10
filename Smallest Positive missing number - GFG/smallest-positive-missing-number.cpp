//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int pos=0;pos<n;pos++)
        {
            int idx=arr[pos]-1;
            if(arr[pos]>0 and arr[pos]<n and arr[pos]!=arr[idx])
                {
                    swap(arr[pos],arr[idx]);
                    pos--;
                }

            
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            return i+1;
        }
        return n+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends