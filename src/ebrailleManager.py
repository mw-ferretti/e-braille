#!/usr/bin/env python
import serial

class Interface(object):
	
	def __init__(self, portaCom, velocidade):
		self.portaCom = portaCom
		self.velocidade = velocidade
		
	def __repr__(self):
		return "InterfaceBraille(Porta: '%s' - Velocidade: %s Bits/s)" % (self.portaCom, self.velocidade)
			
	def escrever(self, string):		
		for c in string:		
			try:
				Obj_porta = serial.Serial(self.portaCom, self.velocidade)
				Obj_porta.write(c)
				self.ler()
				Obj_porta.close()					
			except serial.SerialException:
				print "Erro: Verifique se o dispositivo esta conectado na porta ", self.portaCom, "."
						   
	def ler(self):		 
	   try:
		   Obj_porta = serial.Serial(self.portaCom, self.velocidade)
		   valor = Obj_porta.readline()
		   print "Arduino disse: ",valor
		   Obj_porta.close()	 
	   except serial.SerialException:
		   print "Erro: Verifique se o dispositivo esta conectado na porta ", self.portaCom, "."

	def escutarInterface(self):
		self.ler()
		self.escutarInterface()

if __name__=='__main__':		
	obj = Interface('/dev/ttyACM0', 9600)
	print obj
	print '\n \n'
	while True:
		valor = raw_input("Digite uma letra: ")
		obj.escrever(valor)
	
