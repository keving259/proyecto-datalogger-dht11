import time
import numpy as np
import matplotlib.pyplot as plt 
import pandas as pd
import serial

PUERTO = 'COM5'
BAUDRATE = 9600
N_MUESTRAS = 50
ARCHIVO_SALIDA = 'Registro_Proyecto.csv'


humedad = np.zeros(N_MUESTRAS)
temperatura = np.zeros(N_MUESTRAS)
arduino = serial.Serial(PUERTO, BAUDRATE)
time.sleep(2) # Reinicio tras abrir puerto

with arduino:
    i = 0
    while i < N_MUESTRAS:
        linea = arduino.readline().decode('utf-8', errors='ignore').strip()
        if linea:
            try:
                h, t = linea.split(',')
                humedad[i] = float(h)
                temperatura[i] = float(t)
                print(f'Muestra {i}: Humedad={humedad[i]}% Temperatura={temperatura[i]}°C')
                i += 1
            except ValueError:
                print(f'Línea no válida, se descarta: {linea}')
        time.sleep(1)

print("FIN DEL MUESTREO")

x = list(range(1, 5001))

plt.plot(x, humedad, label='Humedad (%)')
plt.plot(x, temperatura, label='Temperatura (°C)')
plt.xlabel('Muestra')
plt.ylabel('Valor')
plt.title('Registro DHT11')
plt.legend()
plt.show() # Mostrar la gráfica

data = {"Humedad": humedad, "Temperatura": temperatura}
df = pd.DataFrame(data)
df.to_csv(ARCHIVO_SALIDA)
print(f"Datos guardados en {ARCHIVO_SALIDA}")
