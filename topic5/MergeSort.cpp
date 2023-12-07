#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void merge(vector<int>& A, int left, int mid, int right){

    constexpr float inf = numeric_limits<float>::infinity();

    int n1 = mid - left;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for(int i = 0; i != n1; ++i){
        L[i] = A[left + i];
    }

    for(int i = 0; i != n2; ++i){
        R[i] = A[mid + 1];
    }
    
    //sentinel
    L[n1] = inf;
    L[n2] = inf;

    int i = 0;
    int j = 0;
}
