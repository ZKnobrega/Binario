#include <iostream>
#include <Locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int num1, num2, bin1[8], bin2[8], Bin1[8], Bin2[8], soma[8], compleA2[8];

	cout << "Insira o primeiro número: ";
	cin >> num1;
	cout << "Insira o segundo número: ";
	cin >> num2;

	for (int i = 0; i < 8; i++)
	{
		if (num1 >= 1)
		{
			bin1[i] = (num1 % 2);
			num1 /= 2;
		}

		else
		{
			bin1[i] = 0;
		}

		if (num2 >= 1)
		{
			bin2[i] = (num2 % 2);
			num2 /= 2;
		}

		else
		{
			bin2[i] = 0;
		}
	}

	cout << "\nPrimeiro número em binário: ";

	for (int i = 7; i >= 0; i--)
	{
		cout << bin1[i];
	}
    cout << "\nSegundo número em binário: ";

	for (int i = 7; i >= 0; i--)
	{
		cout << bin2[i];
	}

	for (int i=7; i>=0; i--)
    {
        Bin2[i]= bin2[i];
    }

	for (int i = 0; i < 8; i++)
	{
		Bin1[i] = bin1[i];
	}

	for (int i = 0; i < 8; i++)
	{
		soma[i] = bin1[i] + bin2[i];

		if (soma[i] == 2)
		{
			soma[i] = 0;
			bin1[i + 1] += 1;
		}

		if (soma[i] == 3)
		{
			soma[i] = 1;
			bin1[i + 1] += 1;
		}
	}
	cout << "\nSoma entre os binários =  ";

	for (int i = 7; i >= 0; i--)
	{
		cout << soma[i];
	}

	cout << "\n\nAplicando o complemento a 2 em: ";

	for (int i=7; i>=0; i--)
	{
		cout << Bin2[i];
	}

	for (int i = 0; i < 8; i++)
	{
		if (bin2[i] == 1)
		{
			bin2[i] = 0;
		}
		else
		{
			bin2[i] = 1;
		}
	}

	bin2[0] += 1;

	for (int i = 0; i < 8; i++)
	{
		if (bin2[i] == 2)
		{
			bin2[i] = 0;
			bin2[i + 1] += 1;
		}

		if (bin2[i] == 3)
		{
			bin2[i] = 1;
			bin2[i + 1] += 1;
		}
	}

	cout << "\nTorna-se: ";

	for (int i = 7; i >= 0; i--)
	{
		cout << bin2[i];
	}


	for (int i = 0; i < 8; i++)
	{
		compleA2[i] = Bin1[i] + bin2[i];

		if (compleA2[i] == 2)
		{
			compleA2[i] = 0;
			Bin1[i + 1] += 1;
		}

		if (compleA2[i] == 3)
		{
			compleA2[i] = 1;
			Bin1[i + 1] += 1;
		}
	}
	cout << "\nSoma com complemento A2 =  ";

	for (int i = 7; i >= 0; i--)
	{
		cout << compleA2[i];
	}
	return 0;
}
