#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal panel(12,11,30,31,32,33);

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'S','0','E','D'},
};
byte rowPins[ROWS]={37,36,35,34};
byte colPins[COLS]={41,40,39,38};
Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);



void setup() {
  // put your setup code here, to run once:
  panel.begin(16,2);
  panel.clear();
  char welcome[]="Welcome to WMLS";
  //panel.print("NISAl");
/*  for(int i=0;i<16;i++)
  {
    for(int j=0;j<=i;j++)
    {
      panel.print(welcome[j]);
    }
      panel.setCursor(i,0);
      delay(200);
      panel.print("");

  }
  delay(500);*/
//  panel.clear();
for(int i=0;i<15;i++)
{ panel.setCursor(i,0);
  panel.print(welcome[i]);
  delay(50);
  
}
for(int i=0;i<16;i++)
{
  delay(200);
  panel.scrollDisplayRight();
}
panel.clear();
char sys[]="MissileLaunching System";
for(int i=0;i<32;i++)
{
  if(i<7)
  {
    panel.setCursor(i+4,0);
    panel.print(sys[i]);
  }
  else
   { panel.setCursor(i-7,1);
    panel.print(sys[i]);
   }
   delay(50);
}
delay(2000);panel.clear();
char auth[]="AuthorizedPeople ONLY!";
for(int i=0;i<22;i++)
{
  if(i<10)
  {
    panel.setCursor(i+2,0);
    panel.print(auth[i]);
  }
  else
   { panel.setCursor(i-8,1);
    panel.print(auth[i]);
   }
   delay(50);
}
for(int i=0;i<16;i++)
{
  delay(200);
  panel.scrollDisplayLeft();
}
panel.clear();
panel.print("Enter Passcode>>");
panel.setCursor(6,1);
char a[]={'A','1','3','8'};
char b[4];
for(int i=0;i<4;i++)
{
  b[i]=keypad.waitForKey();
  
  panel.print("*");
}
int count=0;
for(int i=0;i<4;i++)
{
  if(b[i]==a[i])
  count++;
}
if(count==4)
{
  panel.clear();
  panel.print("Checking");
delay(50);
for(int i=0;i<8;i++)
{panel.print(".");
delay(100);

}
  
panel.clear();
char will[]="To ConfirmLaunching";
char will1[]="Press START";
for(int i=0;i<19;i++)
{
  if(i<10)
  {
    panel.setCursor(i+3,0);
    panel.print(will[i]);
  }
  else
   { panel.setCursor(i-7,1);
    panel.print(will[i]);
   }
   delay(50);
}
for(int i=0;i<16;i++)
{
  delay(200);
  panel.scrollDisplayLeft();
}
panel.clear();
for(int i=0;i<11;i++)
{
   panel.print(will1[i]);
   delay(50);
}
char key=keypad.waitForKey();
if(key=='S')
{
  panel.clear();
  panel.print("COUNTING STARTING");
  delay(1000);
  for(int i=0;i<17;i++)
{
  delay(200);
  panel.scrollDisplayLeft();
}
 for(int i=0;i<8;i++)
{
  pinMode(i+2, OUTPUT);
}
panel.clear();
for(int k=9;k>=0;k--)
{
  panel.setCursor(9-k,0);panel.print(">");
  
switch(k)
{
  case 0:{ for(int i=0;i<6;i++)
  {
    digitalWrite(i+2, HIGH);
  }
  break;
  }
  case 1: {for(int i=0;i<7;i++)
  {
    int a=i+2;
    if(a==2||a==5||a==6||a==7||a==8)
    continue;
    digitalWrite(i+2, HIGH);
  }
  break;
  }
  case 2: {for(int i=0;i<7;i++)
  {
    int a=i+2;
    if(a==4||a==7)
    continue;
    digitalWrite(i+2, HIGH);
  }
  }
  break;
  case 3:{ for(int i=0;i<7;i++)
  {
    int a=i+2;
    if(a==6||a==7)
    continue;
    digitalWrite(i+2, HIGH);
    
  }
  }
  break;
    case 4:{ for(int i=0;i<7;i++)
  {
    int a=i+2;
    if(a==2||a==6||a==5)
    continue;
    digitalWrite(i+2, HIGH);
  }
  }
  break;
    case 5:{ for(int i=0;i<7;i++)
  {
    int a=i+2;
    if(a==3||a==6)
    continue;
    digitalWrite(i+2, HIGH);
  }
  }
  break;
    case 6:{ for(int i=0;i<7;i++)
  {
    int a=i+2;
    if(a==3)
    continue;
    digitalWrite(i+2, HIGH);
  }
  }
  break;
    case 7: {for(int i=0;i<7;i++)
  {
    int a=i+2;
    if(a==5||a==6||a==7||a==8)
    continue;
    digitalWrite(i+2, HIGH);
  }
  }
  break;
    case 8: {for(int i=0;i<7;i++)
  {
    digitalWrite(i+2, HIGH);
  } 
  }
  break;
    case 9: {for(int i=0;i<7;i++)
  {
    int a=i+2;
    if(a==5||a==6)
    continue;
    digitalWrite(i+2, HIGH);
  }
  }
  break;
}
delay(1000);
for(int j=2;j<9;j++)
   digitalWrite(j, LOW);
}
panel.clear();panel.print("MISSILE LAUNCHED");
pinMode(13, OUTPUT);
digitalWrite(13, HIGH);

}
else
{
  panel.clear();
  panel.setCursor(7,0);
  panel.print("ABORTED!");
}

}
else
{
  pinMode(9, OUTPUT);pinMode(10, OUTPUT);
  panel.clear();
  panel.print("UNAUTHORIZED");
  panel.setCursor(2,1);panel.print("Login Attempt!"); 
 for(;;)
{ for(int i=0;i<3;i++){
digitalWrite(9, HIGH);
delay(50);
digitalWrite(9, LOW);
delay(50);}
for(int j=0;j<3;j++){
digitalWrite(10, HIGH);
delay(50);
digitalWrite(10, LOW);
delay(50);}
}
  
}


}

void loop() {
  // put your main code here, to run repeatedly:

}
