/*
 * -------------------------------------------------------------------
 *               CD4013BE CMOS Dual D-TypeFlip-Flop 
 * -------------------------------------------------------------------
 * Author: Hesham El-sewify (LehKeda) 
 * Last edit: 11th of March 2019
 * 
 * There're two ways to operate this IC:
 *-> Method #1
 *  By setting D(data) pin directly from the microconroller
 *  then shift the data to Q(output) pin
 *  
 *-> Method #2
 *  By using the set pin of the IC
 *  set the set pin to HIGH to set the D(data)
 *  pin to HIGH then shift the data to Q(output)
 *  pin. setting set pin to LOW won't set D pin 
 *  to HIGH.
 *  
 *  Note: 
 *  I'm only using one Flip-Flop (Pins 1 to 6).
 *  
 *  Wiring:
 * /---------------------------------------------------------------\
 * | Pin Name      |     Pin No (IC)  |  Pin No (Microcontroller)  |
 * ----------------------------------------------------------------|
 * | Q1, Q`1 (o/p) |       1, 2       |    (Connected to LEDs)     |
 * | Clock 1       |         3        |           8                |
 * | Reset 1       |         4        |       GND (Disabled)       |
 * | Data 1        |         5        |           7                |
 * | Set 1         |         6        |           6                |
 * | VDD           |         14       |          +5v               |
 * | VSS           |         7        |          GND               |
 * | Q2, Q`2 (o/p) |       13, 12     |          (NC)              |
 * | Clock 2       |         11       |          (NC)              |
 * | Reset 2       |         10       |          (NC)              |
 * | Data 2        |         9        |          (NC)              |
 * | Set 2         |         8        |          (NC)              |
 * \---------------------------------------------------------------/
 */
 
int set1_pin= 6;
int d1_pin= 7;
int clk1_pin= 8;
#define METHOD 1

void setup() {
  pinMode(set1_pin, OUTPUT);
  pinMode(d1_pin, OUTPUT);
  pinMode(clk1_pin, OUTPUT);
  
#if METHOD == 1
  digitalWrite(set1_pin, LOW);
#endif
  
}

void loop() {
  
//---------------- Method 1 ----------------
#if METHOD == 1
  // Set D(data) to HIGH
  digitalWrite(d1_pin, HIGH);

  // Send data out (from D(data) to Q(output) )
  digitalWrite(clk1_pin, LOW);
  digitalWrite(clk1_pin, HIGH);
  
  delay(300);

  // Set D(data) to LOW
  digitalWrite(d1_pin, LOW);

  // Send data out (from D(data) to Q(output) )
  digitalWrite(clk1_pin, LOW);
  digitalWrite(clk1_pin, HIGH);

  delay(300);

//---------------- Method 2 ----------------
#else if METHOD == 2
  // Set set_pin to HIGH to set "D(data)" value HIGH
  digitalWrite(set1_pin, HIGH);
  
  // Send data out (from D(data) to Q(output) )
  digitalWrite(clk1_pin, LOW);
  digitalWrite(clk1_pin, HIGH);
  
  delay(300);

  // Release set pin (sets D to LOW)
  digitalWrite(set1_pin, LOW);

  // Send data out (from D(data) to Q(output) )
  digitalWrite(clk1_pin, LOW);
  digitalWrite(clk1_pin, HIGH);

  delay(300);

#endif  
}
