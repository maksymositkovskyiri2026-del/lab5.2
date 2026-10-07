// Lab_0// Lab_05_2.cpp
// Осітковський Максим
// Лабораторна робота № 5.2
// Варіант 19

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототипи для першого варіанту (void-функції)
void S_void(const double x, const double eps, int& n, double& s);
void A_void(const double x, const int n, double& a);

// Прототипи для другого варіанту (функції з return)
double S_func(const double x, const double eps, int& n);
double A_func(const double x, const int n, const double a);


int main()
{
	double xp, xk, x, dx, eps;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	if (xp <= -1 || xk >= 1)
	{
		cout << "Помилка: потрібно -1 < xp, xk < 1" << endl;
		return 1;
	}

	// ВИКОНАННЯ СПОСІБ 1: через void-функції

	cout << "\n=== 1. ВИКОРИСТАННЯ VOID-ФУНКЦІЙ ===" << endl;
	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << "      |"
		<< setw(10) << "arcsin(x)" << "  |"
		<< setw(7) << "S" << "       |"
		<< setw(5) << "n" << "   |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		double s_v = 0;
		int n_v = 0;
		S_void(x, eps, n_v, s_v);

		cout << "|" << setw(7) << setprecision(2) << x << "   |"
			<< setw(10) << setprecision(5) << asin(x) << "   |"
			<< setw(10) << setprecision(5) << s_v << "   |"
			<< setw(5) << n_v << "   |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;


	// ВИКОНАННЯ СПОСІБ 2: через функції з return

	cout << "\n=== 2. ВИКОРИСТАННЯ ФУНКЦІЙ З RETURN (double) ===" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << "      |"
		<< setw(10) << "arcsin(x)" << "  |"
		<< setw(7) << "S" << "       |"
		<< setw(5) << "n" << "   |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		int n_f = 0;
		double s_f = S_func(x, eps, n_f);

		cout << "|" << setw(7) << setprecision(2) << x << "   |"
			<< setw(10) << setprecision(5) << asin(x) << "   |"
			<< setw(10) << setprecision(5) << s_f << "   |"
			<< setw(5) << n_f << "   |"
			<< endl;

		x += dx;
	}
	cout << "-------------------------------------------------" << endl;

	return 0;
}

void S_void(const double x, const double eps, int& n, double& s)
{
	n = 0;
	double a = x;
	s = a;
	do {
		n++;
		A_void(x, n, a);
		s += a;
	} while (abs(a) >= eps);
}

void A_void(const double x, const int n, double& a)
{
	double R = x * x * (2. * n - 1) * (2. * n - 1) / (2. * n * (2. * n + 1));
	a *= R;
}

double S_func(const double x, const double eps, int& n)
{
	n = 0;
	double a = x;
	double s = a;
	do {
		n++;
		a = A_func(x, n, a);
		s += a;
	} while (abs(a) >= eps);
	return s;
}

double A_func(const double x, const int n, const double a)
{
	double R = x * x * (2. * n - 1) * (2. * n - 1) / (2. * n * (2. * n + 1));
	return a * R;
}
