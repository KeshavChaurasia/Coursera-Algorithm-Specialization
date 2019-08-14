#include<iostream>

// fibonacci fast used matrix exponentiation 
//The algorithm is based on this innocent-looking identity (which can be proven by mathematical induction):
//
//[1 1 1 0 ]n=[F(n+1) F(n) F(n) F(n−1)].
//
//It is important to use exponentiation by squaring with this algorithm, 
//because otherwise it degenerates into the dynamic programming algorithm. 
//This algorithm takes Θ(1) space and Θ(logn) operations. 
//(Note: We are counting the number of bigint arithmetic operations, not fixed-width word operations.)

// The cycle repeats after 60 iterations so

long long int fibonacci_fast(int n){
  n = n % 60;
  if(n <= 1){
    return n;
  }
  long long int mat [2][2] = {{1,1},{1,0}};
  long long int temp [2][2] = {{1,1},{1,0}};
  long long int a [2][2] = {0,0,0,0};
  for(int i = 2;i<=n;i++){
    a[0][0] = temp[0][0] * mat[0][0] + temp[0][1] * mat[1][0];
    a[0][1] = temp[0][0] * mat[0][1] + temp[0][1] * mat[1][1];
    a[1][0] = temp[1][0] * mat[0][0] + temp[1][1] * mat[1][0];
    a[1][1] = temp[1][0] * mat[0][1] + temp[1][1] * mat[1][1];
    // std::cout << i << " step" << "\n";
    // std::cout << temp[0][0] << "  " << temp[0][1] << "\n";
    // std::cout << temp[1][0] << "  " << temp[1][1] << "\n";
    temp[0][0] = a[0][0];
    temp[0][1] = a[0][1];
    temp[1][0] = a[1][0];
    temp[1][1] = a[1][1];
  }
  return temp[0][1];
}

int main(){
  int n = 0;
  std::cin >> n;
  std::cout << fibonacci_fast(n) % 10 << '\n';
  return 0;
}
