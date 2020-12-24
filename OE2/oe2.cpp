/*
 * Adithya Narasimhan
 * 1BM18CS128 | Batch A6
 * Open Ended Question 2
 * 24-12-2020
 * 
 * In the given range [L, R], print all numbers having unique digits.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool isUnique(unordered_set<int> globalLookup, int n) {
    unordered_set<int> localLookup; 
    int t = n;
    while(t != 0) { 
        if(t > 10 && globalLookup.find(t) != globalLookup.end()) {
            return false;
        }
        int d = t % 10; 
        if(localLookup.find(d) != localLookup.end()) { 
            if(t > 10) globalLookup.insert(t);
            return false; 
        } 
        localLookup.insert(d); 
        t = t / 10; 
    } 
    return true; 
} 

vector<int> getList(int L, int R) {
    /*
     *  Input: 
     *      int L, R -> Range [L, R]
     *  Output:
     *      vector<int> -> Integer array with numbers only having unique elements
     *  Time complexity:
     *      O((R-L)n)
     *  
     *  Using unordered_set<> collection from the Standard Template Library, 
     *  we can get O(1) storage and lookup time as a hashmap. In isUnique,
     *  a local set is used to look for repeating digits, where worst case time
     *  is O(n), where n is the total number of digits.
     * 
     *  To reduce time taken for overly large ranges, we use a global unordered set to
     *  take note of already seen non-unique values so that the time to evaluate 
     *  the uniqueness of larger numbers is reduced (dynamic programming).
     * 
     *  Reference:
     *      http://www.cplusplus.com/reference/unordered_set/unordered_set/
     */
    unordered_set<int> DP;
    vector<int> A;
    for(int i = L; i <= R; i++) 
        if(isUnique(DP, i)) A.push_back(i);
        else DP.insert(i);
    return A;
}

int main() {
    int L, R;
    cout << "Input: \n";
    cout << "L = ";
    cin >> L;
    cout<< "R = ";
    cin >> R;
    cout << "\nOutput :\n";
    for(int x : getList(L, R))
        cout << x << " ";
    cout << endl;
    return 0;
}