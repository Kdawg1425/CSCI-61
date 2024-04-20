#include <iostream>
#include <queue>
#include <map>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

struct Student {
  int question;
  int wait;
  int priority;
};

struct Person {
  string name;
  string topic;
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

void lineClear(priority_queue<Student, vector<Student>, greater<Student> > &q) {
  priority_queue<Student, vector<Student>, greater<Student> > empty;
  swap(q, empty);
}

string generateTopic(int num) {
  if(num == 1) {
    return "Stacks";
  }
  if(num == 2) {
    return "Queues";
  }
  if(num == 3) {
    return "BST";
  }
  if(num == 4) {
    return "Heaps";
  }
  if(num == 5) {
    return "B-Trees";
  }
  else {
    return "Homework";
  }
}


void descendSortname(Person arr[], double n){
  int s = int(n);
  Person arr2[s];
  int num1;
  string temp1;
  int num2;
  string temp2;
  arr2[s-1].name=arr[0].name;
  arr2[s-1].topic=arr[0].topic;
  for(int i=1;i<s;i++){
    for(int j=s-1;j>=0;--j){
      temp1 = arr[i].name.substr(7,arr[i].name.length());
      temp2 = arr2[j].name.substr(7,arr[j].name.length());
      num1 = stoi(temp1);
      num2 = stoi(temp2);
      if(num1<=num2){
        for(int k=1;k<j+1;k++){
          arr2[k-1].name=arr2[k].name;
          arr2[k-1].topic=arr2[k].topic;
        }
        arr2[j].name=arr[i].name;
        arr2[j].topic=arr[i].topic;
        break;
      }
    }
  }
  for(int i=0;i<n;i++){
    arr[i].name=arr2[i].name;
    arr[i].topic=arr2[i].topic;
  }
}

void ascendSortname(Person arr[], double n){
  int s = int(n);
  Person arr2[s];
  int num1;
  string temp1;
  int num2;
  string temp2;
  arr2[s-1].name=arr[0].name;
  arr2[s-1].topic=arr[0].topic;
  for(int i=1;i<s;i++){
    for(int j=s-1;j>=0;--j){
      temp1 = arr[i].name.substr(7,arr[i].name.length());
      temp2 = arr2[j].name.substr(7,arr[j].name.length());
      num1 = stoi(temp1);
      num2 = stoi(temp2);
      if(num1>=num2){
        for(int k=1;k<j+1;k++){
          arr2[k-1].name=arr2[k].name;
          arr2[k-1].topic=arr2[k].topic;
        }
        arr2[j].name=arr[i].name;
        arr2[j].topic=arr[i].topic;
        break;
      }
    }
  }
  for(int i=0;i<n;i++){
    arr[i].name=arr2[i].name;
    arr[i].topic=arr2[i].topic;
  }
}

void descendSorttopic(Person arr[], double n){
  int s = int(n);
  Person arr2[s];
  arr2[s-1].name=arr[0].name;
  arr2[s-1].topic=arr[0].topic;
  for(int i=1;i<s;i++){
    for(int j=s-1;j>=0;--j){
      if(arr[i].topic<=arr2[j].topic){
        for(int k=1;k<j+1;k++){
          arr2[k-1].name=arr2[k].name;
          arr2[k-1].topic=arr2[k].topic;
        }
        arr2[j].name=arr[i].name;
        arr2[j].topic=arr[i].topic;
        break;
      }
    }
  }
  for(int i=0;i<n;i++){
    arr[i].name=arr2[i].name;
    arr[i].topic=arr2[i].topic;
  }
}

void ascendSorttopic(Person arr[], double n){
  int s = int(n);
  Person arr2[s];
  arr2[s-1].name=arr[0].name;
  arr2[s-1].topic=arr[0].topic;
  for(int i=1;i<s;i++){
    for(int j=s-1;j>=0;--j){
      if(arr[i].topic>=arr2[j].topic){
        for(int k=1;k<j+1;k++){
          arr2[k-1].name=arr2[k].name;
          arr2[k-1].topic=arr2[k].topic;
        }
        arr2[j].name=arr[i].name;
        arr2[j].topic=arr[i].topic;
        break;
      }
    }
  }
  for(int i=0;i<n;i++){
    arr[i].name=arr2[i].name;
    arr[i].topic=arr2[i].topic;
  }
}


Person* filesort(string file, double num, Person array[]) {
  ifstream in;
  in.open(file);
  Person temp;
  string key;
  string info;
  int answer1;
  int answer2;
  cout << "Do you want to sort by student or topic? Enter 1 for student and 2 for topic." << endl;
  cin >> answer1;
  cout << "Do you want ascending order or descending order? Enter 1 for ascending and 2 for descending." << endl;
  cin >> answer2;
  for(size_t i = 0; i < num; i++) {
    in >> key;
    in >> info;
    temp.name = key;
    temp.topic = info;
    array[i] = temp;
  }
  if(answer1 == 1) {
    if(answer2 == 1) {
      ascendSortname(array,num);
    }
    else if(answer2 == 2) {
      descendSortname(array,num);
    }
  }
  if(answer1 == 2) {
    if(answer2 == 1) {
      ascendSorttopic(array,num);
    }
    else if(answer2 == 2) {
      descendSorttopic(array,num);
    }
  }
  return array;
  


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
  multimap <string,string> people;
  ofstream record;
  record.open("list.txt");
  string temp;
  string temp2;

  for(int i = 0; i < 100; i++) {
    lineClear(queue);
    remainTime = 0.0;
    for(int j = 0; j < 60; j++) {
      if(remainTime - j == 0) {
        busy = false;
      }
      if((rand() % 10 + 1) > 7) {
        for(int k = 0; k < (rand() % 2 + 1); k++) {
          stu = createStu(j);
          queue.push(stu);
          temp = "Student" + to_string(rand()%32+1);
          temp2 = generateTopic(rand()%6+1);
          people.insert(pair<string,string> (temp,temp2));
          record << temp << " " << temp2 << endl;
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

  record.close();

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

  //Outstreaming Student files
  ofstream out;
  for(int l = 1; l <= 32; l++) {
    int occurancy = 0;
    string id = "Student"+to_string(l);
    string studentFile = id + ".txt";
    out.open(studentFile);
    out << id <<" vistited ";
    for(auto m : people){
      if(m.first == id) {
        occurancy++;
      }
    }
    out << occurancy << " times for" << endl;
    for(auto n : people){
      if(n.first == id) {
        out << n.second << " ";
      }
    }
    out << endl << '\n';
    out.close();
  }

  ofstream sort;
  sort.open("Result.txt");
  int s = static_cast<int>(numOfStu);
  Person sorted[s];
  filesort("list.txt", numOfStu, sorted);
  for(size_t x = 0; x < numOfStu; x++) {
    sort << sorted[x].name << " " << sorted[x].topic << endl;
  }
  sort.close();


}
