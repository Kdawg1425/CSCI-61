#include <iostream>
#include <stack>

using namespace std;

struct expTree {
  char value;
  expTree* left;
  expTree* right;
};

expTree* opNode(int op) {
  expTree *temp = new expTree;
  temp->left = nullptr;
  temp->right = nullptr;
  temp->value = op;
  return temp;
};


bool isOperator(char op)  {
  if(op == ' ') {
    return false;
  }
  else {
    return (!isalpha(op) && !isdigit(op));
  }
}

void print(expTree *tree)
{
    if(tree!= NULL){
        print(tree->left);
        std::cout << tree->value << " ";
        print(tree->right);
    }
}


expTree* buildTree(string prefix) {
    stack<expTree*> s;
    expTree *op, *op1, *op2;
    string temp;
    for (size_t i= 0; i < prefix.size(); i++) {
        if (!isOperator(prefix[i])){
            op = opNode(prefix[i]);
            s.push(op);
        }
        else{
            op = opNode(prefix[i]);
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            op->right = op1;
            op->left = op2;
            s.push(op);
        }
    }

    op = s.top();
    s.pop();

    return op;
}

string prefixToPostfix(string prefix)
{
  stack<string> s;
  int length = prefix.size();
  for (int i = length - 1; i >= 0; i--)
  {
    if (isOperator(prefix[i])){
      string op1 = s.top(); s.pop();
      string op2 = s.top(); s.pop();
      string results = op1 + op2 + prefix[i];
      s.push(results);
    }
    else
    {
      s.push(string(1, prefix[i]));
    }
  }
  return s.top();
}


//Got some guidence from my group mates.

int main() {
  string exp = prefixToPostfix("+*72/34");
  expTree* tree = buildTree(exp);
  print(tree);
  cout << endl;
  return 0;
}
