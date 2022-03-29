import math 

def func(value):
	return 4 * math.cos(value) - math.exp(value)

def derv(value):
  return (-1) * 4 * math.sin(value) - math.exp(value)

def max(number1, number2):
  if number1 > number2: 
    return number1
  else: 
    return number2

def main():
  x_k = float(input("Digite o valor inicial: "))
  error = float(input("Digite o erro aceito: "))

  for iter in range(100):
    x_k1 = x_k - func(x_k)/derv(x_k)

    err = abs(x_k1 - x_k) / max(1, abs(x_k1))

    if (err < error):
      print(f"Raiz {x_k1}")
      print(f"Iterações: {iter + 1}")
      return

    x_k = x_k1

  print("Impossível calcular o valor de x")

main()