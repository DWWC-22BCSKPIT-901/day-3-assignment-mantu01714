//Q.4: Basic Calculator

#include <iostream>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> nums, ops;
    int num = 0, result = 0, sign = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            nums.push(result);
            ops.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            num = 0;
            result = nums.top() + ops.top() * result;
            nums.pop();
            ops.pop();
        }
    }
    result += sign * num;
    return result;
}

int main() {
    string s;
    cout << "Enter the expression: ";
    getline(cin, s);
    cout << "Result: " << calculate(s) << endl;
    return 0;
}
