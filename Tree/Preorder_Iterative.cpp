#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

struct node{

    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }

};

vector<int> postOrder(node* root)
{
    //code here
    stack<node*> st;

    node* curr = root;
    node* prevPrintedNode = NULL;

    vector<int> post;

    while(!st.empty() || curr != NULL){

        while(curr != NULL){
            st.push(curr);
            curr = curr -> left;
        }

        curr = st.top();

        // Right child is NULL, You can definitely print the current node, BUT
        // if right node is not NULL, then we have to ensure that ki prev Added node in Traversal was right subtree root ( This implies Right 
        // tree is completed )
        if(curr -> right == NULL || curr -> right == prevPrintedNode){

            post.push_back(curr -> data);
            prevPrintedNode = curr;

            st.pop();
            curr = st.top();

        }
        else{
            curr = curr -> right;
        }

    }

    return post;
    
}