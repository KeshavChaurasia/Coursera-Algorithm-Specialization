#include<iostream>

//Sum of nth Fibonacci series = F(n+2) -1
//Then pisano period of module 10 = let n+2 mod (60) = m then find F(m) mod(10)-1

long long fibonacci_fast(int n){
  n = (n+2) % 60;
  if(n <= 1){
    return n;
  }
  long long mat [2][2] = {{1,1},{1,0}};
  long long temp [2][2] = {{1,1},{1,0}};
  long long a [2][2] = {0,0,0,0};
  for(int i = 2;i<n;i++){
    a[0][0] = temp[0][0] * mat[0][0] + temp[0][1] * mat[1][0];
    a[0][1] = temp[0][0] * mat[0][1] + temp[0][1] * mat[1][1];
    a[1][0] = temp[1][0] * mat[0][0] + temp[1][1] * mat[1][0];
    a[1][1] = temp[1][0] * mat[0][1] + temp[1][1] * mat[1][1];
    temp[0][0] = a[0][0];
    temp[0][1] = a[0][1];
    temp[1][0] = a[1][0];
    temp[1][1] = a[1][1];
  }
  return (temp[0][1] -1 )% 10;
}

int main(){
  int n = 0;
  std::cin >> n;
  std::cout << fibonacci_fast(n) << '\n';
  return 0;
}
