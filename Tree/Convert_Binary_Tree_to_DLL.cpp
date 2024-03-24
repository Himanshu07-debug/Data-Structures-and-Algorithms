#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution
{
    public: 

    // Passing nodes by Reference
    void inorder(Node* root, Node* &head, Node* &curr){

        if(root != NULL){

            inorder(root -> left, head, curr);

            if(head == NULL){
                head = root;
                curr = root;
            }
            else{
                curr -> right = root;
                root -> left = curr;
                curr = root;
            }

            inorder(root -> right, head, curr);

        }

    }

    Node * bToDLL(Node *root)
    {

        Node* head = NULL;
        Node* curr = NULL;

        inorder(root, head, curr);
        
        // curr -> right = NULL;
        // no need of this

        return head;
        
    }
};