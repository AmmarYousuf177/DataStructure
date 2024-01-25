#include <iostream>

using namespace std;


class point {
	int x;
	int y;

public:
	point(){
		this->x = 0;
		this->y = 0;
	}
	point(int a, int b) {
		this->x = a;
		this->y = b;
	}
	void SetX(int a) {
		this->x = a;
	}
	void SetY(int b) {
		this->y = b;
	}
	int GetX() {
		return this->x;
	}
	int GetY() {
		return this->y;
	}
	int distance() {
		return this->x - this->y;
	}
};
//
//int main() {
//	//task1
//	int day, month, year;
//
//	cout << "Enter day: ";
//	cin >> day;
//	cout << "Enter month : ";
//	cin >> month;
//	cout << "Enter year: ";
//	cin >> year;
//
//	cout << "The Date is: " << day << "/" << month << "/" << year;
//	cout << endl;
//	cout << endl;
//	//task2
//	point A(10, 2);
//	cout << "The distance between x and y is: ";
//	cout<<A.distance();
//	cout << endl;
//	cout << endl;
//
//	return 0;
//}

//task3
void inputMatrix(int A[][5], int m, int n) {
	std::cout << "Enter elements of the matrix:\n";
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> A[i][j];
}

void displayMatrix(const int A[][5], int m, int n) {
	std::cout << "Matrix elements:\n";
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			std::cout << A[i][j] << " ";
		std::cout << "\n";
	}
}

int sumOfMatrix(const int A[][5], int m, int n) {
	int sum = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			sum += A[i][j];
	return sum;
}

void rowSum(const int A[][5], int m, int n) {
	std::cout << "Row-wise sum:\n";
	for (int i = 0; i < m; ++i) {
		int rowSum = 0;
		for (int j = 0; j < n; ++j)
			rowSum += A[i][j];
		std::cout << "Row " << i + 1 << ": " << rowSum << "\n";
	}
}

void columnSum(const int A[][5], int m, int n) {
	std::cout << "Column-wise sum:\n";
	for (int j = 0; j < n; ++j) {
		int colSum = 0;
		for (int i = 0; i < m; ++i)
			colSum += A[i][j];
		std::cout << "Column " << j + 1 << ": " << colSum << "\n";
	}
}

// Function to create transpose of a matrix of size m x n
void transposeMatrix(const int A[][5], int m, int n) {
	int transpose[5][5];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			transpose[i][j] = A[j][i];

	std::cout << "Transpose of the matrix:\n";
	displayMatrix(transpose, n, m);
}


int main() {
	int m, n;
	int matrix[5][5];

	std::cout << "Enter the number of rows (m): ";
	std::cin >> m;
	std::cout << "Enter the number of columns (n): ";
	std::cin >> n;

	int choice;
	do {
		std::cout << "\nMenu:\n";
		std::cout << "1. Input elements into matrix\n";
		std::cout << "2. Display elements of matrix\n";
		std::cout << "3. Sum of all elements of matrix\n";
		std::cout << "4. Display row-wise sum of matrix\n";
		std::cout << "5. Display column-wise sum of matrix\n";
		std::cout << "6. Create transpose of matrix\n";
		std::cout << "0. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			inputMatrix(matrix, m, n);
			break;
		case 2:
			displayMatrix(matrix, m, n);
			break;
		case 3:
			std::cout << "Sum of all elements: " << sumOfMatrix(matrix, m, n) << "\n";
			break;
		case 4:
			rowSum(matrix, m, n);
			break;
		case 5:
			columnSum(matrix, m, n);
			break;
		case 6:
			transposeMatrix(matrix, m, n);
			break;
		case 0:
			std::cout << "Exiting program.\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 0);

	return 0;
}