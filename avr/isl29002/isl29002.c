/*
 * Test ISL29002
 * @author 
 *
 */
#include <avr/io.h>

#define i2c_start()	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN)
#define i2c_stop()	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN)
#define i2c_wait()	while(!(TWCR&(1<<TWINT)))
#define i2c_ack()	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA)
#define i2c_noack()	TWCR = (1<<TWINT)|(1<<TWEN)

uint8_t buf[4];
#define CHIPADDR 0x40
void twi_init()
{
	TWCR = 0x00;
	TWBR = 0x02;
	TWSR = 0x02;
	TWAR = 0x02;
	TWCR = 0x44;
}
void i2c_read()
{
	i2c_start();
	i2c_wait();
	TWDR = CHIPADDR + 1;

	i2c_ack();
	i2c_wait();
	buf[0]= TWDR;
	i2c_noack();
	i2c_wait();
	buf[1]= TWDR;
	i2c_noack();
	i2c_wait();
	buf[2]= TWDR;
	i2c_noack();
	i2c_wait();
	buf[3]= TWDR;
	i2c_stop();
}
void i2c_write(uint8_t data)
{
	i2c_start();
	i2c_wait();
	TWDR = CHIPADDR;
	i2c_ack();
	i2c_wait();

	TWDR = data;
	i2c_ack();
	i2c_wait();
}
int main(void)
{
	twi_init();
	i2c_write(0x08);
	i2c_read();

	while(1);
	return 0;
}
