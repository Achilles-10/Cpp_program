#include <iostream>

using namespace std;

int main() {
	const int t_In = 12;
	const float t_M = 0.0254, t_Kg = 2.2;
	int in, ft;
	float m, kg, lb, BMI;

	cout << "Please input your height in feet and inches (int) : ";
	cin >> ft >> in;
	cout << "Please input your weight in pounds (float) : ";
	cin >> lb;
	m = (ft * t_In + in) * t_M;
	kg = lb / t_Kg;
	BMI = kg / (m*m);
	cout << "Your height in meters is : " << m << "m\n";
	cout << "Your weight in kilograms is : " << kg << "kg\n";
	cout << "Your BMI is : " << BMI << endl;

	return 0;

}