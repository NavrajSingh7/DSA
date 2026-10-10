//      RECURSION = when a func calls itself until a specified condition is met.
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void f1();
void nameNtimes(int i, int n);
void nTo1(int i, int n);
void oneToN(int i, int n);
void sumOfN1(int i, int sum);
int sumOfN2(int n);
int factorial1(int n);
void factorial2(int i, int n);
void arrayReverse(int i, char arr[], int n);
bool palindrom(int i, string &s);
int fibonacci(int n); // MULTIPLE RECURSION CALLS

int main() {

  int i;
  int n;
  cout << "entet n: ";
  cin >> n;

  f1();
  nameNtimes(1, n);
  nTo1(n, n);
  oneToN(n, n); // by backtracking

  int sum;
  sumOfN1(n, 0);              // parameterised way
  cout << endl << sumOfN2(n); // functional recursion

  int prdct;
  cout << endl << factorial1(n); // functional recursion
  factorial2(n, 1);              // parameterised way

  char arr[n]; // WILL FIX WHEN I LEARN VECTORS
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  arrayReverse(0, arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  // lc q125
  string s;
  cin >> s;
  cout << s << endl;
  if (palindrom(0, s) == 1)
    cout << "is palindrom" << endl;
  else
    cout << "is not a palindrom" << endl;

  cout << fibonacci(n);

  return 0;
}

void f1() {
  if (cnt == 3)
    return;
  cout << cnt << endl;
  cnt++;
  f1(); // not executed, stored in stack
}
void nameNtimes(int i, int n) {
  if (i > n)
    return;
  cout << "name" << endl;
  nameNtimes(i + 1, n);
}
void nTo1(int i, int n) {
  if (i < 1)
    return;
  cout << i << endl;
  nTo1(i - 1, n);
}
void oneToN(int i, int n) {
  if (i < 1)
    return;
  oneToN(i - 1, n);
  cout << i << endl;
}
void sumOfN1(int i, int sum) {
  if (i < 1) {
    cout << sum;
    return;
  }
  sumOfN1(i - 1, sum + i);
}
int sumOfN2(int n) {
  if (n == 0)
    return 0;
  return n + sumOfN2(n - 1);
}
int factorial1(int n) {
  if (n == 0)
    return 1;
  return n * factorial1(n - 1);
}
void factorial2(int i, int prdct) {
  if (i == 1) {
    cout << endl << prdct << endl;
    return;
  }
  factorial2(i - 1, prdct * i);
}
void arrayReverse(int i, char arr[], int n) {
  // if(l >= r) return;
  // swap(arr[l], arr[r]);
  // arrayReverse(l+1, r-1);
  if (i >= n / 2)
    return;
  swap(arr[i], arr[n - i - 1]);
  arrayReverse(i + 1, arr, n);
}
// lc q125
bool palindrom(int i, string &s) {
  if (i >= s.size() / 2)
    return true; // s.size() = size of string s
  if (s[i] != s[s.size() - i - 1])
    return false;
  return palindrom(i + 1, s);
}
int fibonacci(int n) {
  if (n <= 1)
    return n;
  // int last = fibonacci(n-1);
  // int slast = fibonacci(n-2);
  // return last + slast;
  return fibonacci(n - 1) + fibonacci(n - 2);
}