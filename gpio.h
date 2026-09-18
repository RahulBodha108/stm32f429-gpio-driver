/*
 * gpio.h
 *
 *  Created on: 18-Sept-2026
 *      Author: brahu
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

typedef enum
{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H,
    GPIO_PORT_I
} GPIO_Port_t;

typedef enum
{
	GPIO_LOW = 0,
	GPIO_HIGH = 1
}GPIO_State_t;

typedef enum {
	GPIO_OUTPUT = 0,
	GPIO_INPUT  = 1
}GPIO_Mode_t;

typedef struct
{
	GPIO_Port_t port;
	uint8_t pin;
	GPIO_Mode_t mode;
}GPIO_Config_t;

void GPIO_Init(const GPIO_Config_t *config);
void GPIO_Write(GPIO_Port_t port, uint8_t pin, GPIO_State_t state);
GPIO_State_t GPIO_Read( GPIO_Port_t port, uint8_t pin);
void GPIO_Toggle(GPIO_Port_t port, uint8_t pin);
#endif /* GPIO_H_ */
