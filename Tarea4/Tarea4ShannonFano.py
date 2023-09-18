import math
import argparse

def calcular_frecuencias(texto):
  frecuencias = {}

  for caracter in texto:
    if caracter in frecuencias:
      frecuencias[caracter] += 1
    else:
      frecuencias[caracter] = 1

  return frecuencias

def ordenar_por_frecuencia(lista):
  return sorted(lista, key=lambda x: x[1], reverse=True)

def dividir_lista(lista):
  lista1 = []
  lista2 = []
  suma1 = 0
  suma2 = 0

  for tupla in lista:
    if suma1 <= suma2:
      lista1.append(tupla)
      suma1 += tupla[1]
    else:
      lista2.append(tupla)
      suma2 += tupla[1]
  
  return lista1, lista2

def asignar_codigos(lista, codigo, codigos):
  if len(lista) == 1:
    codigos[lista[0][0]] = codigo
  else:
    lista1, lista2 = dividir_lista(lista)
    asignar_codigos(lista1, codigo + "0", codigos)
    asignar_codigos(lista2, codigo + "1", codigos)

def shannon_fano(texto):
  frecuencias = calcular_frecuencias(texto)
  lista = ordenar_por_frecuencia(frecuencias.items())

  codigos = {}

  asignar_codigos(lista, "", codigos)

  total_bits = 0

  for caracter in texto:
    total_bits += len(codigos[caracter])
    
  total_caracteres = len(frecuencias)
  bits_esperados = total_bits / len(texto)
  entropia = math.log2(total_caracteres)

  print("Codificación:")
  for caracter, codigo in codigos.items():
    print(caracter, "->", codigo)
  print("Número de bits esperado por carácter:", bits_esperados)
  print("Entropía en el peor de los casos:", entropia)
  print("Número total de bits que se necesitarían para guardar el texto:", total_bits)

parser = argparse.ArgumentParser()
parser.add_argument('filename')
args = parser.parse_args()
with open(args.filename, encoding='utf-8') as file:
  file_content = file.read()
  shannon_fano(file_content)
