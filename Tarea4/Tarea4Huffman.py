import math
import heapq
import argparse

class Nodo:
  def __init__(self, caracter, frecuencia, izquierdo, derecho):
    self.caracter = caracter
    self.frecuencia = frecuencia
    self.izquierdo = izquierdo
    self.derecho = derecho

  def __lt__(self, otro):
    return self.frecuencia < otro.frecuencia

def calcular_frecuencias(texto):
  frecuencias = {}

  for caracter in texto:
    if caracter in frecuencias:
      frecuencias[caracter] += 1
    else:
      frecuencias[caracter] = 1
      
  return frecuencias

def construir_arbol(lista):
  while len(lista) > 1:
    nodo1 = heapq.heappop(lista)
    nodo2 = heapq.heappop(lista)
    
    nuevo_nodo = Nodo(None, nodo1.frecuencia + nodo2.frecuencia, nodo1, nodo2)
    heapq.heappush(lista, nuevo_nodo)
    
  return lista[0]

def asignar_codigos(nodo, codigo, codigos):
  if nodo.caracter is not None:
    codigos[nodo.caracter] = codigo
  else:
    asignar_codigos(nodo.izquierdo, codigo + "0", codigos)
    asignar_codigos(nodo.derecho, codigo + "1", codigos)

def huffman(texto):
  frecuencias = calcular_frecuencias(texto)

  lista = [Nodo(caracter, frecuencia, None, None) for caracter, frecuencia in frecuencias.items()]
  heapq.heapify(lista)
  
  arbol = construir_arbol(lista)
  
  codigos = {}
  asignar_codigos(arbol, "", codigos)
  
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
  huffman(file_content)
