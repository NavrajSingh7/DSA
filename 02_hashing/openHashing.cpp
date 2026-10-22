#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

// OPEN HASHING USING LINKED LIST

class Hashing{

    vector<list<int>> hashtable;
    int buckets;

public:
    Hashing(int size){
        buckets = size;
        hashtable.resize(size);
    }
    int hashvalue(int key){
        return key % buckets;
    }
    void add(int key){
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }
    list<int>:: iterator search(int key){
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }
    void deleteKey(int key){
        int idx = hashvalue(key);
        if(search(key) != hashtable[idx].end()){        //key is present
            hashtable[idx].erase(search(key));
            cout << key << " is deleted" << endl;
        } else{
            cout << key << " not present in hashtable" << endl;
        }
    }
};

int main(){
    Hashing h(10);
    h.add(2);
    h.add(532);
    h.add(89);
    h.add(35);
    h.add(31);

    cout << h.hashvalue(89);
    cout << endl;
    h.deleteKey(31);
    h.deleteKey(31);

    return 0;
}