//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        vector<int>vec;
        node*ans = head;
        while(head)
        {
            vec.push_back(head->data);
            head=head->next;
        }int j=0;
        for(int i=0;i<vec.size();i++)
        {
            j++;
            if(j%k==0)
            {
                int start = i-k+1 ,end = i;
                while(start<=end)
                {
                    int temp =vec[start];
                    vec[start]= vec[end];
                    vec[end]=temp; start++ ;end--;
                    
                }
            }
        }head = ans;
        if((vec.size()%k))
        {
            int start = vec.size()-vec.size()%k;
            int end = vec.size()-1;
            while(start<=end)
            {
                    int temp =vec[start];
                    vec[start]= vec[end];
                    vec[end]=temp; start++ ;end--;
                       
            }
            
        }
        for(int i=0;i<vec.size();i++)
        {
            head->data=vec[i];
            head=head->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends