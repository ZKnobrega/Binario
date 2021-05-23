#include <iostream>
#include <locale>
using namespace std;

void convDecParaBin(int num, int* bin);
void imprimeBin(int bin[]);
void copiaBin(int binOriginal[], int* binCopia);
void somaBin(int bin1[], int bin2[], int* soma);
void complementoA2(int* bin);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int num1, num2, bin1[8], bin2[8], Bin1[8], Bin2[8], soma[8], compleA2[8];

	cout << "Insira o primeiro número: ";
	cin >> num1;
	cout << "Insira o segundo número: ";
	cin >> num2;
	convDecParaBin(num1, bin1);
	convDecParaBin(num2, bin2);
	cout << "\nPrimeiro número em binário: ";
	imprimeBin(bin1);
    cout << "\nSegundo número em binário: ";
	imprimeBin(bin2);
	copiaBin(bin1, Bin1);
	copiaBin(bin2, Bin2);
	somaBin(bin1, bin2, soma);
	cout << "\nSoma entre os binários =  ";
	imprimeBin(soma);
	cout << "\n\nAplicando o complemento a 2 em: ";
	imprimeBin(Bin2);
	complementoA2(Bin2);
	cout << "\nTorna-se: ";
	imprimeBin(bin2);
	somaBin(Bin1, bin2, compleA2);
	cout << "\nSoma com complemento A2 =  ";
	imprimeBin(compleA2);
	return 0;
}
//Converte números decimais para números binários e guarda em um vetor.
void convDecParaBin(int num, int* bin)
{
	for (int i = 0; i < 8; i++)
	{
		if (num >= 1)
		{
			bin[i] = (num % 2);
			num /= 2;
		}
		else
		{
			bin[i] = 0;
		}
	}
}
//Imprime o vetor com o número binário.
void imprimeBin(int bin[])
{
	for (int i = 7; i >= 0; i--)
	{
		cout << bin[i];
	}
}
//Copia os inteiros do vetor "binOriginal" para "binCopia"
void copiaBin(int binOriginal[], int* binCopia)
{
	for (int i = 0; i < 8; i++)
	{
		binCopia[i] = binOriginal[i];
	}
}
//Soma dois números binários e guarda no vetor "soma"
void somaBin(int bin1[], int bin2[], int* soma)
{
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
}
//Realiza a operação de complemento a 2
void complementoA2(int* bin)
{
	int bit_1[8] = {1,0,0,0,0,0,0,0}; //bit 1 para utilizar a função somaBin() com o vetor "bin"

	for (int i = 0; i < 8; i++)
	{
		if (bin[i] == 1)
		{
			bin[i] = 0;
		}
		else
		{
			bin[i] = 1;
		}
	}
	somaBin(bin, bit_1, bin);
}