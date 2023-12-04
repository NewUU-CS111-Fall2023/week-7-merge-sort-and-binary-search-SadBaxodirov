/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include "tasks.h"

int main() {
    cout << "Task 1" << endl;//time complexity: O(T*N)->O(N^2)
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        int result = task1(A);
        cout << result << endl;
    }
    cout << "Task 2" << endl;//time complexity: O(n^3) where n is size of array
    int n;
    cin >> n;
    vector<int> Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> Y[i];
    }
    cout<<task2(n, Y)<<endl;
    cout << "Task 3" << endl;// time complexity: O(n^2)
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        int result[N+M];
        for (int i = 0; i < N; ++i) {
            cin >> arr1[i];
        }
        for (int i = 0; i < M; ++i) {
            cin >> arr2[i];
        }
        task3(arr1, N, arr2, M, result);
    }
    cout << "Task 4" << endl;//time complexity: O(N^2) where N=n*n
    int n=0, k=0;
    cin>>n;
    cin>>k;
    int matrix[n*n];
    for (int i=0;i<n*n;i++){
        cin>>matrix[i];
    }
    cout<<task4(matrix, n*n, k-1)<<endl;
    cout << "Task 5" << endl;//Big O(N^2) where N=k
    cin >> n;
    int nums[MAX_N];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> k;
    task5(nums, n, k);
    return 0;
}
