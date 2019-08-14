#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::max;

long long MaxPairWiseProduct(const std::vector<int>& numbers){
	long long product = 0;
	int n = numbers.size();
	for(int i=0;i<n;i++){
		for(int j= i+1;j<n;j++){
			product = max(product,(long long)numbers[i]*numbers[j]);
		}
	}
	return product; 
}

long long  MaxPairWiseProductFast(const vector<int>& numbers){
	int index1 = -1;
	int n = numbers.size();
	for(int i = 0;i<n;i++){
		if(numbers[i] > numbers[index1])
			index1 = i;
	}
	int index2 = -1;
	for(int i = 0;i<n;i++){
		if(i!=index1 && numbers[i] > numbers[index2])
			index2 = i;
	}
	return (long long)numbers[index1]*numbers[index2];
}

int main(){
	// while(true){
	// 	int n = rand() % 10 + 2;
	// 	cout << n << "\n";
	// 	vector<int> a;
	// 	for(int i = 0; i < n; i++){
	// 		a.push_back(rand()%100000);
	// 	}
	// 	for(int i = 0; i<n;i++){
	// 		cout << a[i] << ' ' ;
	// 	}
	// 	cout << "\n";
	// 	long long res1 = MaxPairWiseProduct(a);
	// 	long long res2 = MaxPairWiseProductFast(a);
	// 	if(res1 != res2){
	// 		cout << "WRONG ANSWER" << res1 << res2 << "\n" ;
	// 		break;
	// 	}
	// 	else {
	// 		cout << "Ok \n" ;
	// 	}
	// }
	int n;
	cin >> n;
	vector<int> numbers(n);
	for(int i = 0;i<n;i++){
		cin >> numbers[i];
	}
	//long long product = MaxPairWiseProduct(numbers);
	long long product = MaxPairWiseProductFast(numbers);
	cout << product << "\n";
	return 0;
}
