
char data='0';
int x=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:0000000000000000000000000000000+
        if((digitalRead(3)==HIGH)&&(data=='0'))
              {
                Serial.write('1');
                data='1';
              }
        else if((digitalRead(3)==LOW)&&(data=='1'))
              {
                Serial.write('0');
                data='0';
              }
       delay(5); 
}
