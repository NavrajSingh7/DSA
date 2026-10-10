#include <bits/stdc++.h>
using namespace std;

int main() {

  /*
  int age = 0;
  cout << "enter your age: ";
  cin >> age;

  if(age >= 18){
      cout << "You are an adult";
  }
  else{
      cout << "You are not an adult";
  }
  */

  int marks;
  cout << "enter marks: ";
  cin >> marks;

  if (marks < 25) {
    cout << "grade F";
  } else if (marks <= 44) { // 'marks >= 25 &&' not needed due to the presence
                            // of elseif statement
    cout << "grade E";
  } else if (marks <= 49) {
    cout << "grade D";
  } else if (marks <= 59) {
    cout << "grade C";
  } else if (marks <= 79) {
    cout << "grade B";
  } else if (marks <= 100) {
    cout << "grade A";
  }

  return 0;
}
