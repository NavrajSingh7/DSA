#include <bits/stdc++.h>
using namespace std;

//  n = total rows, i = current row number , j = coloum number

void pattern1(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            cout << "* "; 
        }
        cout << endl;
    }
}

void pattern2(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << "* "; 
        }
        cout << endl;
    }
}

void pattern3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j << " ";
        }
        cout << endl;
    }   
}

void pattern4(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << i << " ";
        }
        cout << endl;
    }   
}

void pattern5(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1 ; j++){
            cout << "* ";
        }
        cout << endl;
    }   
}

void pattern6(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1 ; j++){
            cout << j << " ";
        }
        cout << endl;
    }   
}

void pattern7(int n){
    for(int i = 1; i <= n; i++){
        // space
        for(int j = 1; j <= n-i+1 ; j++){
            cout << " ";
        }
        // stars
        for(int j = 1; j <= 2*i-1 ; j++){
            cout << "*";
        }
        // space
        for(int j = 1; j <= n-i+1 ; j++){
            cout << " ";
        }
        cout << endl;
    }   
}

void pattern8(int n){
    for(int i = 1; i <= n; i++){
        // space
        for(int j = 1; j <= i ; j++){
            cout << " ";
        }
        // stars
        for(int j = 1; j <= 2*n-(2*i-1) ; j++){
            cout << "*";
        }
        // space
        for(int j = 1; j <= i ; j++){
            cout << " ";
        }
        cout << endl;
    }   
}

void pattern9(int n){
    for(int i = 1; i <= 2*n-1; i++){
        int stars = i;
        if(i > n) stars = 2*n-i;
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n){
    int start = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0) start = 0;
        else start = 1;
        for(int j = 1; j <= i; j++){
            cout << start << " ";
            start = 1- start;
        }
        cout << endl;
    }
}

void pattern11(int n){
    for(int i = 1; i <= n; i++){
        // space
        for(int j = 1; j <= n-i; j++){
            cout << " ";
        }
        // stars
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern12(int n){
    for(int i = 1; i <= n; i++){
        // stars
        for(int j = 1; j <= i; j++){
            cout << j;
        }
        // space
        for(int j = 1; j <= 2*(n-i); j++){
            cout << " ";
        }
        // stars
        for(int j = i; j >= 1; j--){
            cout << j;
        }
        cout << endl;
    }
}

void pattern13(int n){
    int num = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void pattern14(int n){
    for(int i = 1; i <= n; i++){
        for(char ch = 'A'; ch <= 'A'+i-1; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern15(int n){
    for(int i = 1; i <= n; i++){
        for(char ch = 'A'; ch <= 'A'+(n-i); ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern16(int n){
    for(int i = 1; i <= n; i++){
        char ch = 'A'+i-1;
        for(int j = 1; j <= i; j++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern17(int n){
    for(int i = 1; i <= n; i++){
        // space
        for(int j = 1; j <= n-i+1; j++){
            cout << " ";
        }
        // characters 
        char ch = 'A';
        int breakpoint = (2*i-1) / 2;
        for(int j = 1; j <= 2*i-1; j++){
            cout << ch;
            if(j <= breakpoint) ch++;
            else ch--;
        }
        // space
        for(int j = 1; j <= n-i+1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern18(int n){
    for(int i = 1; i <= n; i++){
        for(char ch = 'E'-i+1; ch <= 'E'; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern19(int n){
    for(int i = 1; i <= n; i++){
        // stars
        for(int j = 1; j <= n-i+1; j++){
            cout << "*";
        }
        // sapces
        for(int j = 1; j <= 2*(i-1); j++){
            cout << " ";
        }
        // stars
        for(int j = 1; j <= n-i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++){
        // stars
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        // sapces
        for(int j = 1; j <= 2*(n-i); j++){
            cout << " ";
        }
        // stars
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern20(int n){
    int space = 2*(n-1);
    for(int i = 1; i <= 2*n-1; i++){
        int stars = i;
        if(i > n) stars = 2*n-i;
        // stars
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }
        // spaces
        for(int j = 1; j <= space; j++){
            cout << " ";
        }
        // stars
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }
        cout << endl;
        if(i < n) space -= 2;
        else space += 2;
    }
}

void pattern21(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            if(i == 1 || j == 1 || i == n || j == n){
                cout << "*";
            }
            else cout << " ";
        }
        cout << endl;
    }
}

void pattern22(int n){
    cout << "HELP";
}

int main(){

    // int t;          // t = test case
    // cin >> t;
    // for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        pattern1(n);
        pattern2(n);
        pattern3(n);
        pattern4(n);
        pattern5(n);
        pattern6(n);
        pattern7(n);
        pattern8(n);
        pattern9(n);
        pattern10(n);
        pattern11(n);
        pattern12(n);
        pattern13(n);
        pattern14(n);
        pattern15(n);
        pattern16(n);
        pattern17(n);
        pattern18(n);
        pattern19(n);
        pattern20(n);
        pattern21(n);
        pattern22(n);
        // }

    return 0;
}