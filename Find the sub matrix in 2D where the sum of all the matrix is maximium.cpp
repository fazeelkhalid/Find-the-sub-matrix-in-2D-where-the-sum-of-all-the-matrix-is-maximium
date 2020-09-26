#include<iostream>
#include<fstream>
using namespace std;

void printMaxSumSubMatrix(int **M, int N, int K) {
	int tempSum[100][100];
	int j = 0;
	int  i = 0;
	int sum = 0;
	int mSum = -99999;
	int *temp = NULL;
	while (j < N) {
		sum = 0;
		i = 0;
		while (i < K) {
			sum = sum + M[i][j];
			i++;
		}
		tempSum[0][j] = sum;
		i = 1;
		while (i < N - K + 1) {
			sum = sum + (M[i + K - 1][j] - M[i - 1][j]);
			tempSum[i][j] = sum;
			i++;
		}
		j++;
	}

	i = 0;
	while (i < N - K + 1) {
		sum = 0;
		j = 1;
		while (j < K) {
			sum = sum + tempSum[i][j];
			j++;
		}
		if (sum > mSum) {
			mSum = sum;
			temp = &(M[i][0]);
		}
		j = 1;
		while (j <= N - K) {
			sum = sum + (tempSum[i][j + K - 1] - tempSum[i][j - 1]);
			if (sum > mSum) {
				mSum = sum;
				temp = &(M[i][j]);
			}
			j++;
		}
		i++;
	}
	for (int i = 0; i < K; i++) {
		int l = i * N;
		for (int j = 0; j < K; j++)
			cout << *(temp + l + j) << " ";
		cout << endl;
	}

}
int main() {
	int **input = NULL;
	int n = 0;
	int k = -1;
	ifstream fin;
	fin.open("Input.txt");
	while (!fin.eof()) {
		fin >> n;
		input = new int *[n];
		for (int i = 0; i < n; i++) {
			input[i] = new int[n];

		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fin >> input[i][j];
			}
		}
	}
	fin.close();
	while (!(k >= 0 && k <= n)) {
		cout << "Sub matrix rows : ";
		cin >> k;
	}
	printMaxSumSubMatrix(input, n, k);
	
	cout << "\n\n\n\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (input) {
				cout << input[i][j] << "\t";
			}
		}
		cout << endl;
	}

	return 0;
}