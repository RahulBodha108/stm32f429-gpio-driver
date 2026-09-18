/*
 * gpio.c
 *
 *  Created on: 18-Sept-2026
 *      Author: brahu
 */

#include "gpio.h"
#include "stm32f429xx.h"

static GPIO_TypeDef *GPIO_GetPort(GPIO_Port_t port)
{
	switch (port)
	{
	case GPIO_PORT_A: return GPIOA;
	case GPIO_PORT_B: return GPIOB;
	case GPIO_PORT_C: return GPIOC;
	case GPIO_PORT_D: return GPIOD;
	case GPIO_PORT_E: return GPIOE;
	case GPIO_PORT_F: return GPIOF;
	case GPIO_PORT_G: return GPIOG;
	case GPIO_PORT_H: return GPIOH;
	case GPIO_PORT_I: return GPIOI;
	default: return 0;

	}
}

static void GPIO_EnableClock(GPIO_Port_t port)
{
	RCC->AHB1ENR |= (1U << port);
}

void GPIO_Init(const GPIO_Config_t *config)
{
	GPIO_TypeDef *gpio;
	gpio = GPIO_GetPort(config->port);

	if(gpio == 0)
	{
		return;
	}

	GPIO_EnableClock(config->port);

	gpio->MODER &= ~(3U << (config->pin *2));
	if(config->mode == GPIO_OUTPUT)
	{
		gpio->MODER |=  (1U << (config->pin *2));
	}
}

void GPIO_Write(GPIO_Port_t port, uint8_t pin, GPIO_State_t state)
{
	GPIO_TypeDef *gpio;

	gpio = GPIO_GetPort(port);

	if(gpio == 0)
	{
		return;
	}

	if(state == GPIO_HIGH)
	{
		gpio->BSRR = (1U << pin);
	}
	else
	{
		gpio->BSRR = (1U << (pin + 16U));
	}
}

void GPIO_Toggle(GPIO_Port_t port, uint8_t pin)
{
	GPIO_TypeDef *gpio;

	gpio = GPIO_GetPort(port);

	if(gpio == 0)
	{
		return;
	}

	if(gpio->ODR & (1U << pin))
	{
		gpio->BSRR = (1U << (pin =16U));
	}
	else
	{
		gpio->BSRR = (1U << pin);
	}

}
