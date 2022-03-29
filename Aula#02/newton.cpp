#include <iostream>
#include <cmath>

using namespace std;

float func(float value);
float derv(float value);
float max(float number1, float number2);

int main()
{
  float x_k, error;

  cout << "Digite o valor inicial: " << endl;
  cin >> x_k;
  cout << "Digite o erro aceito: " << endl;
  cin >> error;

  int i;

  for (i = 0; i < 100; i++)
  {
    float x_k1;
    x_k1 = x_k - func(x_k) / derv(x_k);

    float err = abs(x_k1 - x_k) / max(1, abs(x_k1));

    if (err < error)
    {
      cout << "Raiz: " << x_k1 << endl;
      cout << "Iterações: " << i << endl;
      return 0;
    }

    x_k = x_k1;
  }

  cout << "Impossível calcular o valor de x" << endl;

  return 0;
}

float func(float value)
{
  return 4 * cos(value) - exp(value);
}

float derv(float value)
{
  return (-1) * 4 * sin(value) - exp(value);
}

float max(float number1, float number2)
{
  if (number1 > number2)
    return number1;
  return number2;
}
