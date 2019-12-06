import serial
import time

aux ='com3'
portaUSB=serial.Serial(aux,9600)
time.sleep(3)
tempoInicial=time.time()

while True:
    linha = portaUSB.readline()
    linha = str(linha)
    linha = linha[2:-5]
    linha = linha +',Tempo:'+ f'{(time.time()-tempoInicial):.2f}'
    with open("dados.csv", 'a') as f:
        f.write(linha+"\n")
        f.close()
    print(linha)