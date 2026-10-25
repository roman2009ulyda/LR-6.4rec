#include <iostream>
#include <iomanip> 
#include <time.h> 
#include <cmath>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(3) << a[i] << ",";
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int MAXINDX(const int* a, const int n, int i, int imax) {
	if (i >= n)
		return imax;

	if (a[i] > a[imax]) {
		imax = i;
	}
	return MAXINDX(a, n, i + 1, imax);
}
int Zero(const int* a, const int n, int i) {
	if (i >= n) return -1;
	if (a[i] == 0) return i;
	return Zero(a, n, i + 1);
}
int dob(const int* a, int start, int end) {
	if (start >= end) return 1;
	return a[start] * dob(a, start + 1, end);
}
int dobutok(const int* a, const int n) {
	int zero1 = Zero(a, n, 0);
	if (zero1 == -1) return 0;
	int zero2 = Zero(a, n, zero1 + 1);
	if (zero2 == -1 || zero2 - zero1 <= 1) return 0;
	return dob(a, zero1 + 1, zero2);
}

void t1(const int* a, int* temp, const int n, int i, int& index) {
	if (i >= n) return; 
	temp[index++] = a[i];
	t1(a, temp, n, i + 2, index); 
}
void t2(const int* a, int* temp, const int n, int i, int& index) {
	if (i >= n) return;
	temp[index++] = a[i];
	t2(a, temp, n, i + 2, index);
}
void res(int* a, const int* temp, const int n, int i) {
	if (i >= n) return;
	a[i] = temp[i];
	res(a, temp, n, i + 1);
}
void Transform(int* a, const int n) {
	int* temp = new int[n];
	int index = 0;
	t1(a, temp, n, 0, index); 
	t2(a, temp, n, 1, index); 
	res(a, temp, n, 0);
	delete[] temp;
}

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "Enter n:";
	cin >> n;
	int* a = new int[n];
	int Low = -5;
	int High = 5;
	Create(a, n, Low, High,0);
	Print(a, n,0);
	cout << "imax=" << MAXINDX(a, n,0,0) << endl;
	cout << "dobutok=" << dobutok(a, n) << endl;
	Transform(a, n);
	Print(a, n,0);
	delete[] a;
	return 0;
}