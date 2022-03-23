// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int n, int k)
{
    // Your Code here
    Node *i=head,*p,*q,*r,*s,*t;
    p = head;
    q = head;
    //if k is greater than n 
    if(k>n)
    {
        return head;
    }     
    
    // if k is 1st or last element
    if(k==1 || k==n)
    {
        while(p->next!=NULL)
        {
            r = p;
            p = p->next;
        }
        p->next = head->next;
        r->next = head;
        head->next = NULL;
        return p;
    }

    //assigning p and q to kth element form first and kth element fron last respectively and r,t will be one pointer behind p and q
    int j=1;
    
    while(j !=k)
    {
        r=p;
        p=p->next;
        j++;
    }
    j = 1;
    while(j!=n-k+1)
    {
        t=q;
        q = q->next;
        j++;
    }
    
    if(p==q)
        return head;

    //if p and q are neighbour to each other
    if(p->next == q)
    {
        p->next = q->next;
        q->next = p;
        r->next = q;
        return head;
    }
    if(q->next == p)
    {
        q->next = p->next;
        p->next = q;
        t->next = p;
        return head;
    }
    
    //otherwise
    s = q->next;
    q->next = p->next;
    t->next = p;
    r->next = q;
    p->next = s;
    
    return head;
}
