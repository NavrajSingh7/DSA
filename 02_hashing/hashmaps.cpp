#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

void map_operations();
int sumRep(vector<int> nums);
bool checkAnagram(string s1, string s2);
bool checkIsomorphic(string s3, string s4);

int main (){

    map<string, int> directory;
    // map<datatype 1, datatype 2, greater<datatype 1>>;        desecnding order
    
    // insertion - O(logN) - TC
    directory["aman"] = 52924;
    directory["raman"] = 678290;
    directory["daman"] = 64786957;
    directory.insert(make_pair("gagan", 2658));
    
    // accessing
    cout << "aman is: " << directory["aman"] << "\n";
    cout << "daman is: " << directory.at("daman") << "\n";
    for(auto it: directory){
        cout << "name- " << it.first << endl;
        cout << "no. " << it.second << endl;
    }

    // travesing
    map<string, int>::iterator itr;
    for(itr = directory.begin(); itr != directory.end(); itr++);
    map<string, int>::reverse_iterator itr1;
    for(itr1 = directory.rbegin(); itr1 != directory.rend(); itr1++);

    vector<int> nums = {1,2,6,6,1,8,2,5,3,9,0};
    cout << "sum: " << sumRep(nums) << endl;

    string s1, s2;
    cin >> s1 >> s2;
    cout << (checkAnagram(s1, s2) ? "yes" : "no" ) << endl;
    
    string s3, s4;
    cin >> s3 >> s4;
    cout << (checkIsomorphic(s3, s4) ? "yes" : "no" ) << endl;

    return 0;
}
void map_operations(){
// made a separate funtion bcz output will freeze as operations done on empty maps
    map<int, int> m;
    map<int, int> m1;
    auto it = m.begin();
    m.erase(it);            // or - m.erase(key)    TC - O(logN)
    auto st = m.begin();
    auto end = m.begin();
    advance(it, 2);
    advance(it, 5);
    m.erase(st, end);       // deletes [2,5)    TC - O(N)
    swap(m, m1);
    m.swap(m1);
    m.clear();              //deletes everything in map
    m.empty();              //boolean, empty(true) or not(false)
    m.size();
    m.find(4);              //if present return itr, else end-itr, TC - O(logN)
    m.count(3);             //no. of occurrences of key, 1/0
    m.upper_bound(2);       //returns itr to next greater key
    m.lower_bound(5);       //returns itr to key if present, else next greater
}
int sumRep(vector<int> nums){
    map<int, int> freq;
    for(int val : nums){
        freq[val]++;
    }
    int sum = 0;
    for(auto pair : freq){
        if(pair.second > 1) sum += pair.first;
    }
    return sum;
}
bool checkAnagram(string s1, string s2){
    if(s1.length() != s2.length()) return false;

    unordered_map<char, int> m;
    for(auto c1 : s1) m[c1]++;
    for(auto c2 : s2){
        if(m.find(c2)==m.end()) return false;
        else m[c2]--;
    }
    for(auto ele : m){
        if(ele.second != 0) return false;
    }
    return true;
}
bool check1to1(string s3, string s4){
    unordered_map<char, char> m;
    for(int i = 0; i < s3.length(); i++){
        if(m.find(s3[i]) != m.end() && m[s3[i]] != m[s4[i]]) return false;
        else m[s3[i]] = s4[i];
    }
    return true;
}
bool checkIsomorphic(string s3, string s4){
    if(s3.length() != s4.length()) return false;

    bool s3s4 = check1to1(s3, s4);
    bool s4s3 = check1to1(s4, s3);
    
    return s3s4 && s4s3;
}
// Unordered Map : unique key value pairs but NOT in ascending/descending order
// implemented using hashing
// map -> unordered_map  (#include<unordered_map>)
// insert, erase, find - Avg TC = O(1), worst TC = O(N)

// Multi Map : key value pairs NOT unique, but in order
// implemented using BST
// map -> multimap   (#include<map>)
// insert, erase - TC = O(logN)
// directory["daman"] = 64786957;          CANT BE USED

// Unordered Multi Map : duplicate key value pairs and not in ascending/descending order
// implemented using hashing
// map -> unordered_multimap  (#include<unordered_map>)
// insert, erase, find - Avg TC = O(1), worst TC = O(N)