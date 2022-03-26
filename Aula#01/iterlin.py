import math 

def func(value):
  # isole a variável da função ex: x^3 + 4x^2 - 10, fica x = sqrt(10 / (4 + x))

	return math.sqrt(10 / (4 + value))

def max(number1, number2):
  if number1 > number2: 
    return number1
  else: 
    return number2

lim_a = float(input("Digite o limite inferior: "))
lim_b = float(input("Digite o limite superior: "))
error = float(input("Digite o erro aceito: "))

med_var = 0.5 * (lim_a + lim_b)

for iter in range(100):
  func_med_var = func(med_var)

  if (abs(func_med_var - med_var) < error *  max(1, abs(func_med_var))):
    print(f"O valor de x é {func_med_var}")
    break

  med_var = func_med_var

print("Impossível calcular o valor de x")
