#include"I2C_16X2_LCD.c"

void I2C_init();
void I2C_start();
void I2C_stop();
void I2C_write(uint8_t data);
void LCD_send_nibble(uint8_t data);
void LCD_send_byte(uint8_t data, uint8_t mode);
void LCD_command(uint8_t command);
void LCD_data(uint8_t data);
void LCD_init();
void LCD_set_cursor(uint8_t col, uint8_t row);
void LCD_print(char *str);
