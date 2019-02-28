#include <iostream>

void print_interval(int start, int stop){
  std::cout<<"Task B from "<< start << " to "<< stop <<'\n';
  while (start < stop){
    std::cout<<start<<" ";
    start++;
  }
}

void change(int myData[], int index, int value){
  myData[index] = value;
  int num = 0;
  while(num<10){
    std::cout<<myData[num]<<" ";
    num++;
  }
}

void fib(){
  long fib[60];
  fib[0] = 0;
  fib[1] = 1;
  int count = 2;
  while (count < 60){
    fib[count]= fib[count-1] + fib[count-2];
    count++;
  }
  int num;
  for(int num = 0; num < 60; num++){
    std::cout<<fib[num]<<" ";
  }
}

int main(){
  print_interval(-5, 10);
  std::cout<<'\n';
  int myData[10];
  int num = 0;
  while (num < 10){
    myData[num] = 1;
    num++;
  }
  std::cout<<'\n';
  std::cout<<"Task C with index 3 and value 20"<< '\n';
  change(myData, 3, 20);
  std::cout<<'\n';
  std::cout<<"Task D"<<'\n';
  fib();
  std::cout<<'\n';
  return 0;
}
