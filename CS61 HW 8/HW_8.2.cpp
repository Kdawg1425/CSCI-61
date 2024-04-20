#include <iostream>
#include <queue>
#include <map>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  string topic;
  int question;
  int wait;
  int priority;
  int officeDay;
  int id;
};



Student createStu(string n, string t, int time, int d, int i) {
  Student temp;
  temp.name = n;
  temp.topic = t;
  temp.question = rand() % 15 + 1;
  temp.wait = time;
  temp.priority = rand() % 3 + 1;
  temp.id = i;
  temp.officeDay = d;
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


void descendSortname(Student arr[], double n){
  int s = int(n);
  Student arr2[s];
  arr2[s-1]=arr[0];
  for(int i=1;i<s;i++){
    for(int j=s-1;j>=0;--j){
      if(arr[i].id<=arr2[j].id){
        for(int k=1;k<j+1;k++){
          arr2[k-1]=arr2[k];
        }
        arr2[j]=arr[i];
        break;
      }
    }
  }
  for(int i=0;i<n;i++){
    arr[i]=arr2[i];
  }
}

void ascendSortname(Student arr[], double n){
  int s = int(n);
  Student arr2[s];
  arr2[s-1]=arr[0];
  for(int i=1;i<s;i++){
    for(int j=s-1;j>=0;--j){
      if(arr[i].id>=arr2[j].id){
        for(int k=1;k<j+1;k++){
          arr2[k-1]=arr2[k];
        }
        arr2[j]=arr[i];
        break;
      }
    }
  }
  for(int i=0;i<n;i++){
    arr[i]=arr2[i];
  }
}

void descendSorttopic(Student arr[], double n){
  int s = int(n);
  Student arr2[s];
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

void ascendSorttopic(Student arr[], double n){
  int s = int(n);
  Student arr2[s];
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


Student* sort(double num, Student array[]) {
  string info;
  int answer1;
  int answer2;
  cout << "Do you want to sort by student or topic? Enter 1 for student and 2 for topic." << endl;
  cin >> answer1;
  cout << "Do you want ascending order or descending order? Enter 1 for ascending and 2 for descending." << endl;
  cin >> answer2;
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

Student* sort(int input, double num, Student array[]) {
  if(input == 1) {
    ascendSortname(array,num);
  }
  if(input == 2) {
    ascendSorttopic(array,num);
  }
  return array;
}

void search(int input, vector<Student> arr, double num) {
  ofstream searched;
  searched.open("Searched.txt");
  string target;
  Student sorted[(int)num];
  for(size_t x = 0; x < num; x++) {
    sorted[x] = arr[x];
  }
  if(input == 1) {
    cout << "Type in the Student's name. Example: 'StudentX'" << endl;
    cin >> target;
    sort(1, num, sorted);
    for(size_t i = 0; i < num; i++) {
      if(arr[i].name == target) {
        searched << arr[i].name << " " << arr[i].topic << " " << arr[i].officeDay << endl;

      }
    }
  }
  else if(input == 2) {
    cout << "Type in the Topic you are looking for. Ex: B-Trees, Stacks, etc." << endl;
    cin >> target;
    sort(2, num, sorted);
    for(size_t i = 0; i < num; i++) {
      if(arr[i].topic == target) {
        searched << arr[i].name << " " << arr[i].topic << " " << arr[i].officeDay << endl;
      }
    }
  }
  searched.close()
  cout << "Search is done." << endl;
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
  vector<Student> list;
  ofstream record;
  record.open("list.txt");
  string temp;
  string temp2;
  int id;

  for(int i = 0; i < 100; i++) {
    lineClear(queue);
    remainTime = 0.0;
    for(int j = 0; j < 60; j++) {
      if(remainTime - j == 0) {
        busy = false;
      }
      if((rand() % 10 + 1) > 7) {
        for(int k = 0; k < (rand() % 2 + 1); k++) {
          id = rand()%32+1;
          temp = "Student" + to_string(id);
          temp2 = generateTopic(rand()%6+1);
          stu = createStu(temp, temp2, j, i, id);
          queue.push(stu);
          list.push_back(stu);
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
  /*
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
  */

  ofstream outFile;
  outFile.open("Result.txt");
  int s = static_cast<int>(numOfStu);
  Student sorted[s];
  for(size_t x = 0; x < numOfStu; x++) {
    sorted[x] = list[x];
  }
  sort(numOfStu, sorted);
  for(size_t y = 0; y < numOfStu; y++) {
    outFile << sorted[y].name << " " << sorted[y].topic << sorted[y].id << endl;
  }
  outFile.close();


  int input;
  cout << "What do you want to search by? Type in 1 for students and 2  for topics." << endl;
  cin >> input;
  search(input, list, numOfStu);
}
