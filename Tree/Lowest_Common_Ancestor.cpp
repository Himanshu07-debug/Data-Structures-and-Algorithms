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


// NAIVE --------------------------------->>

bool search(node* root, node* t, vector<node*> &path){

    if(root == NULL) return false;

    path.push_back(root);

    if(root == t) return true;

    if(search(root -> left, t, path) == true){
        return true;
    }

    if(search(root -> right, t, path) == true){
        return true;
    }

    path.pop_back();
    return false;

}

node* lowestCommonAncestor(node* root, node* p, node* q) {

    vector<node*> path1, path2;

    if(search(root, p, path1) == false || search(root, q, path2) == false){
        cout << "No LCA possible" << endl;
        return NULL;
    }

    int i = 0;

    while(i < path1.size() && i < path2.size()){

        if(path1[i] == path2[i]) i++;
        else{
            break;
        }

    }

    return path1[i-1];
      
}


// OPTIMAL ----------------------------->>


node* lca(node* root, node* p, node* q){

    if(root == NULL){
        return NULL;   // represents false
    }

    if( root == p || root == q ){
        return root;
    }

    node* leftTree = lca(root -> left, p, q);
    node* rightTree = lca(root -> right, p, q);

    if(leftTree != NULL && rightTree != NULL){
        return root;
    }
    else if(leftTree != NULL){
        return leftTree;
    }
    else if(rightTree != NULL){
        return rightTree;
    }

    return NULL;

}