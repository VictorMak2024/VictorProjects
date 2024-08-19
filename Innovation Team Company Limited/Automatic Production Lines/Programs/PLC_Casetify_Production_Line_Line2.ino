#include <SPI.h>
#include <Ethernet.h>

//byte mac[] = {0x3C, 0x7C, 0x3F, 0xBC, 0x8A, 0x11};
byte mac[] = {0x10, 0x62, 0xE5, 0x10, 0x18, 0x6A};
byte ip[] = {192, 168, 12, 143};
byte subnet[] = {255, 255, 255, 0};
EthernetServer server(10005);
char commandstr[64];
int counter = 0;
bool alreadyprintdata1 = HIGH;
bool alreadyprintdata2 = HIGH;
bool alreadyprintdata3 = HIGH;
bool alreadyprintdata4 = HIGH;
bool alreadyprintdata5 = HIGH;
bool alreadyprintdata6 = HIGH;
bool alreadyprintdata7 = HIGH;
bool alreadyprintdata8 = HIGH;
bool alreadyprintdata9 = HIGH;
bool alreadyprintdata10 = HIGH;
bool alreadyprintdata11 = HIGH;
bool alreadyprintdata12 = HIGH;
bool ASLogic1 = LOW;
bool ASLogic2 = LOW;
bool ASLogic3 = LOW;
bool ASLogic4 = LOW;
int var = 0;
int var1 = 0;
int var2 = 0;
int var3 = 0;
int var4 = 0;
int var5 = 0;
int var6 = 0;
int var7 = 0;
int var8 = 0;
int var9 = 0;

const byte PSVs[] = {42, 12, 53, 45};  //PSV = Pneumatic Solenoid  Valve
const byte Motors[] = {41 , 44, 43, 8, 13, 7, 47, 48, 49};
const byte PSs[] = {54, 19, 18, 60, 3, 2, 20, 21, 66};  //PS = PhotoElectric Switch
const byte ASs[] = {0,0,0,0,59,0,0,0,0,65,0,0,0,0,26,0,0,0,0,28};  //AS = Auto Switch
const byte Printer[] = {22,23,24};  //Printer's sensors I0.0,0.1,0.2
const byte Func3[] = {38,37,36};  //Printer's func key Q0.0,0.1,0.2

const byte TotalPSVs = sizeof(PSVs);
const byte TotalMotors = sizeof(Motors);
const byte TotalPSs = sizeof(PSs);
const byte TotalASs = sizeof(ASs);
const byte TotalPrinters = sizeof(Printer);
const byte TotalFunc3 = sizeof(Func3);

void setup()
{
  for(byte i=0; i<TotalPSVs; i++)
  {
    pinMode(PSVs[i], OUTPUT);
  }
  for(byte j=0; j<TotalMotors; j++)
  {
    pinMode(Motors[j], OUTPUT);
  }
  for(byte z=0; z<TotalFunc3; z++)
  {
    pinMode(Func3[z], OUTPUT);
  }
  for(byte k=0; k<TotalPSs; k++)
  {
    pinMode(PSs[k], INPUT);
  }
  for(byte l=0; l<TotalASs; l++)
  {
    pinMode(ASs[l], INPUT);
  }
  for(byte p=0; p<TotalPrinters; p++)
  {
    pinMode(Printer[p], INPUT);
  }

  
  Serial.begin(9600);
  while(!Serial)
  {
    ;
  }
  Ethernet.begin(mac , ip, subnet);
  server.begin();
  Serial.print("Server is at");
  Serial.println(Ethernet.localIP());
  Serial.println("Connecting. . .");
}

