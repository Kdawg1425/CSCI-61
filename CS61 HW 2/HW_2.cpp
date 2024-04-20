#include <iostream>
#include <queue>
#include <ctime>

using namespace std;



void lineClear(queue<int> &q);

int main() {
  double numOfStu = 0.0;
  double officeMin = 0.0;
  double waitMin = 0.0;
  double remainTime = 0;
  double tempTime = 0;
  double afterTime = 0;
  bool busy = false;
  queue <int> processTime;
  queue <int> arrivalTime;
  srand(time(NULL));
  for(int i = 0; i < 100; i++) {
    lineClear(processTime);
    lineClear(arrivalTime);
    tempTime = 60;
    afterTime = 0;
    for(int j = 0; j <= 60; j++) {
      if(remainTime - j == 0) {
        busy = false;
      }
      if((rand() % 10 + 1) > 7) {
        for(int k = 0; k < (rand() % 2 + 1); k++) {
          processTime.push(rand() % 15 + 1);
          arrivalTime.push(j);
        }
      }
      if(!busy && (remainTime - j) == 0) {
        if(processTime.empty()) {
          break;
        }
        remainTime = processTime.front();
        officeMin += processTime.front();
        processTime.pop();
        waitMin += (j - arrivalTime.front());
        arrivalTime.pop();
        numOfStu++;
        busy = true;
      }
    }
    while(!processTime.empty()) {
      tempTime += processTime.front();
      officeMin += processTime.front();
      afterTime += processTime.front();
      processTime.pop();
      waitMin += (tempTime - arrivalTime.front());
      arrivalTime.pop();
      numOfStu++;
    }
  }
  cout << "The average time a student spends waiting is " << waitMin/numOfStu/100 << " minutes." << endl;
  cout << "The average time a student spends with the professor is " << officeMin/numOfStu << " minutes." << endl;
  cout << "The average time the Professor spends after office hours " << afterTime/100 << " minutes." << endl;
}


void lineClear(queue<int> &q) {
  queue<int> empty;
  swap(q, empty);
}
