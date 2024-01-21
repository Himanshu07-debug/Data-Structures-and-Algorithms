// One thing is very Clear. Yha pe Hashset, Hashmap nhi chalega becz Dono se getRandom() perform nhi kar sakte...

// Another option is Array, getRandom ho jayega indx pe rand() function lagake.. 
// But in Deletion, Apko shift krna padega elements after deletion, Also Insertion me array ko search ki wo hai kya already array me ??

// getRandom() -> O(1) , Insertion, Deletion -> O(n)


// Before Insertion, we have to check element present hai kya...
// -2^31 <= val <= 2^31 - 1
// itne elements ka track rkhne ke liye array nhi bana sakte, size > 10^9

// There is one more line in Constaint --->
// At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
// This means max. Insertion 2 * 10^5 baar honga and itne elements ka hi track rkhna hai.. Size < 10^9 
// But yeah Array se nhi honga, We will use Hashmap [ out of many no.s , only valid no.s ke liye ]


// Remove() ->
// Do we Really need Shifting ????
// Hum agar array me val ke jagah me arr.back() ko place krke pop_back() kar sakte hai piche se.. 
// Will not Affect Probability, Becz range of no.s are same after deletion and rand() kisi bhi ek ko utha lenga...

// HashMap me {val, indx} 


// NAIVE ------------>> Use Array ( getRandom() -> O(1) , Insertion, Deletion -> O(n) )

// BEST ------------->> 
// vector + Hashmap



#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:

    unordered_map<int,int> m;
    vector<int> arr;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {

        if(m.find(val) != m.end() ) return false;

        m[val] = arr.size();
        arr.push_back(val);
        return true;

    }
    
    bool remove(int val) {

        if(m.find(val) == m.end()) return false;

        int indx = m[val];

        m[arr.back()] = indx;

        arr[indx] = arr.back();

        m.erase(val);
        arr.pop_back();

        return true;
        
    }
    
    int getRandom() {

        int i = rand() % arr.size();

        return arr[i];
        
    }
};