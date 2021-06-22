#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string city;
	int temp;
	int newTemp;
	ifstream fileTemp("FahrenheitTemperature.txt");
	ofstream fileTemp2("CelsiusTemperature.txt");

	if (!fileTemp.is_open()) {
		cout << "file is not open" << endl;
	}

	while (fileTemp >> city >> temp) {
		newTemp = (temp - 32) * 5 / 9;
		temp = newTemp;
		fileTemp2 << city << " " << temp << endl;
	}

	fileTemp.close();
	fileTemp2.close();

	return 0;
}