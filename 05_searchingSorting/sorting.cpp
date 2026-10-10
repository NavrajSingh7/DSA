#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge(int arr[], int low, int mid, int high);
void mS(int arr[], int low, int high);
void mergeSort(int arr[], int n);

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    // vector<int> a(arr, arr+n);                  // ⭐copies the arr to vec
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    mergeSort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}

void selectionSort(int arr[], int n){
    for(int i = 0; i <= n-2; i++){
        int mini = i;
        for(int j = i; j <= n-1; j++){
            if(arr[j] < arr[mini]) mini = j;
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
void bubbleSort(int arr[], int n){ 
    for(int i = n-1; i >= 1; i--){
        int didSwap = 0;            //for linear TC
        for (int j = 0; j <= i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
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
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
void merge(int arr[], int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++) arr[i] = temp[i - low];
}
void mS(int arr[], int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid+1, high);
    merge(arr, low, mid, high);
}
void mergeSort(int arr[], int n){
    mS(arr, 0, n-1);
}