#include <bits/stdc++.h>
using namespace std;

void explainPairs();
void explainVectors();
void explainLists();
void explainDeque();
void explainStack();
void explainQueue();
void explainPQ();
void explainSets();
void explainMS();
void explainMap();
void someAlgos();

int main(){

    return 0;
}

// PAIRS
void explainPairs(){
    pair<int , int> p = {1,3};
    cout << p.first << " " << p.second;

    // Nested Pairs
    pair<int, pair<int,int>> q = {1,{2,4}};
    cout << q.second.first;

    //Pair Array
    pair<int,int> arr[]= {{1,2}, {3,4}, {5,6}};
    cout << arr[1].second;
}

// VECTORS
void explainVectors(){

    vector<int> v;          //[empty]
    v.push_back(1);         //[1]
    v.emplace_back(2);      //[1,2]
    
    vector<pair<int,int>> vec;
    vec.push_back({1,2});       //[(1,2)]
    vec.emplace_back(3,4);      //[(1,2),(3,4)]

    vector<int> v1(5,10);        //[10,10,10,10,10]  vector of size 5 containing given value
    vector<int> v2(5);           //of size 5 containing gibberish
    vector<int> v3(4,53);
    vector<int> v4(v3);          //copy of v3
    
    //let V = [1,2,3,4,5]
    vector<int> :: iterator it = v.begin();         //'it' is just a variable, point memory index of 0th index
    it++;
    cout << *(it);          //prints 2
    cout << v[0];           //prints 1, == v.at(0) rarely used

    vector<int> :: iterator it = v.end();       //points right after last index, use 'it--'
    cout << v.back();                           // last index 
    
    //Printing a vector
    for(vector<int> :: iterator it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }
    //instead of 'vector<int>::iterator it' we use 'auto'
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }
    for(auto it : v){
        cout << it << " ";
    }

    // Deletion func
    // {10,20,30,40,50}
    v.erase(v.begin()+1);       //{10,30,40,50}
    v.erase(v.begin()+2, v.begin()+4);      //{10,20,50}, [start,end)

    // Insert Func
    vector<int> v(2,100);           //{100,100}
    v.insert(v.begin(), 300);       //{300,100,100}
    v.insert(v.begin()+1, 2, 20);   //{300,20,20,100,100}

    vector<int> v2(2,50);
    v.insert(v.begin(), v2.begin(), v2.end());  //{50,50,300,20,20,100,100}

    // other funcs
    cout << v.size();       //gives current size
    v.pop_back();           //pops last element
    v1.swap(v2);            //v1 <-> v2
    v.clear();              //erases everything, empty vector
    cout << v.empty();      // true/false

}

// LISTS
void explainLists(){
    list<int> ls;
    ls.push_back(1);        //{1}
    ls.emplace_back(2);     //{1,2}
    ls.push_front(3);       //{3,1,2}
    ls.emplace_front();     //{1,2}
    // rest is same as vectors
}

// DEQUE
void explainDeque(){
    deque<int> dq;
    dq.pop_back();
    dq.pop_front();
    dq.back();
    dq.front();
    // rest same as vector/lists
}

// STACK
void explainStack(){
    stack<int> st;
    st.push(1);     //{1}
    st.push(2);     //{2,1}
    st.push(4);     //{4,2,1}
    st.emplace(5);  //{5,4,2,1}

    cout << st.top();       //5, indexing doesnt exist- st[3] is invalid
    
    st.pop();       //{4,2,1}
    cout << st.top();       //4
    cout << st.size();      //3
    cout << st.empty();     //true / false

    stack<int> st1,st2;
    st1.swap(st2);          //st1 <-> st2
}

// QUEUE
void explainQueue(){
    queue<int> q;
    q.push(1);      //{1}
    q.push(2);      //{1,2}
    q.emplace(4);    //{1,2,4}

    q.back() += 5;
    cout << q.back();   //print 9
    cout << q.front();  // 1
    q.pop();            //{2,9}
    cout << q.front();  // 2
}

// PRIORITY QUEUE
void explainPQ(){
    //MAXIMUM HEAP
    priority_queue<int> pq;
    pq.push(5);     //{5}
    pq.push(2);     //{5,2}
    pq.push(10);    //{10,5,2}
    pq.emplace(8);  //{10,8,5,2}

    cout << pq.top();       //10
    pq.pop();               //{8,5,2}

    // MINIMUN HEAP
    priority_queue<int, vector<int>, greater<int>> pq;
    //{10,8,5,2}
    cout << pq.top();       //2
}

// SETS
void explainSets(){
    set<int> st;
    st.insert(1);       //{1}
    st.insert(2);       //{1,2}
    st.insert(4);       //{1,2,4}
    st.emplace(3);      //{1,2,3,4}
    st.insert(2);       //{1,2,3,4}

    // {1, 2, 3, 4, 5}
    auto it = st.find(3);       //points adrs of '3'
    auto it = st.find(6);       //points adrs of st.end()
    st.erase(5); // erases 5 // takes logarithmic time

    int cnt = st.count(1);      //1 or 0 bcz unique

    auto it = st.find(3);
    st.erase(it); //takes constant time
    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); //{1, 4, 5} [first, last)

    // lower_bound() & upper_bound() func works the as in vectors
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}

// MULTI-SETS
void explainMS(){
    multiset<int>ms;
    ms.insert(1); //{1}
    ms.insert(1); // {1, 1}

    ms.erase(1);             // all 1's erased, as element is fed
    ms.erase(ms.find(1));    // only a single 1 erased, as iterator is fed
    // ms.erase(ms.find(1), ms.find(1)+2);     //[start,end)
    // +-operator not allowed in multiset as it has a tree data structure, iterators are bidirectional !!!!!!!!!
}

// MAPS
void explainMap(){
    map<int,int> mpp;
    map<int, pair<int,int>> mpp;
    map<pair<int,int>, int> mpp1;

    mpp[1] = 2;
    mpp.emplace(3,4);
    mpp.insert({2,7});
    mpp1[{2,3}] = 10;
    /*{1,2}
      {2,7}
      {3,4}*/

    //traversing a map, iterating
    for(auto it : mpp){
        cout << it.first << " " << it.second << endl;
    }
    // getting value
    cout << mpp[2];        //7
    cout << mpp[5];        //null

    auto it = mpp.find(1);
    // cout << *(it).second;        //giving some error ???
}

// Algorithms
bool comp (pair <int, int> p1, pair<int, int> p2){
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    // if same
    if (p1.first > p2.first) return true;
    return false;
}

void someAlgos(){

    vector<int> v;
    pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};

    sort(a+1, a+3);
    sort(v.begin(), v.end());       //for descending order add "greater<int>"

    // sort it according to second element
    // if second element is same, then sort it according to first element but in descending
    sort(a, a+3, comp);

    int num1 = 7;
    int cnt1 = __builtin_popcount(num1);
    
    long long num2 = 52767842628654872;
    int cnt2 = __builtin_popcountll(num2);

    
    string s = "312";
    sort (s.begin(), s.end());

    do{
        cout << s << endl;
    }while (next_permutation(s.begin(), s.end()));


    int arr[] = {1,6,5,9,1};
    int n  = 5;
    int maxi = *max_element(arr, arr+n);  
}

