#include<iostream>
#include<list>              // DOUBLY linked list
//#include<forward_list>    // SINGLY linked list
#include<algorithm>         // to use find()
using namespace std;

int main(){
    
    list<int> l0;           //initialize int list, size 0
    list<int> l{1,2,3};     //initialixe with values
    l.push_back(1);         //{1,2,3,1} insert at tail, TC = O(1)
    l.push_front(2);        //{2,1,2,3,1} insert at head
    l.pop_back();           //{2,1,2,3} delete element at tail
    l.pop_front();          //{1,2,3} delete element at head
    l.front();              //returns head
    l.back();               //returns tail
    l.begin();              //returns iterator pointing to head
    l.end();                //returns iter pointing to one position after tail
    l.rbegin();             //returns the tail
    l.rend();               //returns iter pointing to one position brfore head
    l.clear();              //deletes all elements
    l.empty();              //boolean, list empty(true) or not(false)
    l.reverse();            //reveres
    l.size();               //returns number of elements
    
    list<int> l1{1,3,5};
    list<int> l2{2,4,6};
    l1.merge(l2);           //merge 2 sorted lists into l1{1,2,3,4,5,6}, l2 becomes empty

    list<int> l3 = l1;          //l3 is new list & copy of l1, TC = O(N) = SC, changes in l3 do not effect l1
    list<int>& l4 = l1;         //l4 refers to l1, TC = O(1) = SC, same list 2 names
    
    // inserting element at a position
    auto itr = l1.begin();          //list<int> ::iterator itr = l.begin()
    advance(itr, 1);                //moves pointer to 2nd pos (element 2), 0 base indexing
    l1.insert(itr, 15);             //inserts before pos pointed by itr {1,15,2,3,4,5,6}
    // itr still points to the ele 2 after inserting 15 before it
    advance(itr, 2);                //points to ele 4
    l1.insert(itr, 3, 25);          //insert multiple {1,15,2,3,25,25,25,4,5,6}
    l1.insert(l1.begin(), 5);       //insert at head {5,1,15,2,3,25,25,25,4,5,6}
    l1.insert(l1.end(), 10);        //insert at tail {5,1,15,2,3,25,25,25,4,5,6,10}

    // deleting element at a position
    list<int> l5 = l1;
    auto itr1 = l5.begin();
    advance(itr1, 3);               //points to ele 2
    l5.erase(itr1);                 //delete where itr points {5,1,15,3,25,25,25,4,5,6,10}
    auto first = l5.begin();
    auto last = l5.begin();
    advance(first, 2);              //points to ele 15
    advance(last, 6);               //points to ele 25 (last one)
    l5.erase(first, last);          //{5,1,25,4,5,6,10}, deletes [first, last)
    l5.erase(l5.begin());           //{1,25,4,5,6,10}, deletes head
    l5.erase(prev(l5.end()));       //{1,25,4,5,6}, l.erase(--l.end()), deletes tail

    list<int> l6 = {1,3,4,2,5};
    // Accessing Elements
    cout << l6.front() << endl;          //1
    cout << l6.back() << endl;           //5
    cout << *next(l6.begin(), 2);        //4

    // Updating Elements
    l6.front() = 11;                     //{11,3,4,2,5}
    auto itr2 = l6.begin();
    advance(itr2, 2);
    *itr2 = 10;                          //{11,3,10,2,5}

    // Finding Elements
    auto itr3 = find(l6.begin(), l6.end(), 4);
    if (itr3 != l6.end()) cout << "Found " <<*itr3;
    else cout << "Element Not Found!";

    return 0;
}