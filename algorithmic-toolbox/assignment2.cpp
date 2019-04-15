#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::max;

int MaxPairWiseProduct(const std::vector<int>& numbers){
	int product = 0;
	int n = numbers.size();
	for(int i=0;i<n;i++){
		for(int j= i+1;j<n;j++){
			product = max(product,numbers[i]*numbers[j]);
		}
	}
	return product; 
}

int MaxPairWiseProductFast(const vector<int>& numbers){
	int index1 = 0;
	int n = numbers.size();
	for(int i = 1;i<n;i++){
		if(numbers[i] > numbers[index1])
			index1 = i;
	}
	int index2 = 0;
	for(int i = 1;i<n;i++){
		if(i!=index1 && numbers[i] > numbers[index2])
			index2 = i;
	}
	return numbers[index1]*numbers[index2];
}

int main(){
	int n;
	cin >> n;
	vector<int> numbers(n);
	for(int i = 0;i<n;i++){
		cin >> numbers[i];
	}
	//int product = MaxPairWiseProduct(numbers);
	int product = MaxPairWiseProductFast(numbers);
	cout << product << "\n";
	return 0;
}
