/*The Number of Inversions

For a given sequence A={a0,a1,...an−1}
, the number of pairs (i,j) where ai>aj and i<j, 
is called the number of inversions. The number 
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;
long long cnt {0};

void merge(vector<int>& A, int left, int mid, int right){

    //無限大
    constexpr int inf = 1000000007;

    //部分集合のサイズ
    int n1 = mid - left;
    int n2 = right - mid;

    //マージソートにはこれらの配列が必要で、メモリを消費してしまうデメリットがある
    vector<int> L(n1+2);
    vector<int> R(n2+2);

    //左右に分ける
    for(int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    
    //部分集合の端を無限大にすることで最大項を解決（日本語難しい）
    //AOJではintをキャストしないと通らなかった（自分の環境ではコンパイルできた）
    L[n1] = inf;
    R[n2] = inf;

    int i {0};
    int j {0};

    //入れ替えをおこなう
    for(int k = left; k < right; k++){
        
        if (L[i] <= R[j]){
            A[k] = L[i++];
        }

        else{
            A[k] = R[j++];
            cnt += n1 - i;
        }
    }
}

 void mergeSort(vector<int>& A, int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

void mergeSortApplication(){

    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i != n; ++i){
        cin >> A[i];
    }

    mergeSort(A, 0, n);

    cout << cnt << endl;
}

int main(){
    mergeSortApplication();
    return 0;
}