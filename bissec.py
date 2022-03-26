import math 

def func(value):
	return value * value - math.sin(value)

lim_a = float(input("Digite o limite inferior: "))
lim_b = float(input("Digite o limite superior: "))
error = float(input("Digite o erro aceito: "))

func_a = func(lim_a)
func_b = func(lim_b)

if (func_a * func_b > 0):
	print("Impossível calcular isso ;c")

for iter in range(100):
	func_a = func(lim_a)
	func_b = func(lim_b)

	var_med = 0.5 * (lim_a + lim_b)

	func_var_med = func(var_med)
	
	if (abs(func_var_med) < error): 
		print(f'O valor de x é {var_med}')
		break

	if (func_a * func_var_med < 0):
		lim_b = var_med
	else:
		lim_a = var_med
