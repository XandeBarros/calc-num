#include <iostream>
#include <cmath>

using namespace std;

float function(float number);

float max(float number1, float number2);

int main()
{
  float raiz;
  float lim_a, lim_b, error;

  cout << "Digite o limite inferior: " << endl;
  cin >> lim_a;
  cout << "Digite o limite superior: " << endl;
  cin >> lim_b;
  cout << "Digite o erro aceito: " << endl;
  cin >> error;

  float med_var = 0.5 * (lim_a + lim_b);

  for (int i = 0; i < 100; i++)
  {
    float func_med_var = function(med_var);

    if (abs(func_med_var - med_var) < error * max(1, abs(func_med_var)))
    {
      cout << "O valor da raiz é: " << func_med_var << endl;
      break;
    }

    med_var = func_med_var;
  }
}

float function(float number)
{
  // Isole a variável da função ex: x^3 + 4x^2 - 10, fica x = sqrt(10 / (4 + x))

  return sqrt(10 / (4 + number));
}

float max(float number1, float number2)
{
  if (number1 > number2)
    return number1;
  return number2;
}
