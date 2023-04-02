#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

void printStack(stack<char> stack) {
    string reverse;
    while (!stack.empty()) {
        if(stack.top() == '(')
            stack.top() = ')';
        else if(stack.top() == ')')
            stack.top() = '(';
         reverse += stack.top();
        stack.pop();
    }
    cout << setw(8) << reverse;
}

int opPrecedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

string inToPost(string expression){
    stack<char> opStack;
    string finalExp;
    
    for(int i = 0; i < expression.size(); i++){
        cout << left << setw(8) << expression[i];
        if(isalpha(expression[i]) || isdigit(expression[i])){
            finalExp += expression[i];
        }
        else if(expression[i] == '(')
            opStack.push(expression[i]);
        
        
        else if(expression[i] == ')'){
            while(!opStack.empty() && opStack.top() != '('){
                finalExp += opStack.top();
                opStack.pop();
            }
            
            if(!opStack.empty() && opStack.top() == '(')
                opStack.pop();
        }
        
        else{
            while(!opStack.empty() && opPrecedence(opStack.top()) >= opPrecedence(expression[i])){
                finalExp += opStack.top();
                opStack.pop();
            }
            opStack.push(expression[i]);
        }
        printStack(opStack);
        cout << setw(8) << finalExp;
        
        cout << endl;
    }
    
    while(!opStack.empty()){
        finalExp += opStack.top();
        opStack.pop();
    }
    
    return finalExp;
}

int endPre(string strExp, int first) {
    int last = strExp.length() - 1;
    if (first < 0 || first > last)
        return -1;
    char ch = strExp[first];
    if (isalpha(ch)) // Check if ch is an identifier
        return first;
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') // Check if ch is an operator
    {
        int firstEnd = endPre(strExp, first + 1); // Find the end of the first prefix expression
        if (firstEnd > -1)
            return endPre(strExp, firstEnd + 1); // Find the end of the second prefix expression
        else
            return -1;
    }
    else
        return -1;
}

bool isPrefix(string strExp) {
    int lastChar = endPre(strExp, strExp.length() - 1);
    return (lastChar >= 0) && (lastChar == strExp.length() - 1);
}

float evaluatePrefix(string strExp) {
    int strLength = strExp.length();
    if (strLength == 1)
        return strExp[0] - '0';
    else {
        // Find the end of the first prefix expression
        int endFirst = endPre(strExp, 1);
        if (endFirst < 0) {
            cout << "Invalid prefix expression: " << strExp << endl;
            return 0;
        }
        // Recursively evaluate the first prefix expression
        float operand1 = evaluatePrefix(strExp.substr(1, endFirst));
        // Find the end of the second prefix expression
        int endSecond = endPre(strExp, endFirst+1);
        if (endSecond < 0) {
            cout << "Invalid prefix expression: " << strExp << endl;
            return 0;
        }
        // Recursively evaluate the second prefix expression
        float operand2 = evaluatePrefix(strExp.substr(endFirst + 1, endSecond - endFirst));
        // Evaluate the prefix expression
        float result;
        switch (strExp[0]) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                cout << "Invalid operator: " << strExp[0] << endl;
                result = 0;
        }
        return result;
    }
}

string convertPreToPost(string preExp) {
    int preLength = preExp.length();
    char ch = preExp[0];
    string postExp = "";
    if (islower(ch)) {
        // Base case - single identifier
        postExp += ch;
    } else {
        // preExp has the form <operator> <prefix1> <prefix2>
        int endFirst = endPre(preExp, 1); // Find the end of prefix1
        // Recursively convert prefix1 into postfix form
        postExp += convertPreToPost(preExp.substr(1, endFirst));
        // Recursively convert prefix2 into postfix form
        postExp += convertPreToPost(preExp.substr(endFirst + 1, preLength - 1));
        postExp += ch; // Append the operator to the end of postExp
    }
    return postExp;
}

float evaluatePostfix(string strExp) {
    stack<int> intStack;

    for (char c : strExp) {
        if (isdigit(c)) {
            intStack.push(c - '0');  // convert digit char to integer value
        }
        else if (isalpha(c)) {
            intStack.push(c);  // push ASCII value of letter onto stack
        }
        else if (c == '+' && intStack.size() >= 2) {
            int op2 = intStack.top(); intStack.pop();
            int op1 = intStack.top(); intStack.pop();
            intStack.push(op1 + op2);
        }
    }

    return intStack.top();
}
int main(){
    //------------------------------Stacks-----------------------------
  cout << "Stacks" << endl;
      cout << endPre("+*ab-cde", 0) << endl;
      string strExpPre = "+*ac-dcee";
      bool result = isPrefix(strExpPre);
      if (result) {
          cout << "Valid prefix expression." << endl;
      } else {
          cout << "Not a valid prefix expression." << endl;
      }
      cout << "Result of " << strExpPre << " is: " << evaluatePrefix(strExpPre) << endl;
      cout << strExpPre << " to post : " << convertPreToPost(strExpPre) << endl;
  
    cout << "----------------Postfix------------" << endl;
      cout << "To Prefix :" << evaluatePostfix(strExpPre) << endl;
      
      cout << "---------------Infix to PostFix------------------------------" << endl;
      cout << inToPost("(9-4+7)*9-((2+8)*4)") << endl;
  
  return 0;
}