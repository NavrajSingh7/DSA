#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge(vector<int> &arr1, int st, int mid, int end);
void mergeSort(vector<int> &arr1, int st, int end);
int partition(vector<int> &arr2, int st, int end);
void quickSort(vector<int> &arr2, int st, int end);

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    // vector<int> a(arr, arr+n);                  // ⭐copies the arr to vec
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    for(int val : arr) cout << val << " ";
    cout << endl;
    
    vector<int> arr1 = {12,31,35,8,32,17};
    mergeSort(arr1, 0, arr1.size()-1);
    for(int val : arr1) cout << val << " ";
    cout << endl;

    vector<int> arr2 = {21,52,12,1,6,13};
    quickSort(arr2, 0, arr2.size()-1);
    for(int val : arr2) cout << val << " ";
    cout << endl;

    return 0;
}

void selectionSort(int arr[], int n){
    for(int i = 0; i <= n-2; i++){
        int mini = i;
        for(int j = i; j <= n-1; j++){
            if(arr[j] < arr[mini]) mini = j;
        }
        swap(arr[i], arr[mini]);
    }
}
void bubbleSort(int arr[], int n){ 
    for(int i = n-1; i >= 1; i--){                  //for(int i = 0; i <n-1; i++)
        int didSwap = 0;            //for linear TC
        for (int j = 0; j <= i-1; j++){             //for(int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
    }
}
void insertionSort(int arr[], int n){
    for(int i = 0; i <= n-1; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
    /*
    for(int i = 1; i < n; i++){
        int curr = arr[i], prev = i-1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
    */
}
void mergeSort(vector<int> &arr1, int st, int end){
    if(st >= end) return;
    
    int mid = st + (end - st)/2;
    mergeSort(arr1, st, mid);        // left half
    mergeSort(arr1, mid+1, end);     // right half
    merge(arr1, st, mid, end);
}
void merge(vector<int> &arr1, int st, int mid, int end){
    vector<int> temp;
    int left = st, right = mid+1;

    while(left <= mid && right <= end){
        if(arr1[left] <= arr1[right]){
            temp.push_back(arr1[left]);
            left++;
        }
        else{
            temp.push_back(arr1[right]);
            right++;
        }    
    }
    while(left <= mid){
        temp.push_back(arr1[left]);
        left++;
    }
    while(right <= end){
        temp.push_back(arr1[right]);
        right++;
    }
    //copy sorted temp to arr1
    for(int i = 0; i < temp.size(); i++) arr1[i+st] = temp[i];
    // for(int i = st; i <= end; i++) arr1[i] = temp[i-st];
}
int partition(vector<int> &arr2, int st, int end){
    int i = st-1, pivot = arr2[end];
    for(int j = st; j < end; j++){
        if(arr2[j] <= pivot){
            i++;
            swap(arr2[j], arr2[i]);
        }
    }
    i++;
    swap(arr2[end], arr2[i]);
    return i;
}
void quickSort(vector<int> &arr2, int st, int end){
    if(st >= end) return;
    int pivIdx = partition(arr2, st, end);
    quickSort(arr2, st, pivIdx-1);       //left half
    quickSort(arr2, pivIdx+1, end);      //right half
}