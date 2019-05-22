
//dichiarazione variabili

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);


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
int tempo;


void setup() {
  // put your setup code here, to run once:
   lcd.init();                               //  inizializzazione schermo lcd con modulo i2c
   lcd.backlight();
   bottone1 = 2;
   bottone2 = 3;
   bottone3 = 4;
   bottone4 = 5;
   bottone5 = 6;
   bottoneInizio = 8;
   record = 0;
   vite = 5;
   tempo = 2000;
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
  premereBottone(bottoneInizio);
  vite = 5;
  puntiPartita_Attuale = 0;
  aggiornaSchermo();
  while (vite > 0)
  {
    delay(1500);
    int rnd1 = random(1, 15);   //crea numero random

    if (rnd1 == 1)   //quando il rsndom è 1 uscirà il bonus
    {
      int posizione = pos();
      int premuto = prem("B", posizione);

      if (premuto == posizione)
      {
        vite++;
      }
    }
    else if (rnd1 == 2) //quando il rsndom è 1 uscirà il malus
    {
      int posizione = pos();
      int premuto = prem("M", posizione);

      if (premuto == posizione)
      {
        vite--;
      }
    }
    else
    {
      int posizione = pos();   //tutti gli altri numeri random saranno i pigreco da premere
      int premuto = prem("π", posizione);

      if (premuto == posizione)
      {
        puntiPartita_Attuale++;
      }
      else
      {
        vite--;
      }
    }

    aggiornaSchermo();
  }

  if (puntiPartita_Attuale > record)
  {
    record = puntiPartita_Attuale;
  }
  aggiornaSchermo();
  lcd.clear();
  lcd.print("RIPROVA!");
  delay(1500);
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



void aggiornaSchermo ()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("LP" + String(vite));   //LP = LIFE POINTS
  lcd.setCursor (6,0);
  lcd.print ("Punti :" + String(puntiPartita_Attuale));
}

void inizio()
{
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("INIZIA GIOCO");
  lcd.setCursor (0,1);
  lcd.print ("RECORD" + String(record) + "PUNTI");
  
}


int pos  ()
{
  int posizione;
  int rnd = random (1, 6);    //posiziono il simbolo pigreco in modo random nello schermo lcd
  if (rnd == 1)
  {
    posizione = 4;
  }
  else if (rnd == 2)
  {
    posizione = 7;
  }
  else if (rnd == 3)
  {
    posizione = 13;
  }
  else if (rnd == 4)
  {
    posizione = 2;
  }
  else if (rnd == 5)
  {
    posizione = 10;
  }
  return posizione;
}
int prem(String s, int posizione)
{
  lcd.setCursor (posizione, 1);
  lcd.print (s);

  int i = 0;
  int premuto = -1;
  while (i < tempo)
  {
    if (digitalRead(bottone2) == HIGH)
    {
      premuto = 4;
      break;
    }
    else if (digitalRead(bottone3) == HIGH)
    {
      premuto = 7;
      break;
    }
    else if (digitalRead(bottone5) == HIGH)
    {
      premuto = 13;
      break;
    }
    else if (digitalRead(bottone1) == HIGH)
    {
      premuto = 2;
      break;
    }
    else if (digitalRead(bottone4) == HIGH)
    {
      premuto = 10;
      break;
    }
    i++;
    delay(1);
  }
  return premuto;
}
