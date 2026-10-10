#include <bits/stdc++.h>
using namespace std;

    // funcs are a set of code which does smthg for you
    // use to modularise a code, increases readability, help to write same code many times 
    // 4 main types: void, return, parameterised, non parameterised
    
// void printName(string name){
//     cout << "hey " << name;
// }    
// int main(){
//     string name;
//     cin >> name;
//     printName(name);

//     string name2;
//     cin >> name2;
//     printName(name2);

// int sum(int num1, int num2){
//     int num3 = num1 + num2;
//     return num3;
// }
// int main(){

//     int num1, num2;
//     cin >> num1 >> num2;
//     int res = sum(num1, num2);
//     cout << res;


// ***PASS BY VALUE***

// void doSomething(int num){
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
// }
// int main(){
//     int num = 10;
//     doSomething(num);       // the original numbers isnt sent, rather a copy is 
//     cout << num << endl;


// ***PASS BY REFERENCE***
// (ARRAY IS ALWAYS SENT WITH REFERENCE)

void doSmthg(int &num2){        // the original numbers is sent/recieved
    cout << num2 << endl;
    num2 += 5;
    cout << num2 << endl;
    num2 += 5;
    cout << num2 << endl;
}
int main(){

    int num2 = 10;
    doSmthg(num2);
    cout << num2 << endl;

    return 0;
}