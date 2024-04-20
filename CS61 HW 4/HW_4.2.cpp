#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

struct Student {
  int question;
  int wait;
  int priority;
};

Student createStu(int t) {
  Student temp;
  temp.question = rand() % 15 + 1;
  temp.wait = t;
  temp.priority = rand() % 3 + 1;
  return temp;
}

bool operator>(const Student& s1, const Student& s2) {
  return s1.priority > s2.priority;
}


int main() {

  double numOfStu = 0.0;
  double officeMin = 0.0;
  double waitMin = 0.0;
  double afterMin = 0.0;
  double remainTime = 0.0;
  double tempTime;

  bool busy = false;
  Student stu;
  priority_queue<Student, vector<Student>, greater<Student> > queue;
  srand(time(NULL));
  for(int i = 0; i < 100; i++) {
    remainTime = 0.0;
    for(int j = 0; j <= 60; j++) {
      if(remainTime - j == 0) {
        busy = false;
      }
      if((rand() % 10 + 1) > 7) {
        for(int k = 0; k < (rand() % 2 + 1); k++) {
          stu = createStu(j);
          queue.push(stu);
        }
      }
      if(!busy && (remainTime - j) == 0) {
        if(queue.empty()) {
          break;
        }
        remainTime = queue.top().question;
        officeMin += queue.top().question;
        waitMin += (j - queue.top().wait);
        queue.pop();
        numOfStu++;
      }
    }
    if((remainTime - 60) > 0) {
      tempTime = 60 + (remainTime - 60);
    }
    while(!queue.empty()) {
      tempTime += queue.top().question;
      officeMin += queue.top().question;
      afterMin += queue.top().question;
      waitMin += (tempTime - queue.top().wait);
      queue.pop();
      numOfStu++;
    }
  }
  cout << "The average time a student spends waiting is " << waitMin/numOfStu/100 << " minutes." << endl;
  cout << "The average time a student spends with the professor is " << officeMin/numOfStu << " minutes." << endl;
  cout << "The average time the Professor spends after office hours " << afterMin/100.0 << " minutes." << endl;
  cout << endl;


  //Test Priority Queue
  Student s1 = {5, 4, 2};
  Student s2 = {6, 1, 1};
  Student s3 = {3, 2, 3};
  priority_queue<Student, vector<Student>, greater<Student> > test;
  test.push(s1);
  test.push(s2);
  test.push(s3);
  cout << "Test Priority Queue" << endl;
  cout << test.top().priority << endl;
  test.pop();
  cout << test.top().priority << endl;
  test.pop();
  cout << test.top().priority << endl;
  test.pop();
}
