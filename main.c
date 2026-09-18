#include <stdint.h>
#include "gpio.h"


int main(void)
{
	GPIO_Config_t led = { GPIO_PORT_G, 13};
	GPIO_Init(&led);
	while(1)
	{
		GPIO_Toggle(GPIO_PORT_G, 13);
		for(volatile int i = 0; i < 500000; i++);
	}
}
