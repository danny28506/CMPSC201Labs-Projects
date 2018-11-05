#include <iostream>
#include <cmath>
using namespace std;

int main()
{
//Input User Data
	double IntN;
	double IntL;
	double IntR;
	double SumL = 0;
	double SumR = 0;
	double SumM = 0;
	double SumT = 0;
	double SimApp;

	cout << "This program will compute Riemann Sums using Left, Right, Midpoint and Trapezoid techniques." << endl;
	cout << "The function we are solving for is f(x) = (1/x) + 3 sin(x) - 2" << endl;

	cout << "Enter the number of intervals: ";
	cin >> IntN;

	cout << "Enter the left bound of intervals: ";
	cin >> IntL;

	cout << "Enter the right bound of intervals: ";
	cin >> IntR;

//Loops

//Left Loop
	
		int countL = 1;
	double DeltaxL = ((IntR - IntL) / (IntN));
	do
	{

		SumL = DeltaxL * ((1 / (IntR - (countL*DeltaxL))) + (3 * (sin(IntR - (countL*DeltaxL))) - 2)) + SumL;

		countL++;
	} while (countL <= IntN);


//Right Loop

	double DeltaxR = ((IntR - IntL) / (IntN));
	int countR = 1 - DeltaxR;	
	do
	{

		SumR = DeltaxR * (((1 / (IntR - (countR*DeltaxR)))) + (3 * (sin(IntR - (countR*DeltaxR))) - 2)) + SumR;

		countR++;
	} while (countR <= IntN - DeltaxR);


//Midpoint Loop

	double DeltaxM = (IntR - IntL) / IntN;
	int countM = 1 - DeltaxM;
	do 
	{

		SumM = DeltaxM * (((1 / (IntR - (countM*DeltaxM) - DeltaxM/2))) + (3 * (sin(IntR - (countM*DeltaxM) - DeltaxM/2)) - 2)) + SumM;

		countM++;
	} while (countM <= IntN - DeltaxM);


//Trapezoid Loop

	double DeltaxT = (IntR - IntL) / (IntN);
	int countT = 1;
	do
	{

		SumT = (DeltaxT * ((((1 / (IntL + ((countT - 1) * DeltaxT))) + (3 * (sin(IntL + ((countT - 1) * DeltaxT))) - 2)) + ((1 / (IntL + (countT * DeltaxT))) + (3 * (sin(IntL + (countT * DeltaxT))) - 2)))/2)) + SumT;

		countT++;
	} while (countT <= IntN);


//Calculate Simpson's Approx.

	SimApp = ((2 * SumM) + SumT) / 3;

//Output User Data

	cout << " " << endl;
	cout << "Results of approximation of f(x) on [" << IntL << " , " << IntR << "] using " << IntN << " subintervals: " << endl;
	cout << " " << endl;
	cout << "Left Sum Quadrature Technique: " << SumL << endl;
	cout << "Right Sum Quadrature Technique: " << SumR << endl;
	cout << "Midpoint Quadrature Technique: " << SumM << endl;
	cout << "Trapezoid Quadrature Technique: " << SumT << endl;
	cout << "Simpson's Approximation: " << SimApp << endl;


	;  return 0;
}
