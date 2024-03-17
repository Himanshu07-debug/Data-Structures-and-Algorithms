#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// In Such type of Question, time is Moving continously
// Aap level by level soch sakte ho lekin apko time ka track rkhna honga...
// max time kitna lga kisi bhi employee ko inform hone me ....
// Hum employee ko as a node dikhayenge... and kisi bhi node ko max time kitna lga inform hone me uska track rkhnge...

// In queue --> { node, time taken to inform }

// REMEMBER --> In such type of Question, like min. no. of minutes, then think for a Clock running.. Dont think that in graph, it will be all 
//              about height....
// ho sakta hai Jyada depth wla child bhi Phle jo time lga tha kisi node ko inform hone me ussi time interval me visit ho gya...

// EX --> n = 11, head = 4 , manager - [5,9,6,10,-1,8,9,1,9,3,4] , time - [0,213,0,253,686,170,975,0,261,309,337]

// Iska tree banao, last 3rd level me 6th wla employee 2nd emp ko inform krta hai with time 975 ... 
// ussi level me 8th wla employee 5th emp ko inform krta hai 261 me ... 5th emp jldi inform hua --> Now it will inform 0th emp at +170 minutes..
// 8th --> 5th ---> 0th  =  0 + 261 + 170 = 430 min , see 8 -> 0 tk visit ho gya 430 min me .. But note that ki 6th --> 2nd wla emp abhi bhi 
// inform nhi hua --> 975 - 430 == 545 min is remaining.... 
// Max time for a employee to get informed ---> 965 [ just taking this case from that level ]

// Therefore har ek node ka track rkhna honga unke time ke sath....


int numOfMinutes(int n, int head, vector<int>& arr, vector<int>& time) {

    vector<int> gr[n];

    for(int i=0;i<n;i++){
        if(i != head){
            gr[arr[i]].push_back(i);
        }
    }

    int ans = 0;

    queue<pair<int,int>> q;
    q.push({head, 0});

    while(!q.empty()){

        int id = q.front().first;
        int t = q.front().second;
        q.pop();

        ans = max(ans, t);

        for(int x : gr[id]){

            q.push({x, t + time[id]});

        }



    }

    return ans;
        
}

// DFS --->
// jha pe vis[] = true krte ho wha pe max lena to update the mx
// Keep a running sum --> 
// in for loop --> phle running sum me add kro inform time curr src ka and call ke baad changes backtrack kro i.e running sum se - inform time