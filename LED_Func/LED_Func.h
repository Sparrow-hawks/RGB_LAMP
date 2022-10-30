/*
 * LED_Func.h
 *
 *  Author: Sparrow-hawk
 *  Email:	sparrow-hawk@hotmail.com
 */ 


#ifndef LED_FUNC_H_
#define LED_FUNC_H_

#include <stdint.h>

#define LED_MAX_LEVEL			85				

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} LED_RGB_t;

uint8_t LED_funcR(uint16_t x);
uint8_t LED_funcG(uint16_t x);
uint8_t LED_funcB(uint16_t x);

#endif /* LED_FUNC_H_ */