void loop()
{
  EthernetClient client = server.available();
  auto link = Ethernet.linkStatus();
  if(link == LinkON)
  {
    Ethernet.begin(mac , ip, subnet);
    server.begin();
    Serial.println("On");
    Serial.println(Ethernet.localIP());
    if(client)
    {
      while(client.connected())
      {
        if(client.available())
        {
          commandstr[counter] = client.read();
          
          if((int)commandstr[counter] == 10)
          {
            
          }
          else if((int)commandstr[counter] == 13)
          {
            
          }
          else
          {
            counter++;
          }
          if(counter>3)
          {
            if(commandstr[counter-1] == 'L' && commandstr[counter-2] == 'O' && commandstr[counter-3] == 'V')
            {
              counter = 0;
              String cmd(commandstr);

              if(cmd == "HelloVOL")
              {
                client.println("Welcome to Casetify Production Line");
                Serial.println("Welcome to Casetify Production Line");
              }
              /*else if(cmd == "stopLVOL")
              {
                client.println("TCP communcation is disconnected");
                client.flush();
                client.stop();
                for(byte m=0; m<TotalMotors; m++)
                {
                  digitalWrite(Motors[m],LOW);
                }
                for(byte n=0; n<TotalPSVs; n++)
                {
                  digitalWrite(PSVs[n],LOW);
                }
                break;
              }*/
              else if(cmd == "stopLVOL")
              {
                //digitalWrite(Motors[0], LOW);
                for(byte m=0; m<TotalMotors; m++)
                {
                  digitalWrite(Motors[m],LOW);
                }
                for(byte n=0; n<TotalPSVs; n++)
                {
                  digitalWrite(PSVs[n],LOW);
                }
                client.println("All motors & Valves stop");
                Serial.println("All motors & Valves stop");
                //client.println("Motor c1 is stopped");
                //Serial.println("Motor c1 is stopped");
              }
              else if(cmd == "startVOL")
              {
                //digitalWrite(Motors[0], LOW);
                for(byte m=0; m<TotalMotors; m++)
                {
                  digitalWrite(Motors[m],HIGH);
                }
                for(byte n=0; n<TotalPSVs; n++)
                {
                  digitalWrite(PSVs[n],HIGH);
                }
                client.println("All motors & Valves start");
                Serial.println("All motors & Valves start");
                //client.println("Motor c1 is stopped");
                //Serial.println("Motor c1 is stopped");
              }
              else if(cmd == "M1&M2VOL")
              {
                digitalWrite(Motors[1], HIGH);
                digitalWrite(Motors[0], HIGH);
                //digitalWrite(Motors[1], HIGH);
                client.println("Motor 1 && Motor 2 On Successful");
                Serial.println("Motor 1 && Motor 2 On Successful");
              }
              else if(cmd == "M2&M3VOL")
              {
                digitalWrite(Motors[1], HIGH);
                digitalWrite(Motors[2], HIGH);
                client.println("Motor 2 && Motor 3 On Successful");
                Serial.println("Motor 2 && Motor 3 On Successful");
              }
              else if(cmd == "M3&M4VOL")
              {
                digitalWrite(Motors[2], HIGH);
                digitalWrite(Motors[3], HIGH);
                client.println("Motor 3 && Motor 4 On Successful");
                Serial.println("Motor 3 && Motor 4 On Successful");
              }
              else if(cmd == "M4&M5VOL")
              {
                digitalWrite(PSVs[1], HIGH);
                digitalWrite(Motors[4], HIGH);
                client.println("Valve 4 && Motor 5 On Successful");
                Serial.println("Valve 4 && Motor 5 On Successful");
              }
              else if(cmd == "M5&M6VOL")
              {
                digitalWrite(Motors[4], HIGH);
                digitalWrite(Motors[5], HIGH);
                client.println("Motor 5 && Motor 6 On Successful");
                Serial.println("Motor 5 && Motor 6 On Successful");
              }
              else if(cmd == "M6&M7VOL")
              {
                digitalWrite(PSVs[2], HIGH);
                digitalWrite(Motors[6], HIGH);
                client.println("Valve 6 && Motor 7 On Successful");
                Serial.println("Valve 6 && Motor 7 On Successful");
              }
              else if(cmd == "M7&M8VOL")
              {
                digitalWrite(Motors[6], HIGH);
                digitalWrite(Motors[7], HIGH);
                Serial.println("Motor 7 && Motor 8 On Successful");
                client.println("Motor 7 && Motor 8 On Successful");
              }
              else if(cmd == "M8&M9VOL")
              {
                digitalWrite(Motors[7], HIGH);
                digitalWrite(Motors[8], HIGH);
                Serial.println("Motor 8 && Motor 9 On Successful");
                client.println("Motor 8 && Motor 9 On Successful");
              }
              else if(cmd == "P1&GoVOL")
              {
                digitalWrite(PSVs[0], HIGH);
                Serial.println("Object is pushed in C1!");
                client.println("Object is pushed in C1!");
              }
              else if(cmd == "P1&BkVOL")
              {
                digitalWrite(PSVs[0], LOW);
                Serial.println("Valve 1 is coming back !");
                client.println("Valve 1 is coming back !");
              }
              else if(cmd == "P4&BkVOL")
              {
                digitalWrite(PSVs[1], LOW);
                Serial.println("Valve 4 is coming back !");
                client.println("Valve 4 is coming back !");
              }
              else if(cmd == "P6&BkVOL")
              {
                digitalWrite(PSVs[2], LOW);
                Serial.println("Valve 6 is coming back !");
                client.println("Valve 6 is coming back !");
              }
              else if(cmd == "P9&GoVOL")
              {
                digitalWrite(PSVs[3], HIGH);
                Serial.println("Object is pushed in C9!");
                client.println("Object is pushed in C9!");
              }
              else if(cmd == "P9&BkVOL")
              {
                digitalWrite(PSVs[3], LOW);
                Serial.println("Valve 9 is coming back !");
                client.println("Valve 9 is coming back !");
              }
              else if(cmd == "CheckVOL")
              {
                var = var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9;
                String varStr = String(var);
                Serial.println("ConveyorStatus: "+varStr);
                client.println("ConveyorStatus: "+varStr);
              }
              else if(cmd == "P1Fu3VOL")
              {                
                digitalWrite(Func3[0], HIGH);
                delay(100);
                digitalWrite(Func3[0], LOW);
                Serial.println("Printer 1 Func3 on! ");
                client.println("Printer 1 Func3 on! ");
              }
              else if(cmd == "P2Fu3VOL")
              {
                digitalWrite(Func3[1], HIGH);
                delay(100);
                digitalWrite(Func3[1], LOW);
                Serial.println("Printer 2 Func3 on! ");
                client.println("Printer 2 Func3 on! ");
              }
              else if(cmd == "P3Fu3VOL") 
              {
                digitalWrite(Func3[2], HIGH);
                delay(100);
                digitalWrite(Func3[2], LOW);
                Serial.println("Printer 3 Func3 on! ");
                client.println("Printer 3 Func3 on! ");
              }
            } 
          }
        }
        
        bool PS1state = digitalRead(PSs[0]);  //read PhotoElectric Switch state
        bool PS2state = digitalRead(PSs[1]);
        bool PS3state = digitalRead(PSs[2]);
        bool PS4state = digitalRead(PSs[3]);
        bool PS5state = digitalRead(PSs[4]);
        bool PS6state = digitalRead(PSs[5]);
        bool PS7state = digitalRead(PSs[6]);
        bool PS8state = digitalRead(PSs[7]);
        bool PS9state = digitalRead(PSs[8]);
        
        bool Pr1state = digitalRead(Printer[0]); //read Printer PhotoElectric Switch state
        bool Pr2state = digitalRead(Printer[1]);
        bool Pr3state = digitalRead(Printer[2]);
        
        if(PS1state == HIGH)
        {
          if(alreadyprintdata1 == PS1state)
          {
            delay(300);
            Serial.println("Conveyor 1 has Object !");
            client.println("Conveyor 1 has Object !");
            digitalWrite(Motors[0], LOW);
            Serial.println("Motor 1 is stopped !");
            client.println("Motor 1 is stopped !");
            var1 = var1 + 1;
            alreadyprintdata1 = !PS1state;
          }
        }
        else if(PS1state == LOW)
        {
          if(alreadyprintdata1 == PS1state)
          {
            Serial.println("No Object in Conveyor 1 !");
            client.println("No Object in Conveyor 1 !");
            var1 = 0;
            alreadyprintdata1 = !PS1state;
          }
        }
        if(PS2state == HIGH)
        {
          if(alreadyprintdata2 == PS2state)
          {
            Serial.println("Conveyor 2 has Object !");
            client.println("Conveyor 2 has Object !");
            digitalWrite(Motors[1], LOW);
            Serial.println("Motor 2 is stopped !");
            client.println("Motor 2 is stopped !");
            var2 = var2 + 2;
            alreadyprintdata2 = !PS2state;
          }
        }
        else if(PS2state == LOW)
        {
          if(alreadyprintdata2 == PS2state)
          {
            Serial.println("No Object in Conveyor 2 !");
            client.println("No Object in Conveyor 2 !");
            var2 = 0;
            alreadyprintdata2 = !PS2state;
          }
        }
        if(PS3state == HIGH)
        {
          if(alreadyprintdata3 == PS3state)
          {
            Serial.println("Conveyor 3 has Object !");
            client.println("Conveyor 3 has Object !");
            digitalWrite(Motors[1], LOW);
            digitalWrite(Motors[2], LOW);
            Serial.println("Motor 2 & 3 are stopped !");
            client.println("Motor 2 & 3 are stopped !");
            var3 = var3 + 4;
            alreadyprintdata3 = !PS3state;
          }
        }
        else if(PS3state == LOW)
        {
          if(alreadyprintdata3 == PS3state)
          {
            Serial.println("No Object in Conveyor 3 !");
            client.println("No Object in Conveyor 3 !");
            var3 = 0;
            alreadyprintdata3 = !PS3state;
          }
        }
        if(PS4state == HIGH)
        {
          if(alreadyprintdata4 == PS4state)
          {
            Serial.println("Conveyor 4 has Object !");
            client.println("Conveyor 4 has Object !");
            digitalWrite(Motors[2], LOW);
            digitalWrite(Motors[3], LOW);
            Serial.println("Motor 3 & 4 are stopped !");
            client.println("Motor 3 & 4 are stopped !");
            var4 = var4 + 8;
            alreadyprintdata4 = !PS4state;
          }
        }
        else if(PS4state == LOW)
        {
          if(alreadyprintdata4 == PS4state)
          {
            Serial.println("No Object in Conveyor 4 !");
            client.println("No Object in Conveyor 4 !");
            var4 = 0;
            alreadyprintdata4 = !PS4state;
          }
        }
        if(PS5state == HIGH)
        {
          if(alreadyprintdata5 == PS5state)
          {
            delay(1000);
            Serial.println("Conveyor 5 has Object !");
            client.println("Conveyor 5 has Object !");
            digitalWrite(Motors[4], LOW);
            Serial.println("Motor 5 is stopped !");
            client.println("Motor 5 is stopped !");
            var5 = var5 + 16;
            alreadyprintdata5 = !PS5state;
          }
        }
        else if(PS5state == LOW)
        {
          if(alreadyprintdata5 == PS5state)
          {
            Serial.println("No Object in Conveyor 5 !");
            client.println("No Object in Conveyor 5 !");
            var5 = 0;
            alreadyprintdata5 = !PS5state;
          }
        }
        if(PS6state == HIGH)
        {
          if(alreadyprintdata6 == PS6state)
          {
            Serial.println("Conveyor 6 has Object !");
            client.println("Conveyor 6 has Object !");
            digitalWrite(Motors[4], LOW);
            digitalWrite(Motors[5], LOW);
            Serial.println("Motor 5 & 6 are stopped !");
            client.println("Motor 5 & 6 are stopped !");
            var6 = var6 + 32;
            alreadyprintdata6 = !PS6state;
          }
        }
        else if(PS6state == LOW)
        {
          if(alreadyprintdata6 == PS6state)
          {
            Serial.println("No Object in Conveyor 6 !");
            client.println("No Object in Conveyor 6 !");
            var6 = 0;
            alreadyprintdata6 = !PS6state;
          }
        }
        if(PS7state == HIGH)
        {
          if(alreadyprintdata7 == PS7state)
          {
            Serial.println("Conveyor 7 has Object !");
            client.println("Conveyor 7 has Object !");
            digitalWrite(Motors[6], LOW);
            Serial.println("Motor 7 is stopped !");
            client.println("Motor 7 is stopped !");
            var7 = var7 + 64;
            alreadyprintdata7 = !PS7state;
          }
        }
        else if(PS7state == LOW)
        {
          if(alreadyprintdata7 == PS7state)
          {
            Serial.println("No Object in Conveyor 7 !");
            client.println("No Object in Conveyor 7 !");
            var7 = 0;
            alreadyprintdata7 = !PS7state;
          }
        }
        if(PS8state == HIGH)
        {
          if(alreadyprintdata8 == PS8state)
          {
            Serial.println("Conveyor 8 has Object !");
            client.println("Conveyor 8 has Object !");
            digitalWrite(Motors[6], LOW);
            digitalWrite(Motors[7], LOW);
            Serial.println("Motor 7 & 8 are stopped !");
            client.println("Motor 7 & 8 are stopped !");
            var8 = var8 + 128;
            alreadyprintdata8 = !PS8state;
          }
        }
        else if(PS8state == LOW)
        {
          if(alreadyprintdata8 == PS8state)
          {
            Serial.println("No Object in Conveyor 8 !");
            client.println("No Object in Conveyor 8 !");
            var8 = 0;
            alreadyprintdata8 = !PS8state;
          }
        }
        if(PS9state == HIGH)
        {
          if(alreadyprintdata9 == PS9state)
          {
            Serial.println("Conveyor 9 has Object !");
            client.println("Conveyor 9 has Object !");
            digitalWrite(Motors[7], LOW);
            digitalWrite(Motors[8], LOW);
            Serial.println("Motor 8 & 9 are stopped !");
            client.println("Motor 8 & 9 are stopped !");
            var9 = var9 + 256;
            alreadyprintdata9 = !PS9state;
          }
        }
        else if(PS9state == LOW)
        {
          if(alreadyprintdata9 == PS9state)
          {
            Serial.println("No Object in Conveyor 9 !");
            client.println("No Object in Conveyor 9 !");
            var9 = 0;
            alreadyprintdata9 = !PS9state;
          }
        }

        if(Pr1state == LOW)
        {
          if(alreadyprintdata10 == Pr1state)
          {
            Serial.println("No Object in Printer 1 !");
            client.println("No Object in Printer 1 !");
            alreadyprintdata10 = !Pr1state;
          }
        }     
        else if(Pr1state == HIGH)
        {
          if(alreadyprintdata10 == Pr1state)
          {
            Serial.println("Object detected in Printer 1 !");
            client.println("Object detected in Printer 1 !");
            alreadyprintdata10 = !Pr1state;
          }
        }
        
        if(Pr2state == LOW)
        {
          if(alreadyprintdata11 == Pr2state)
          {
            Serial.println("No Object in Printer 2 !");
            client.println("No Object in Printer 2 !");
            alreadyprintdata11 = !Pr2state;
          }
        }   
        else if(Pr2state == HIGH)
        {
          if(alreadyprintdata11 == Pr2state)
          {
            Serial.println("Object detected in Printer 2 !");
            client.println("Object detected in Printer 2 !");
            alreadyprintdata11 = !Pr2state;
          }
        }
        
        if(Pr3state == LOW)
        {
          if(alreadyprintdata12 == Pr3state)
          {
            Serial.println("No Object in Printer 3 !");
            client.println("No Object in Printer 3 !");
            alreadyprintdata12 = !Pr3state;
          }
        }
        else if(Pr3state == HIGH)
        {
          if(alreadyprintdata12 == Pr3state)
          {
            Serial.println("Object detected in Printer 3 !");
            client.println("Object detected in Printer 3 !");
            alreadyprintdata12 = !Pr3state;
          }
        }
      
        bool AS1upstate1 = digitalRead(ASs[0]);
        bool AS1upstate2 = digitalRead(ASs[1]);
        bool AS1downstate1 = digitalRead(ASs[2]);
        bool AS1downstate2 = digitalRead(ASs[3]);
        bool AS1pushstate = digitalRead(ASs[4]);
        bool AS4upstate1 = digitalRead(ASs[5]);
        bool AS4upstate2 = digitalRead(ASs[6]);
        bool AS4downstate1 = digitalRead(ASs[7]);
        bool AS4downstate2 = digitalRead(ASs[8]);
        bool AS4pushstate = digitalRead(ASs[9]);
        bool AS6upstate1 = digitalRead(ASs[10]);
        bool AS6upstate2 = digitalRead(ASs[11]);
        bool AS6downstate1 = digitalRead(ASs[12]);
        bool AS6downstate2 = digitalRead(ASs[13]);
        bool AS6pushstate = digitalRead(ASs[14]);
        bool AS9upstate1 = digitalRead(ASs[15]);
        bool AS9upstate2 = digitalRead(ASs[16]);
        bool AS9downstate1 = digitalRead(ASs[17]);
        bool AS9downstate2 = digitalRead(ASs[18]);
        bool AS9pushstate = digitalRead(ASs[19]);
      

        if(AS1pushstate == HIGH)
        {
          if(ASLogic1 == AS1pushstate)
          {
            client.println("Valve 1 is back !");
            Serial.println("Valve 1 is back !");
            ASLogic1 = !ASLogic1;
          }
        }
        else if(AS1pushstate == LOW)
        {
          if(ASLogic1 == AS1pushstate)
          {
            client.println("Valve 1 pushes object !");
            Serial.println("Valve 1 pushes object !");
            ASLogic1 = !ASLogic1;
          }
        }
        if(AS4pushstate == HIGH)
        {
          if(ASLogic2 == AS4pushstate)
          {
            client.println("Valve 4 is back !");
            Serial.println("Valve 4 is back !");
            ASLogic2 = !ASLogic2;
          }
        }
        else if(AS4pushstate == LOW)
        {
          if(ASLogic2 == AS4pushstate)
          {
            client.println("Valve 4 pushes object !");
            Serial.println("Valve 4 pushes object !");
            ASLogic2 = !ASLogic2;
          }
        }
        if(AS6pushstate == HIGH)
        {
          if(ASLogic3 == AS6pushstate)
          {
            client.println("Valve 6 is back !");
            Serial.println("Valve 6 is back !");
            ASLogic3 = !ASLogic3;
          }
        }
        else if(AS6pushstate == LOW)
        {
          if(ASLogic3 == AS6pushstate)
          {
            client.println("Valve 6 pushes object !");
            Serial.println("Valve 6 pushes object !");
            ASLogic3 = !ASLogic3;
          }
        }
        if(AS9pushstate == HIGH)
        {
          if(ASLogic4 == AS9pushstate)
          {
            client.println("Valve 9 is back !");
            Serial.println("Valve 9 is back !");
            ASLogic4 = !ASLogic4;
          }
        }
        else if(AS9pushstate == LOW)
        {
          if(ASLogic4 == AS9pushstate)
          {
            client.println("Valve 9 pushes object !");
            Serial.println("Valve 9 pushes object !");
            ASLogic4 = !ASLogic4;
          }
        }
        /*if(AS1upstate == HIGH && AS1downstate == LOW && AS1pushstate == LOW)
        {
          if(ASLogic1 = HIGH)
          {
            client.println("Valve 1 pushes object !");
            Serial.println("Valve 1 pushes object !");
            ASLogic1 = !ASLogic1;
          }
        }
        else if(AS1upstate == LOW && AS1downstate == HIGH && AS1pushstate == HIGH)
        {
          if(ASLogic1 == LOW)
          {
            client.println("Valve 1 is back!");
            Serial.println("Valve 1 is back!");
            ASLogic1 = !ASLogic1;
          }
        }
        if(AS4upstate == HIGH && AS4downstate == LOW && AS4pushstate == LOW)
        {
          if(ASLogic2 = HIGH)
          {
            client.println("Valve 4 pushes object !");
            Serial.println("Valve 4 pushes object !");
            ASLogic2 = !ASLogic2;
          }
        }
        else if(AS4upstate == LOW && AS4downstate == HIGH && AS4pushstate == HIGH)
        {
          if(ASLogic2 == LOW)
          {
            client.println("Valve 4 is back!");
            Serial.println("Valve 4 is back!");
            ASLogic2 = !ASLogic2;
          }
        }*/
      }
    }
  }

  if(link == LinkOFF)
  {
    Serial.println("Off default");
    client.flush();
    client.stop();
    digitalWrite(Motors[0], LOW);
    digitalWrite(Motors[1], LOW);
    digitalWrite(Motors[2], LOW);
    digitalWrite(Motors[3], LOW);
    digitalWrite(Motors[4], LOW);
    digitalWrite(Motors[5], LOW);
    digitalWrite(Motors[6], LOW);
    digitalWrite(Motors[7], LOW);
    digitalWrite(Motors[8], LOW);
    /*for(byte b = 0; b<9; b++)
    {
      digitalWrite(Motors[b],LOW);
    }*/
    Serial.println("default Client is stopped !");
    Serial.println(Ethernet.localIP());
  }
  delay(1000);
}
