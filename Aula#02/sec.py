import math 

def func(value):
	return 4 * math.cos(value) - math.exp(value)

def max(number1, number2):
  if number1 > number2: 
    return number1
  else: 
    return number2

def main():
  x_k = float(input("Digite o valor inicial: "))
  x_k1 = float(input("Digite o valor final: "))
  error = float(input("Digite o erro aceito: "))

  for iter in range(100):
    x_k2 = ((x_k) * func(x_k1) - (x_k1) * func(x_k)) / (func(x_k1) - func(x_k))

    err = abs(x_k2 - x_k1) / max(1, abs(x_k2))

    if (err < error):
      print(f"Raiz {x_k2}")
      print(f"Iterações: {iter + 1}")
      return

    x_k = x_k1
    x_k1 = x_k2

  print("Impossível calcular o valor de x")

main()