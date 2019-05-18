
//dichiarazione variabili

#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
                                  
int bottone1;
int bottone2;
int bottone3;
int bottone4;
int bottone5;
int bottoneInizio;
int record;
int vite;
int posPigreco;
int posbombe;
int puntiPartita_Attuale;


void setup() {
  // put your setup code here, to run once:
  lcd.begin (16,2);
   bottone1 = 2;
   bottone2 = 3;
   bottone3 = 4;
   bottone4 = 5;
   bottone5 = 6;
   bottoneInizio = 8;
   record = 0;
   vite = 5;
   puntiPartita_Attuale = 0;


   pinMode (bottoneInizio,INPUT);
   pinMode (bottone1,INPUT);
   pinMode (bottone2,INPUT);
   pinMode (bottone3,INPUT);
   pinMode (bottone4,INPUT);
   pinMode (bottone5,INPUT);

   
}

void loop() {
  // put your main code here, to run repeatedly:
  inizio();
  premereBottone (bottoneInizio);
  lcd.setCursor (0,0);
  lcd.print ("VITE" + vite);
 int numeroRandom  = random (1,6);
  while (vite > 0)
  if (numeroRandom == 1)
  {
    inserirePiGreco ( bottone1, record, vite, 1, "π");
  }
  else if (numeroRandom == 2)
  {
    inserirePiGreco ( bottone2, record , vite, 5, "π");
  }
  else if (numeroRandom == 3)
  {
    inserirePiGreco (bottone3 , record, vite, 4, "π");
  }
  else if (numeroRandom == 4)
  {
    inserirePiGreco (bottone4, record, vite, 6, "π");
  }
  else if (numeroRandom == 5)
  {
    inserirePiGreco (bottone5, record, vite, 2 , "π");
  }
  
}

void premereBottone (int bottone)
{
  bool premuto = false;
  while (!premuto)
  {
    if (digitalRead(bottone) == HIGH)
    {
      premuto = true;
    }
  }
}


 void inserirePiGreco (int bottone, int record, int vite , int o,  String s)  
{
  lcd.setCursor (o, 1);
  lcd.print (s);
  premereBottone(bottone);
  record++;
  puntiPartita_Attuale++;
  
}

void inserisciPigreco ( int bottone, int record, int vite, int a, String s)
{
  lcd.setCursor (a, 1);
  lcd.print(s);
  if (digitalRead (bottone) == HIGH)
  {
    record++;
    vite++;
    
  }
}

void inizio ()
{
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("INIZIA GIOCO");
  lcd.setCursor (0,1);
  lcd.print ("RECORD" + String(record) + "PUNTI");
  
}


