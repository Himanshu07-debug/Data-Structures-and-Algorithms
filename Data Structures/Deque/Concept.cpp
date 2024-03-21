// DEQUE 

// 1. Internally uses DLL
// 2. It is a Monotonic Structure

// USAGE -->

// Adding and Removing from front and back efficiently --> head and tail DLL

// Random Access --> It has Random Pointers at each node , You can use dq[i]

// Take example of Standard Q, Sliding window maximum --->  It stores data in Monotonic decreasing order at any Moment. [ SORTED ORDER ]

// Due to its Sorting property, it also supports lowerBound, upperBound functionality

// NOTE --> Everything in vector is also applied to deque .. Only deque is not used and stack, vector, queue are used becz deque consumes more 
//          memory space


// REMEMBER --> Deque is a Monotonic Structure..
//              It can store data in Monotonic Increasing or decreasing order at any moment....


// Common Pattern ( Mostly used in Q.s ) -->
// Questions that can be solved by QUEUE, but to optimize it, You try to remove the unnecessary elements from end.. Deque is used there...


// GENERIC CODE of Deque as MONOTONIC Struture -------------------->>

// Q.s --> Sliding window maximum

#include<bits/stdc++.h>
using namespace std;

void monotonic_insert(deque<int> &dq, int i, vector<int> &arr){

    while(!dq.empty() && arr[dq.back()] < arr[i]){
        dq.pop_back();
    }

    dq.push_back(i);

}

void remove(deque<int> &dq, int indx, int k){

    while(!dq.empty() && indx - dq.front() >= k){
        dq.pop_front();
    }

    // while is generic that's why written otherwise if can be applied on this Q.s

}


vector<int> maxSlidingWindow(vector<int> &arr, int k){

    deque<int> dq;

    for(int i=0;i<k;i++){
        monotonic_insert(dq, i, arr);
    }

    vector<int> res;
    res.push_back(arr[dq.front()]);

    for(int i=k;i<arr.size() ;i++){

        remove(dq, i, k);
        monotonic_insert(dq, i, arr);
        res.push_back(arr[dq.front()]);

    }

    return res;

}