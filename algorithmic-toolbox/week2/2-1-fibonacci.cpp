#include<iostream>

int fibonacci_naive(int n){
  if (n <= 1)
    return n;
  return fibonacci_naive(n-1) + fibonacci_naive(n-2);
}

// fibonacci fast used matrix exponentiation 
//The algorithm is based on this innocent-looking identity (which can be proven by mathematical induction):
//
//[1 1 1 0 ]n=[F(n+1) F(n) F(n) F(n−1)].
//
//It is important to use exponentiation by squaring with this algorithm, 
//because otherwise it degenerates into the dynamic programming algorithm. 
//This algorithm takes Θ(1) space and Θ(logn) operations. 
//(Note: We are counting the number of bigint arithmetic operations, not fixed-width word operations.)
int fibonacci_fast(int n){
  if(n <= 1){
    return n;
  }
  int mat [2][2] = {{1,1},{1,0}};
  int temp [2][2] = {{1,1},{1,0}};
  int a [2][2] = {0,0,0,0};
  for(int i = 1;i<n;i++){
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
  // while(true){
  //   int i = rand() % 45 + 2;
  //   std::cout << i << '\n';
  //   int res1 = fibonacci_naive(i);
  //   int res2 = fibonacci_fast(i);
  //   if(res1!=res2){
  //     std::cout << "error" <<  "\n";
  //     break;
  //   }
  //   else {
  //     std::cout << "OK!" <<  "\n";
  //   }
  // }
  int n = 0;
  std::cin >> n;
  // std::cout << fibonacci_naive(n) << '\n';
  std::cout << fibonacci_fast(n) << '\n';
  return 0;
}
