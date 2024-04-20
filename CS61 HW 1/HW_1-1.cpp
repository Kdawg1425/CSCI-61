#include <iostream>
#include <stack>
#include <string>


using namespace std;

string infixToPrefix(string input);

string prefixToInfix(string input);

// Function to check if given character is
// an operator or not.
bool isOperator(char c);

// Function to find priority of given
// operator.
int getPriority(char C);

int main() {
  /*
  string s1 = "A * B + C / D";       //You can use these to test if you don't
  string s2 = "A * ( B + C ) / D";   //want to type in an expression
  string r1 = infixToPrefix(s1);
  string r2 = infixToPrefix(s2);
  cout << infixToPrefix(s1) << endl;
  cout << infixToPrefix(s2) << endl;
  cout << prefixToInfix(r1) << endl;
  cout << prefixToInfix(r2) << endl;
  */
  string choice;
  string expression;
  do {
    cout << "What conversion do you want to preform? Type in corresponding number." << endl;
    cout << "1 - Infix To Prefix" << endl;
    cout << "2 - Prefix To Infix" << endl;
    cout << "3 - Exit" << endl;
    getline(cin, choice);
    if(choice == "1") {
      cout << "Enter infix expression." << endl;
      getline(cin, expression);
      cout << endl;
      cout << infixToPrefix(expression) << endl;
    }
    else if(choice == "2") {
      cout << "Enter prefix expression." << endl;
      getline(cin, expression);
      cout << endl;
      cout << prefixToInfix(expression) << endl;
    }
    else if(choice == "3") {
      break;
    }
    else {
      cout << "Invalid Command" << endl;
    }
    cout << endl;
  } while(choice != "3");
  return 0;
}


bool isOperator(char op)  {
  if(op == ' ') {
    return false;
  }
  else {
    return (!isalpha(op) && !isdigit(op));
  }
}

int getPriority(char op) {
    if (op == '-' || op == '+')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}

//Got help from geeksforgeeks.org  Post Title: Infix to Prefix conversion using two stacks
//I didn't understand the problem. Looking at the code for the website helped me see how to
//go about doing the code. Break if up via chuncks like parenthesies or single operations
string infixToPrefix(string input) {
  stack<string> operands;
  stack<char> operators;
  string convert;
  string temp = "";
  string op1 = "";
  string op2 = "";
  string op;
  string result;
  for(int i = 0; i < input.length(); i++) {
    if(input[i] == '(') {
      operators.push(input[i]);
    }
    else if(input[i] == ' ') { //skips spaces
    }
    else if (input[i] == ')') {
      while (!operators.empty() && operators.top() != '(') { //Gets previous two operands and one operator to chunck together
        // operand 1
        op1 = operands.top();
        operands.pop();
        // operand 2
        op2 = operands.top();
        op2 = " ";
        operands.pop();
        // operator
        op = operators.top();
        operators.pop();
        op += " ";
        // Add operands and operator
        // in form operator +
        // operand1 + operand2.
        temp = op + op2 + op1;
        operands.push(temp);
      }
      // Pop opening bracket from
      // stack.
      operators.pop();
    }
    else if (!isOperator(input[i])) { //Push Operands into an operand stack.
      convert = "";
      do {
        convert += input[i];      //Used to convert char to string
        i++;
      }while(!isOperator(input[i]));
      i--;
      operands.push(convert);  // need to work of spacing
    }
    else {
      while (!operators.empty() && getPriority(input[i]) <= getPriority(operators.top())) { //Organizes
        op1 = operands.top();
        operands.pop();
        op2 = operands.top();
        op2 += " ";
        operands.pop();
        op = operators.top();
        op += " ";
        operators.pop();
        temp = op + op2 + op1;
        operands.push(temp);
      }
      operators.push(input[i]);
    }
  }
  while (!operators.empty()) {
    op1 = operands.top();
    operands.pop();
    op2 = operands.top();
    op2 += " ";
    operands.pop();
    op = operators.top();
    op += " ";
    operators.pop();
    temp = op + op2 + op1;
    operands.push(temp);
  }
  while(!operands.empty()) {   //Helps convert to string format and stops code from hitting segmentation error
    result += operands.top();
    operands.pop();
  }
  return result;
}


string prefixToInfix(string input) {
  stack<string> expression;
  string num1;
  string num2;
  string temp;
  string convert;
  for(int i = input.length()-1; i >= 0; i--) {
    if(input[i] == ' ') {
    }
    else if(isOperator(input[i])) {
      num1 = expression.top();
      expression.pop();
      num2 = expression.top();
      expression.pop();
      temp = "(" + num1 + " " + input[i] + " " + num2 + ")";
      expression.push(temp);
    }
    else {
      convert = "";
      while(input[i] != ' ') {
        convert += input[i];
        i--;
      }
      reverse(convert.begin(),convert.end());
      expression.push(convert);
    }
  }
  return expression.top();
}
