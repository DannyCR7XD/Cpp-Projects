#include <iostream>

using namespace std;

int fact (int N);
void printlines();

int main()

{
	int x;
	int y;
	
	cout << "Enter Value for x: ";
	cin >> x;

	y = fact(x);	
	
	cout << "The Factorial of "<< x << " is = " << y << endl;
	
	for (y=1; y <= 10; ++y)
	{
		printlines();
		cout << "The Factorial of "<< y <<" = " << fact(y) << endl;
	}
	return 0;

}

void printlines()
{
	cout << "---------------------------" << endl;
}

int fact (int N)

{
	int F, I;
	F = 1;
	for (I = 1; I <= N; ++I)
	F = F * I;
	
	return F;

}