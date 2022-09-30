// Maszyna do mieszania drinków 
// Wresja 3.1
// Założenia: 3 składniki
//            możliwość wybrania mocy drinka
//            kilka rodzajów drinkó

//Wersja testowa

//#include <LiquidCrystal.h> 
//LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define enkodera 2
#define enkoderb 4
#define enkoPrzycisk 5
//#define alkochol 6
//#define sokPomaranczowy 6
//#define sokPorzeczkowy 6
//#define Cola 6
//#define mieszadlo 6
//#define minusPlyny 6

byte ileenkoder=0;
byte ileprzycisk=0;
byte ile=0;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
pinMode(enkodera,INPUT_PULLUP);
pinMode(enkoderb,INPUT_PULLUP);
pinMode(enkoPrzycisk,INPUT_PULLUP);


attachInterrupt(0,Enkoder,FALLING);
lcd.noCursor();


  
}

byte Enkoder(){
  if(digitalRead(enkoderb)){
  if(ileenkoder==0)
  ileenkoder=1;
  ileenkoder--;
  }
  else{
  if(ileenkoder==9)
  ileenkoder=8;
  ileenkoder++;
  }
  Serial.println(ileenkoder);
  
}
/*void mieszanie(unsigned long czasAlko,unsigned long czasOrange,unsigned long czasPorzecz,unsigned long czasCola)
{
  digitalWrite(minusPlyny,LOW);//ustawienie by wszystkie silniki krecily sie w jedna strone
 unsigned long roznicaCzasu=0;
  while(1){
unsigned long aktualnyCzas=millis();
if(roznicaCzasu>=czasAlko){//ustawienie aby alko bylo pobierane przez okreslony czas
  digitalWrite(alkochol,HIGH);}
  else
  digitalWrite(alkochol,LOW);
if(roznicaCzasu>=czasOrange){
  digitalWrite(sokPomaranczowy,HIGH);}
  else
  digitalWrite(sokPomaranczowy,LOW);
if(roznicaCzasu>=czasPorzecz){
  digitalWrite(sokPorzeczkowy,HIGH);}
  else
  digitalWrite(sokPorzeczkowy,LOW);
if(roznicaCzasu>=czasCola){
  digitalWrite(Cola,HIGH);}
  else
  digitalWrite(Cola,LOW);
          }
  }
*/
void jeden(String NazwaDrinka,unsigned long plyn1,unsigned long plyn2,unsigned long plyn3,unsigned long plyn4, byte Procenty){
Serial.println(NazwaDrinka);
Serial.println(plyn1);
Serial.println(plyn2);
Serial.println(plyn3);
Serial.println(plyn4);
Serial.println(Procenty);
   
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nazwa drinka");

if(Procenty==true){
byte procenty; //definicja zmiennej do przechowywana wartości procentowych
  while(1){
  Serial.println("Nazwa drinku");
//  if(ileenkoder==10)
//  ileenkoder=9;  
  procenty=ileenkoder*10;
  Serial.print(procenty);
  Serial.println("%");
  lcd.setCursor(0,1);
  lcd.print(procenty);
  lcd.print("%");
  if(procenty==0){
    lcd.setCursor(2,1);
  lcd.print(" ");
  }
  
  if(digitalRead(enkoPrzycisk)==LOW )
{
int a;
int b;
int c;
int d;
//mieszanie(a,b,c,d);
ileenkoder=0;
  while(digitalRead(enkoPrzycisk)==LOW);
delay(20);
break;
  }
  
  //Serial.println("Pierwsza próba działania programu");
  }
}
}


void loop() {
String NazwaDrinka ;
unsigned long Plyn1 ; 
unsigned long Plyn2 ;
unsigned long Plyn3 ;
unsigned long Plyn4 ;
byte Procenty = false;
lcd.setCursor(0,0);
lcd.print("Wybierz drink");
  lcd.setCursor(0,1);
  lcd.print(ileenkoder);
  
if(digitalRead(enkoPrzycisk)==LOW ){
  delay(20);
ile=ileenkoder;
ileprzycisk++;
Serial.print("Przycisk: ");
Serial.println(ileprzycisk);
ileenkoder=0;
while(digitalRead(enkoPrzycisk)==LOW);
delay(20);}
switch(ile){
case 1:
NazwaDrinka=("Drink 1") ;
Plyn1=1 ; 
Plyn2=2 ;
Plyn3=3 ;
Plyn4=4 ;
Procenty = false;
jeden(NazwaDrinka, Plyn1, Plyn2, Plyn3, Plyn4, Procenty);
ile=0; 
       break;
case 2:
Serial.print("Dziala");
while(digitalRead(enkoPrzycisk)==HIGH);
delay(20);
      break;
case 3:

      break;
case 5:
lcd.clear(); 
lcd.print("Blad, wybierz inny drink");
lcd.rightToLeft();

Serial.println("Bladdd");
while(digitalRead(enkoPrzycisk)==HIGH);
delay(20);
      break;
default:
      break;
  }
}
