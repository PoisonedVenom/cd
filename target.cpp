#include<bits/stdc++.h>


using namespace std;

// Define a class to represent a three-address code instruction
class ThreeAddressCode {
public:
    string op;
    string arg1;
    string arg2;
    string result;

    ThreeAddressCode(string op, string arg1, string arg2, string result)
        : op(op), arg1(arg1), arg2(arg2), result(result) {}

    void print() {
        cout << result << " = ";
        if (op != "") {
            cout << arg1 << " " << op << " " << arg2;
        } else {
            cout << arg1;
        }
        cout << endl;
    }
};

// Define a function to generate a unique temporary variable name
string new_temp() {
    static int count = 0;
    return "t" + to_string(count++);
}

// Define the three-address code generator function
vector<ThreeAddressCode> generate_tac(string const& expression) {
    stack<string> operators;
    stack<string> operands;
    vector<ThreeAddressCode> tac;
    unordered_map<string, int> precedence{{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}};

    for (int i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            string operand = "";
            while (i < expression.length() && isdigit(expression[i])) {
                operand += expression[i++];
            }
            --i;
            operands.push(operand);
        } else if (expression[i] == '(') {
            operators.push("(");
        } else if (expression[i] == ')') {
            while (operators.top() != "(") {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                string temp = new_temp();
                tac.emplace_back(operators.top(), op1, op2, temp);
                operands.push(temp);
                operators.pop();
            }
            operators.pop();
        } else {
            string op1 = "";
            while (!operators.empty() && precedence[operators.top()] >= precedence[string(1, expression[i])]) {
                string op2 = operands.top();
                operands.pop();
                op1 = operands.top();
                operands.pop();
                string temp = new_temp();
                tac.emplace_back(operators.top(), op1, op2, temp);
                operands.push(temp);
                operators.pop();
            }
            operands.push(op1);
            operators.push(string(1, expression[i]));
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();
        string temp = new_temp();
        tac.emplace_back(operators.top(), op1, op2, temp);
        operands.push(temp);
        operators.pop();
    }

    return tac;
}

// Define a function to print the three-address code
void print_tac(vector<ThreeAddressCode> const& tac) {
    for (auto const& code : tac) {
        code.print();
    }
}

int main() {
    string expression = "5+6*7/2-1";
    vector<ThreeAddressCode> tac = generate_tac(expression);
    print_tac(tac);
    return 0;
}
