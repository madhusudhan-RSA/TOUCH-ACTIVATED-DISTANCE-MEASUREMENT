#include <avr/io.h>
#include <util/delay.h>
#include"I2C_16X2_LCD.h"
#include"ultrasonic.h"
#include"touch_sensor.h"
#include"string.h"


#define F_CPU 16000000UL

int main(void) 
{
  double distance;
  char distance_text[7];
  
  I2C_init();    // Initialize I2C
  LCD_init();    // Initialize LCD
  UltrasonicInit(); // Initialize ULTRASONIC SENSOR
  touchSensorInit(); //Initialize TOUCH SENSOR
  // Display message
  LCD_set_cursor(0, 0);         // Set cursor to column 0, row 0
  LCD_print("-PROXIMITY DIST-");   // Print first line
  LCD_set_cursor(0, 1);         // Set cursor to column 0, row 0
  LCD_print("---MEASUREMENT--");   // Print first line
  _delay_ms(2000);
  while (1) 
  {
    if(touchSensorDebounce())
    {
      LCD_command(0x01);           // Clear display
      LCD_set_cursor(0, 0);         // Set cursor to column 0, row 0
      LCD_print("----DISTANCE----");   // Print first line
      distance = distanceUltrasonic();
      doubleToString(distance, distance_text);
      LCD_set_cursor(0, 1);         // Set cursor to column 0, row 0
      LCD_print(distance_text);   // Print first line
      LCD_print("cm");   // Print first line
    }
  }
}
