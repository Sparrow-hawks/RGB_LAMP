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
} Color_t;

void	LED_ColorChangeEnable(void);
void	LED_ColorChangeDisable(void);

Color_t LED_NextColor(void);

#endif /* LED_FUNC_H_ */