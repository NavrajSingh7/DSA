#include <bits/stdc++.h>
using namespace std;

int count1 (int n);
int count2 (int n);
int revNum (int n);
bool isPalindrome(int n);
bool isArmstrong(int n);
int allDivisors1(int n);
int allDivisors2(int n);
bool(isPrime1(int n));
bool(isPrime2(int n));
int HCF1(int n, int n1);
int HCF2(int n, int n1);

int main(){

    int n, n1;
    cin >> n >> n1;

    int cnt1 = count1(n);
    cout << cnt1 << endl;

    int cnt2 = count2(n);
    cout << cnt2 << endl;

    int revNo = revNum(n);
    cout << revNo << endl;

    if(isPalindrome(n)){
        cout << n << " is a palindrome" << endl;
    }
    else{
        cout << n << " isnt a palindrome" << endl;
    }

    cout << "n = " << n << endl;
    cout << "isArmstrong = " << isArmstrong(n) << endl;
    if(isArmstrong(n)){
        cout << n << " is an armstrong" << endl;
    }
    else{
        cout << n << " is not an armstrong" << endl;
    }

    allDivisors1(n);
    allDivisors2(n);
    cout << endl;

    if(isPrime1(n)){
        cout << n << " is prime" << endl;
    }
    else{
        cout << n << " is not prime" << endl;
    }
    if(isPrime2(n)){
        cout << n << " is prime" << endl;
    }
    else{
        cout << n << " is not prime" << endl;
    }

    int gcd = HCF1(n, n1);
    cout << "hcf is " << gcd << " ";
    int gcd1 = HCF2(n, n1);
    cout << "hcf is " << gcd;


    return 0;
}

int count1(int n){
    int cnt1 = 0;
    while (n>0){
        int lastdigit = n % 10;     // this is just to extract all digits
        cnt1++;
        n  = n / 10;
    }
    return cnt1;
}

int count2(int n){
    int cnt2 = (int)(log10(n) + 1);
    return cnt2;
}

// lc q7
int revNum(int n){
    int revNo = 0;
    while(n != 0){
        int ld = n % 10;

        // checking for overflow
        if (revNo > INT_MAX / 10 || (revNo == INT_MAX/10 && ld > 7)){
            return 0;
        }
        if (revNo < INT_MIN / 10 || (revNo == INT_MIN /10 && ld < -8)){
            return 0;
        }

        revNo = (revNo  * 10) + ld;
        n = n / 10;
    }
    return revNo;
}

// lc q9
bool isPalindrome(int n){
    int N = n;
    int revNo = 0;
    while(n > 0){
        int ld = n % 10;
        revNo = (revNo * 10) + ld;
        n /= 10;
    }return revNo == N;
}

// lc q1134
bool isArmstrong(int n){
    int N = n;
    int sum = 0;
    int cnt = (int)(log10(n) + 1);
    while(n > 0){
        int ld = n % 10;
        sum = sum + round(pow(ld, cnt));
        n /= 10;
    }return sum == N; 
}

int allDivisors1(int n){
    for(int i = 1; i <= n; i++){
        if(n % i ==  0){
            cout << i << " ";
        }
    }
}

int allDivisors2(int n){

    vector<int> ls;
// O(sqrt(n))
    for(int i = 1; i*i <= n; i++){      // i*i<= n, is another way of writing sqrt(n) to avoid calling the sqrt func
        if(n % i ==  0){
            ls.push_back(i);
            if(n/i != i){
                ls.push_back(n/i);
            }
        }
    }
// O(allDiv * log(allDiv))
    sort(ls.begin(), ls.end());
// O(allDiv)
    for(auto it : ls) cout << it << " "; 
}

bool isPrime1(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            cnt++;
        }
    }
    if(cnt == 2){
        return true;
    }
    else{
        return false;
    }
}

bool isPrime2(int n){
    int cnt = 0;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            cnt ++;
            if(n/i != i){
                cnt++;
            }
        }
    }
    if(cnt == 2){
        return true;
    }
    else{
        return false;
    }
}

int HCF1(int n, int n1){
    int gcd = 1;
    for(int i = 1; i <= min(n,n1);  i++){
        if(n % i == 0 && n1 % i == 0){
            gcd = i;
        }
    }
    return gcd;
}

int HCF2(int n, int n1){
    while(n > 0 && n1 > 0){
        if(n > n1) n = n % n1;
        else n1 = n1 % n;
    }
    if(n == 0) return n1;
    else return n;
}