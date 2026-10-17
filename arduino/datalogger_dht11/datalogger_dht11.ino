#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

#define DHTPIN 2        // Pin digital donde está conectado el DHT11
#define DHTTYPE DHT11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);

int valor;
float humidity;
float tempc;

void setup(void)
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // OLED FISICA 0x3C PROTEUS 0x3D
  display.clearDisplay();
  display.display();
  dht.begin();
}

void loop(void){
  humidity = dht.readHumidity();

  tempc = dht.readTemperature();
  delay(1000);
  display.fillScreen(0);
  display.setTextSize(1.5); // Se define el tamaño del texto como el más pequeño.
  display.setTextColor(WHITE); // Se define como blanco (el único color) el color del texto.
                                // La pantalla solo puede mostrar blanco a diferencia de otros tipos de pantalla

  display.setCursor(1,0); // El cursor se coloca en los ejes (X,Y).
  display.print("datalloguer");
  display.setCursor(1,10);
  //display.print("00:00");
  display.print("Humedad=");
  display.print(humidity);
  Serial.print(humidity); Serial.print(",");

  display.setCursor(1,20); // El cursor se coloca en los ejes (X,Y).
  display.print("Centigrados=");
  display.print(tempc);
  Serial.println(tempc);
  //Serial.print("\n");
  display.display();

}
