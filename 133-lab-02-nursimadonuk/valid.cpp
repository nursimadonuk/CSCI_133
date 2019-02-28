/*
Author: Nursima Donuk
Course: CSCI 133
Assignment: Lab 2
*/

#include <iostream>

int valid(int num){
  num = num*num;
  return num;
}


int main()
{
  int num;
  std::cout<<"Please enter an integer: ";
  std::cin>>num;
  while (num <= 0 || num>= 100){
    std::cout<<"Please re-enter: ";
    std::cin>>num;
  }
  std::cout<<'\n';
  std::cout<<"Number squared is " << valid(num)<<'\n';
  return 0;
}
