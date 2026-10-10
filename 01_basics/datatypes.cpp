#include <bits/stdc++.h>
using namespace std;

int main(){

    // integer : int, long, long long
    // decimal : flout, double, long double
    
    // string and getline
    /*string s1, s2;
    cin >> s1 >> s2;            //doesnt read anything after space
    cout << s1 << " " << s2; */

    string str1 = "hello \n";
    cout << str1;
    string str2;
    getline(cin, str2);
    cout << str2 << " \n";

    //character : char
    char ch1 = '#';
    cout << ch1;
    char ch2;
    cin >> ch2;
    cout << ch2;

    // every datatype take up certain memory & depending on our req we decide what to use 

    return 0;
}