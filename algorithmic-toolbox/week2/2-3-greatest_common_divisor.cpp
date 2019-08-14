#include<iostream>

int gcd(int a, int b){
  while(a != b){
    if (a > b){
      a -= b;
    }
    else{
      b -= a;
    }
  }
  return a;
}

int main(){
  int a = 0;
  int b = 0;
  std::cin >> a >> b ;
  std::cout << gcd(a,b) << "\n";
  return 0;
}