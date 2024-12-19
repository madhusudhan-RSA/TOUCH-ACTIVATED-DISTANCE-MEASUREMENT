#include <avr/io.h>
#include <util/delay.h>

// I2C Address of the LCD (change to 0x3F if needed)
#define LCD_I2C_ADDR 0x27

// I2C/TWI Functions
void I2C_init() {
    TWSR = 0x00;                     // Prescaler set to 1
    TWBR = ((F_CPU / 100000UL) - 16) / 2; // SCL frequency = 100kHz
    TWCR = (1 << TWEN);              // Enable TWI
}

void I2C_start() {
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT); // Send START condition
    while (!(TWCR & (1 << TWINT)));                  // Wait for TWINT to set
}

void I2C_stop() {
    TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT); // Send STOP condition
    while (TWCR & (1 << TWSTO));                     // Wait until STOP is executed
}

void I2C_write(uint8_t data) {
    TWDR = data;                      // Load data into TWDR register
    TWCR = (1 << TWEN) | (1 << TWINT); // Start transmission
    while (!(TWCR & (1 << TWINT)));   // Wait for TWINT to set
}

// LCD Functions
void LCD_send_nibble(uint8_t data) {
    I2C_start();
    I2C_write(LCD_I2C_ADDR << 1);  // Send I2C address with Write bit
    I2C_write(data | 0x08);        // Send data with backlight ON
    I2C_write(data | 0x0C);        // Enable = 1
    _delay_us(1);
    I2C_write(data | 0x08);        // Enable = 0
    _delay_us(100);
    I2C_stop();
}

void LCD_send_byte(uint8_t data, uint8_t mode) {
    uint8_t high_nibble = (data & 0xF0) | mode;
    uint8_t low_nibble = ((data << 4) & 0xF0) | mode;

    LCD_send_nibble(high_nibble); // Send high nibble
    LCD_send_nibble(low_nibble);  // Send low nibble
}

void LCD_command(uint8_t command) {
    LCD_send_byte(command, 0x00); // RS = 0 for command
    _delay_ms(2);
}

void LCD_data(uint8_t data) {
    LCD_send_byte(data, 0x01);    // RS = 1 for data
    _delay_ms(2);
}

void LCD_init() {
    _delay_ms(50);               // Wait for LCD to power up
    LCD_command(0x33);           // Initialize for 4-bit mode
    LCD_command(0x32);           // Initialize for 4-bit mode
    LCD_command(0x28);           // Function set: 4-bit, 2 lines
    LCD_command(0x0C);           // Display ON, Cursor OFF
    LCD_command(0x06);           // Entry mode: auto increment
    LCD_command(0x01);           // Clear display
    _delay_ms(2);
}

void LCD_set_cursor(uint8_t col, uint8_t row) {
    uint8_t address = 0x80 + (row * 0x40) + col; // Calculate DDRAM address
    LCD_command(address);
}

void LCD_print(char *str) {
    while (*str) {
        LCD_data(*str++);
    }
}
