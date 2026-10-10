#include <bits/stdc++.h>
using namespace std;

int hash1[10000000];     //declaring globally for 1e7
void numHash(int arr[], int n);
void numQuery();

int hash2[26];      //hash2[256]
void charHash(string s);
void charQuery(); 

int main(){ 
    
    int n;
    cout << "array size: ";
    cin >> n;
    int arr[n];
    cout << "array ele: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    numHash(arr, n);
    numQuery();

    string s;
    cout << "enter s: ";
    cin >> s;
    charHash(s);
    charQuery();
    // can also be done using MAPS, key- num, value- freq
    // bcz arr hashing above 1e7 for int is not poss
    return 0;
}

void numHash(int arr[],int n){

    // precomputing
    for(int i = 0; i < n; i++){
        hash1[arr[i]] += 1;
    }
    /*
    map<int, int> mpp;
    for (int i= 0; i < n; i++){
        mpp[arr[i]]++;
    }
    */
}
void numQuery(){
    int q;
    cout << "enter how many num you want to check: ";
    cin >> q;

    while(q--){
        int number ;
        cout << "enter the num you want: ";
        cin >> number;
        // fetching
        cout << hash1[number] << endl;
        // cout << mpp[number] << endl;
    }
}
void charHash(string s){
    for (int i = 0; i < s.size(); i++){
        hash2[s[i] - 'a'] ++;       //hash2[s[i]]
    }
}
void charQuery(){
    int q;
    cout << "enter how many char you want to check: ";
    cin >> q;

    while(q--){
        char c;
        cout << "enter chars you want to check: ";
        cin >> c;
        cout << hash2[c - 'a'] << endl;         //hash2[c]
    }
}
