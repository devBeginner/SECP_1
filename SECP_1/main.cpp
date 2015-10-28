#include <iostream>
using namespace std;


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


int main()
{
	cout << getModulo(87654, 13);
	std::cin.get();
	return 0;
}