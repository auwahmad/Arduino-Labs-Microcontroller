//**************************************************************//
//  Name    : Writing 4-bit binary values to LEDs
//  Author  : Atta ul Wasay
//  Date    : 13 Apr, 2021
//  Modified: 16 May, 2021
//  Version : 1.0
//  Notes   : Used bitRead() function
//
//****************************************************************

byte dec_value = 8;   // decimal value to be sent to 4 LEDs
int bit_value = 0;    // initializing an integer to store the bits of decimal value

void setup() {
  Serial.begin(9600);   // initializing Serial Communication

  Serial.print("value: ");    // displaying value to be displayed on 4-LEDs
  Serial.print(value, BIN);
  Serial.print(" : ");
  Serial.println(value);

  //set pins to output so you can control the shift register
  for (int pin = 8; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }

  // keeping the LEDs OFF in the beginning 
  for (int pin = 8; pin <= 11; pin++) {
    digitalWrite(pin, 0);
  }
}

void loop() {
  // reading each bits of the decimal value & writing to 4 LEDs
  for (int i = 0; i <= 3; i++) {
    bit_value = bitRead(dec_value, i);
    digitalWrite(i + 8, bit_value);
  }
}
