#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 105;
int task1(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 2; ++i) {
        vector<int> subarray(arr.begin() + i, arr.begin() + i + 3);
        sort(subarray.begin(), subarray.end());//let's say it is bubble sort, size of each subarray is 3
        int median = subarray[1];
        auto it = find(arr.begin(), arr.end(), median);
        if (it != arr.end()) {
            arr.erase(it);
        }
    }
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}
long int task2(int n, vector<int> &Y){
    long int initial_beautifulness = 0;
    for (int i = 0; i < n; ++i) {
        initial_beautifulness += abs(Y[i] - i - 1);
    }
    long int max_beautifulness = initial_beautifulness;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(Y[i], Y[j]);
            long int temp_beautifulness = 0;
            for (int k = 0; k < n; ++k) {
                temp_beautifulness += abs(Y[k] - k - 1);
            }
            max_beautifulness = max(max_beautifulness, temp_beautifulness);
            swap(Y[i], Y[j]);
        }
    }
    return max_beautifulness;
}
void task3(int arr1[], int size1, int arr2[], int size2, int result[]){
    int i, j;
    int resultSize = size1+size2;
    for(i=0; i<size1; i++)
    {
        result[i] = arr1[i];
    }
    for(j=0; j<size2; j++)
    {
        result[i] = arr2[j];
        i++;
    }
    resultSize = i;
    for(j=0; j<(resultSize-1); j++)
    {
        for(i=0; i<(resultSize-1); i++)
        {
            if(result[i]<result[i+1])
            {
                int temp = result[i];
                result[i] = result[i+1];
                result[i+1] = temp;
            }
        }
    }
    for(i=0; i<resultSize; i++)
    {
        if(i==(resultSize-1))
            cout<<result[i];
        else
            cout<<result[i]<<" ";
    }
    cout<<endl;
}
int task4(int array[], int size, int k){
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return array[k];
}
void task5(int nums[MAX_N], int n, int k) {
    int uniqueValues[MAX_N];
    int frequencies[MAX_N];
    int uniqueCount = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            uniqueValues[uniqueCount] = nums[i];
            frequencies[uniqueCount] = 1;
            uniqueCount++;
        } else {
            frequencies[uniqueCount - 1]++;
        }
    }
    //bubbleSort(frequencies, uniqueValues, uniqueCount);
    for (int i = 0; i < uniqueCount - 1; ++i) {
        for (int j = 0; j < uniqueCount - i - 1; ++j) {
            if (frequencies[j] > frequencies[j + 1]) {
                int tempFreq = frequencies[j];
                frequencies[j] = frequencies[j + 1];
                frequencies[j + 1] = tempFreq;
                int tempValue = uniqueValues[j];
                uniqueValues[j] = uniqueValues[j + 1];
                uniqueValues[j + 1] = tempValue;
            }
        }
    }
    for (int i = uniqueCount - 1; i >= uniqueCount - k; --i) {
        cout << uniqueValues[i] << " ";
    }
    cout << endl;
}
