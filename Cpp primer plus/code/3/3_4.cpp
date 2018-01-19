#include <iostream>

using namespace std;

int main() {
	const int d_h = 24, h_m = 60, m_s = 60;
	int day, hour, minute;
	unsigned long second,temp;

	cout << "Enter the number of seconds: ";
	cin >> second;
	temp = second;
	day = temp / (d_h * h_m * m_s);
	temp %= d_h*h_m*m_s;
	hour = temp / (h_m * m_s);
	temp %= h_m*m_s;
	minute = temp / m_s;
	temp %= m_s;
	cout << second << " seconds = " << day << " days, " << hour << " hours, ";
	cout << minute << " minutes, " << temp << " seconds\n";

	return 0;
}