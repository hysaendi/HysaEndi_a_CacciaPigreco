
//dichiarazione variabili

#include <LiquidCrystal.h>
                                  
int bottone1;
int bottone2;
int bottone3;
int bottone4;
int bottone5;
int bottoneInizio;

void setup() {
  // put your setup code here, to run once:
   bottone1 = 2;
   bottone2 = 3;
   bottone3 = 4;
   bottone4 = 5;
   bottone5 = 6;
   bottoneInizio = 8;


   pinMode (bottoneInizio,INPUT);
   pinMode (bottone1,INPUT);
   pinMode (bottone2,INPUT);
   pinMode (bottone3,INPUT);
   pinMode (bottone4,INPUT);
   pinMode (bottone5,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
