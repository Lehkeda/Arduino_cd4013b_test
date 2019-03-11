##CD4013BE CMOS Dual D-TypeFlip-Flop 

### There are two ways to operate this IC
 - ##### Method #1
   By setting D(data) pin directly from the microconroller
   then shift the data to Q(output) pin
   
 - ##### Method #2
   By using the set pin of the IC
   set the set pin to HIGH to set the D(data)
   pin to HIGH then shift the data to Q(output)
   pin. setting set pin to LOW won't set D pin 
   to HIGH.
   
### Note
   I am only using one Flip-Flop (Pins 1 to 6).
   
### Wiring

  | Pin Name      |     Pin No (IC)  |  Pin No (Microcontroller)  |
| :------------: | :------------: | :------------: |
  | Q1, Q`1 (o/p) |       1, 2       |    (Connected to LEDs)     |
  | Clock 1       |         3        |           8                |
  | Reset 1       |         4        |       GND (Disabled)       |
  | Data 1        |         5        |           7                |
  | Set 1         |         6        |           6                |
  | VDD           |         14       |          +5v               |
  | VSS           |         7        |          GND               |
  | Q2, Q`2 (o/p) |       13, 12     |          (NC)              |
  | Clock 2       |         11       |          (NC)              |
  | Reset 2       |         10       |          (NC)              |
  | Data 2        |         9        |          (NC)              |
  | Set 2         |         8        |          (NC)              |
