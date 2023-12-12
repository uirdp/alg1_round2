#include <iostream>
#include <vector>

using namespace std;

int solve(int i, int m, int n, const vector<int>& A){

    if(m == 0) return 1;
    if(i >= n) return 0;

    //use ith element in A || do not use ith element in A
    int res = solve(i + 1, m, n, A) || solve(i + 1, m - A[i], n, A); 
    return res;
}

void ExhaustiveSearch(){

    int n;
    cin >> n;

    vector<int> A;
    for(int i = 0; i != n; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }

    int q;
    cin >> q;

    for(int i = 0; i != q; ++i){
        int m;
        cin >> m;

        if(solve(0, m, n, A)) cout << "yes" << endl;
        else cout << "no" << endl;
    }

}

int main(){
    ExhaustiveSearch();
    return 0;
}