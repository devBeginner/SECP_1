#include <iostream>
#include <cmath>
using namespace std;

void outputMod(int, int);

int getModulo(int num, int divisor)
{
	// wenn devisor gleich 0 ist
	if (divisor == 0)
	{
		cout << "Error: wir können nicht durch 0 teilen \n";
		return -1;
	}

	// negative Werte
	if (divisor < 0) divisor = -divisor;
	if (num < 0)     num = -num;

	// produkt der summe von divisor sollte kleiner oder gleich num sein
	int i = 1;
	int product = 0;
	while (product <= num)
	{
		product = divisor * i;
		i++;
	}

	// rest zurückgeben
	return num - (product - divisor);
}

int moduloV2(int num, int divisor) {

	int numAbs = abs(num);
	int divAbs = abs(divisor);

	// wenn devisor gleich 0 ist
	if (divisor == 0)
	{
		cout << "Error: wir können nicht durch 0 teilen \n";
		return -1;
	}

	while (numAbs > divAbs) { numAbs -= divAbs; }

	if (num < 0) {
		numAbs = -numAbs;
	}

	return numAbs;
}
 
int moduloGoogle(int num, int divisor) {

	int numVorz = num < 0 ? -1 : 1;
	int divVorz = divisor < 0 ? -1 : 1;

	num = abs(num);
	divisor = abs(divisor);

	if (numVorz == divVorz) {
		while (num > divisor) { num -= divisor; }
	} else {
		while (num > 0) { num -= divisor; }
	}

	return num * numVorz;
}

int main()
{
	int C1 = 4;
	int C2 = 3;
	
	outputMod(C1, C2);
	outputMod(-C1, C2);
	outputMod(C1, -C2);
	outputMod(-C1, -C2);

	std::cin.get();
	return 0;
}

void outputMod(int I1 ,int I2) {
	cout << "\nNum:\t\t" << I1 << "\nDivisor:\t" << I2 << endl;
	/*cout << "Version 1:\t" << getModulo(I1, I2) << endl;*/
	cout << "% Own:\t\t" << moduloV2(I1, I2) << endl;
	cout << "% Library:\t" << I1%I2 << endl;
	cout << "% Google:\t" << moduloGoogle(I1, I2) << endl;
}