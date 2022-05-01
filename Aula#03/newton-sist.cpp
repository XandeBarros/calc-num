
#include <iostream>
#include <cmath>
#include <array>

using namespace std;

array<float, 6> funcs(float x, float y);
float jaccobi(float x, float y);
float max(float number1, float number2);

int main()
{
  float x_k, y_k, error;

  cout << "Digite o valor inicial de x: " << endl;
  cin >> x_k;
  cout << "Digite o valor inicial de y: " << endl;
  cin >> y_k;
  cout << "Digite o erro aceito: " << endl;
  cin >> error;

  int i;

  for (i = 0; i < 100; i++)
  {
    array<float, 6> f = funcs(x_k, y_k);
    float x_k1, y_k1;

    x_k1 = x_k - ((f[0] * f[5] - f[1] * f[3]) / (jaccobi(x_k, y_k)));
    y_k1 = y_k - ((f[1] * f[2] - f[0] * f[4]) / (jaccobi(x_k, y_k)));
    float errx = abs(x_k1 - x_k) / max(1, abs(x_k1));
    float erry = abs(y_k1 - y_k) / max(1, abs(y_k1));

    if (errx < error && erry < error)
    {
      cout << "Raiz x: " << x_k1 << endl;
      cout << "Raiz y: " << y_k1 << endl;
      cout << "Iterações: " << i + 1 << endl;
      return 0;
    }

    x_k = x_k1;
    y_k = y_k1;
  }

  cout << "Impossível calcular o valor de x" << endl;

  return 0;
}

float funcf(float x, float y)
{
  return (x * x) + (y * y) - 2;
}

float funcg(float x, float y)
{
  return (x * x) - (y * y) - 1;
}

array<float, 6> funcs(float x, float y)
{
  array<float, 6> functions;

  functions[0] = (x * x) + (y * y) - 2; // f
  functions[1] = (x * x) - (y * y) - 1; // g
  functions[2] = 2 * x;                 // fx
  functions[3] = 2 * y;                 // fy
  functions[4] = 2 * x;                 // gx
  functions[5] = -2 * y;                // gy

  return functions;
}

float jaccobi(float x, float y)
{
  array<float, 6> functions = funcs(x, y);
  return functions[2] * functions[5] - functions[3] * functions[4];
}

float max(float number1, float number2)
{
  if (number1 > number2)
    return number1;
  return number2;
}
