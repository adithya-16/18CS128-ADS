/*
 * Adithya Narasimhan
 * 1BM18CS128 | Batch A6
 * Open Ended Question 1
 * 24-12-2020
 * 
 * Given an array of N distinct elements, 
 * the task is to find all elements in array 
 * except two greatest elements.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void reduceArray(vector<int> A, int N) {
    /*
     *  Input: 
     *      vector<int> A -> array of integers to remove two greatest values from
     *      int N -> integer length of the aforementioned array, 3<=N<=100
     *  Output:
     *      Print sorted array elements without the two greatest values
     *  Time complexity:
     *      O(N-log(N))
     *  
     *  Using set<> collection from the Standard Template Library, log(n) time is
     *  achieved for insertion. The implementation uses a Red-Black Tree, which is
     *  a self balancing binary search tree, to achieve this. The elements are
     *  ordered automatically and thus printing them sequentially displays the
     *  sorted values.
     * 
     *  Reference:
     *      http://www.cplusplus.com/reference/set/set/
     */
    set<int> reducedArray;
    for (int x : A)
        reducedArray.insert(x);
    int i = 0;
    for (int x : reducedArray) {
        if (i < N - 2)
            cout << x << " ";
        ++i;
    }
}

int main()
{
    int T;
    cout << "Input: \n";
    cin >> T;
    vector<vector<int>> arrays(T);
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int j = 0; j < N; j++)
            cin >> A[j];
        arrays[i] = A;
    }
    cout << "\nOutput: \n";
    for(vector<int> A : arrays) {
        reduceArray(A, (int)A.size());
        cout << endl;
    }
    return 0;
}