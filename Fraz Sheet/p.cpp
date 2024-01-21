#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:

    unordered_map<int,int> m;
    vector<int> arr;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m[val] == 0){
            m[val] = arr.size();
            arr.push_back(val);
            return true;
        }

        return false;
    }
    
    bool remove(int val) {

        if(m[val] != 0){

            int i = m[val];
            int x = arr.back();

            swap(arr[i], x);

            m[x] = i;

            m[val] = 0;

            arr.pop_back();

            return true;

        }

        return false;
        
    }
    
    int getRandom() {

        int i = rand() % arr.size();

        return arr[i];
        
    }
};