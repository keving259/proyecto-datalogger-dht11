# Datalogger DHT11 (Humedad y Temperatura)

Proyecto de registro de datos ambientales usando un sensor **DHT11** conectado
a una entrada digital de **Arduino**, con visualización local en una pantalla
**OLED SSD1306** y captura/almacenamiento de los datos desde **Python**.

## Descripción

Se utilizó un sensor de humedad y temperatura DHT11, conectado a una entrada
digital del Arduino. El Arduino muestra los valores en una pantalla OLED y los
envía por puerto serial. Un script en Python lee esos valores, toma 50
muestras, las grafica y genera un archivo `.csv` con el registro ordenado de
las muestras.

## Estructura del repositorio

```
proyecto-datalogger-dht11/
├── arduino/
│   └── datalogger_dht11.ino   # Código del Arduino (lectura DHT11 + display OLED)
├── python/
│   └── registro_datos.py      # Captura por serial, graficado y exportación a CSV
├── data/
│   └── Registro_Proyecto.csv  # Ejemplo de registro de 51 muestras
└── README.md
```

## Hardware utilizado

- Arduino (Uno/Nano o similar)
- Sensor DHT11 (humedad y temperatura)
- Pantalla OLED SSD1306 (I2C, dirección 0x3C)

## Librerías de Arduino

- `DHT sensor library` (Adafruit)
- `Adafruit_SSD1306`
- `Adafruit_GFX`
- `Wire`

## Librerías de Python

```
pip install numpy matplotlib pandas pyserial
```

## Cómo usarlo

1. Cargar `arduino/datalogger_dht11.ino` al Arduino (ajustar `DHTPIN` según tu
   conexión).
2. Verificar el puerto serial asignado al Arduino y actualizarlo en
   `python/registro_datos.py` (variable `PUERTO`).
3. Ejecutar el script:
   ```
   python python/registro_datos.py
   ```
4. El script tomará 50 muestras, mostrará una gráfica de humedad y
   temperatura, y generará `Registro_Proyecto.csv` con los datos.

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo [LICENSE](LICENSE)
para más detalles.

## Notas

- El archivo `data/Registro_Proyecto.csv` incluido es un ejemplo de una
  corrida real del sensor (reconstruido a partir de un registro previo).
- Las declaraciones de `display` y `dht` en el `.ino` se reconstruyeron para
  que el código compile de forma completa; ajusta pines y dirección I2C si tu
  montaje es distinto.
