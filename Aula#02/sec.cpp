#include <iostream>
#include <cmath>

using namespace std;

float func(float value);
float max(float number1, float number2);

int main()
{
  float x_k, x_k1, error;

  cout << "Digite o valor inicial: " << endl;
  cin >> x_k;
  cout << "Digite o valor final: " << endl;
  cin >> x_k1;
  cout << "Digite o erro aceito: " << endl;
  cin >> error;

  for (int i = 0; i < 100; i++)
  {
    float x_k2;
    float func_x_k = func(x_k);
    float func_x_k1 = func(x_k1);
    x_k2 = ((x_k * func_x_k1) - (x_k1 * func_x_k)) / (func_x_k1 - func_x_k);

    float err = abs(x_k2 - x_k1) / max(1, abs(x_k2));

    if (err < error)
    {
      cout << "Raiz: " << x_k2 << endl;
      cout << "Iterações: " << i + 1 << endl;
      return 0;
    }

    x_k = x_k1;
    x_k1 = x_k2;
  }

  cout << "Impossível calcular o valor de x" << endl;

  return 0;
}

float func(float value)
{
  return 4 * cos(value) - exp(value);
}

float max(float number1, float number2)
{
  if (number1 > number2)
    return number1;
  return number2;
}
