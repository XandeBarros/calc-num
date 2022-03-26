#include <iostream>
#include <cmath>

using namespace std;

float function(float number);

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

  float func_a = function(lim_a), func_b = function(lim_b);

  if (func_a * func_b > 0)
  {
    cout << "Impossível calcular isso ;c" << endl;
    return 0;
  }

  for (int i = 0; i < 100; i++)
  {
    float med_vars = 0.5 * (lim_a + lim_b);

    float func_a = function(lim_a), func_b = function(lim_b);
    float func_med = function(med_vars);

    if (abs(func_med) < error)
    {
      cout << "O valor de x é " << med_vars << endl;
      break;
    }
    if (func_a * func_med < 0)
    {
      lim_b = med_vars;
    }
    else
    {
      lim_a = med_vars;
    }
  }

  return 0;
}

float function(float number)
{
  return number * number - sin(number); // você pode escrever qualquer função que quiser testar aqui
}