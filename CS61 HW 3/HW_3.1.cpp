#include <iostream>

using namespace std;

// There are 14 different binary trees with 4 nodes

//The algorithm for calulating the number of differnt binary trees that could be
//created with x amount of nodes is called the Cataln Numbers. The equation
//is (2n)!/(n+1)!n!. N represents the number of nodes.
//Below is a recursive function that calculates the different number of binary
//trees with a given amount of nodes.  

int numBTrees(int nodes);

int main() {
  int n;
  cout << "Enter the number of nodes" << endl;
  cin >> n;
  cout << n << " nodes can create " << numBTrees(n) << " different possible binary trees" << endl;
}

int numBTrees(int nodes) {
  if(nodes == 0 || nodes == 1) {
    return 1;
  }
  else {
    int i = 1;
    int total = 0;
    while(i <=  nodes) {
      total += numBTrees(i-1)*numBTrees(nodes-i);
      i++;
    }
    return total;
  }
}
