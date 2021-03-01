#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
//We are just multiplying n with its self minus one each time for its length
int factorialFor(int n){
    int ret = 1;
    int num = n;
    for (int i = n; i > 0; i--) {
        ret *= num;
        num--;
    }
    return ret;
}
//We are  multiplying n with its self minus one each time for its length
int factorialWhile(int n){
    int ret = 1;
    while (n!=0){
        ret *= n;
        n--;
    }
    return ret;
}
//We just return n multiplied by itself as we break down n more with the recursion
int factorialRec(int n){
    if(n==0){
        return 1;
    }
    return n * factorialRec(n-1);
}
//For loop
int fibFor(int n){
    if (n==1){
        return 1;
    }
    if (n==0){
        return 0;
    }
    else{
        int before = 0;
        int after = 1;
        int newTerm = 0;
        for (int i = 1; i < n; ++i) {
            newTerm = after + before;
            before = after;
            after = newTerm;
        }
        return newTerm;
    }
}
// Fib while loop we start from n-1 because we account for the first step of the fib sequence when we initalize first term
// and the second term
int fibWhile(int n){
    if (n==1){
        return 1;
    }
    if (n==0){
        return 0;
    }
    else{
        int counter = n-1;
        int firstTerm = 0;
        int secondTerm = 1;
        int newTerm = 0;
        while(counter>0){
            newTerm = firstTerm + secondTerm;
            firstTerm = secondTerm;
            secondTerm = newTerm;
            counter--;
        }
        return newTerm;
    }
}
// Our base cases are when n = 1 or 0, we reach both because we are breaking down the two largest number we will get from n
int fibRecursive(int n){
    if (n<=1){ //If n is 1 or 0 return itself
        return n;
    }
    return fibRecursive(n-1) + fibRecursive(n-2);
}
//We can break down the problem into small bites because of how it works, bascially each problem can be shrunken down
//the original 3 circles one we want.
void hanoiTowerRec(int n, char fromRod, char toRod, char tempRod){
        if (n==1){
            cout << "Move ring 1 from: " << fromRod << " to " << toRod << endl;
            return;
        }
        hanoiTowerRec(n-1, fromRod, tempRod, toRod);
        cout << "Move ring" << n << "from: " << fromRod << " to " << toRod << endl;
        hanoiTowerRec(n-1, tempRod, toRod, fromRod);
}
//Dont know how to do
void hanoiTowerIter(int n, stack<int> from, stack<int> destination, char frm, char dest){
    int steps = pow(2,n) - 1;

}
void makeMove(stack<int> self, stack<int> destination){
    if(destination.empty()){
        destination.push(self.top());
        self.pop();
    }
    else if(self.empty()){
        self.push(destination.top());
        destination.pop();
    }
    else{
        if (self.top()>destination.top()){
            self.push(destination.top());
            destination.pop();
        }
        else{
            destination.push(self.top());
            self.pop();
        }
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << factorialFor(7) << endl;
    cout << factorialWhile(7) << endl;
    cout << factorialRec(7) << endl;
    cout << fibFor(10) << endl;
    cout << fibWhile(10) << endl;
    cout << fibRecursive(10) << endl;
    hanoiTowerRec(4,'A','C','B');
    return 0;
}
