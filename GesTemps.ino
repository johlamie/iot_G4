

  const int temp_trans_pin = A0, LEDpin = 8, FAN_pin = 6;




   float MinTemp = 19, MaxTemp = 24;


  #include <LiquidCrystal.h>


   
  LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

  void setup() {
  

    
    LCD.begin(16, 2);
    pinMode(LEDpin, OUTPUT);
    pinMode(FAN_pin, OUTPUT);
    digitalWrite(LEDpin, HIGH);
    
    

    
    LCD.print("La temp de la chambre (C):");
    LCD.setCursor(2,1);
    LCD.print(MinTemp); LCD.print("-");LCD.print(MaxTemp);
    
    delay(2000);
 }
   

 void loop() {
   float Eqv_volt, SensorTemp;
   
   Eqv_volt = analogRead(temp_trans_pin) * 5.0 / 1023;
   SensorTemp = 100.0 * Eqv_volt-50.0;

   
    LCD.clear();
    LCD.print("Lecture de sensor T:");
    LCD.setCursor(2,1);
    LCD.print(SensorTemp); LCD.print(" C");
   
    delay(2000);
  
 
  
   if(SensorTemp > MaxTemp){
      LCD.clear();
      LCD.print("Temp est elevee !");
     
  
     
      LCD.setCursor(0, 1);LCD.print("Activez le ventilo !");
      for( int i = 0; i <= 255; i++ ) {
        analogWrite(FAN_pin, i);
        SensorTemp=SensorTemp-1;
       }
       delay(2000);
     
       LCD.clear();
       LCD.print("Temp ok !");
       LCD.setCursor(0, 1);
       LCD.print("Stoppez le ventillo !");
     

       for( int i = 255; i >= 0; i-- ) {
        analogWrite(LEDpin, i);
       }
        delay(2000);
       }
  else if(SensorTemp < MinTemp){
      LCD.clear();
      LCD.print("Temp est basse !");
      LCD.setCursor(0, 1);
      LCD.print("Activez le chauffage !");
    
    
      digitalWrite(LEDpin, HIGH);
    
      delay(3000);
    
      LCD.clear();
      LCD.print("Temp ok !");
      LCD.setCursor(0, 1);
      LCD.print("Stoppez le chauffage !");
    
      delay(1000);
    
      digitalWrite(LEDpin, LOW);
      LCD.clear();
      }
  else if(SensorTemp > MinTemp && SensorTemp < MaxTemp){
      LCD.clear();
      LCD.print("Temp normale !");
      LCD.setCursor(2,1);
      LCD.print("Ne changez rien ");
    
      delay(1000);
      LCD.clear();
   }
  else {
      LCD.clear();
      LCD.print("ERROR ! un soucis");
      LCD.setCursor(2,1); LCD.print(" avec les parametres quue vous avez saisi");
      delay(1000);
      LCD.clear();
    }
    delay(1000);
   } 