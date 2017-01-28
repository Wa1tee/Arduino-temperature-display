/* Sulautetut prosessorijärjestelmät DTEK1019 Harjoitustyö 
 * Antti Auranen
 * 512934
 * ajaaur@utu.fi
 * 
 * DS18B20-lämpötilasensorista otetaan lämpötila ja tulostetaan
 * PC1602C-malliselle LCD-paneelille.
 */

#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Alustetaan näytön i/o pinneihin 12, 11, 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Alustetaan DS18B20 -sensorin  i/o pinniin 10
OneWire ds(10);

DallasTemperature sensors(&ds);

//DS18B20 Temperature chip
void setup() {
  //setup hommelit
  lcd.begin(16,2);
  lcd.print("Temp in deg C");
  sensors.begin();
}

void loop() {  
  //luetaan lämpötila sensorilta
  sensors.requestTemperatures();
  //asetetaan kursori toisen rivin ensimmäiseen indeksiin näytöllä
  lcd.setCursor(0,1);
  //tulostetaan lämpötila näytölle
  lcd.print(sensors.getTempCByIndex(0));
}
