#include<iostream>

long long int gcd(long long int a, long long int b){
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
  long int a = 0;
  long int b = 0;
  std::cin >> a >> b ;
  if(a==0 || b== 0){
    std::cout << 0 << "\n";
  }
  else{
    std::cout << (a*b) / gcd(a,b) << "\n";
  }
  return 0;
}