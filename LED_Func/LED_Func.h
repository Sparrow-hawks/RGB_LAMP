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
#define LED_LEVEL(L)			(255 - (L))

uint8_t LED_funcR(uint16_t x);
uint8_t LED_funcG(uint16_t x);
uint8_t LED_funcB(uint16_t x);

#endif /* LED_FUNC_H_ */