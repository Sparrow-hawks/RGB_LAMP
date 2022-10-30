/*
 * LED_Func.c
 *
 *  Author: Sparrow-hawk
 *  Email:	sparrow-hawk@hotmail.com
 */ 

#include "LED_Func.h"

#if (((LED_MAX_LEVEL) * 3) <= 255)
	typedef uint8_t UINT;
#else
	typedef uint16_t UINT;
#endif

#define LED_PERIOD_BY_3	(LED_MAX_LEVEL)
#define LED_PERIOD		((UINT)(LED_MAX_LEVEL) * 3)


static struct {
	uint8_t colorChange;
	uint16_t step;
} __LED_Control;

static uint8_t __LED_funcR(uint16_t x) {
	x = x % LED_PERIOD;
	
	uint8_t y;
	if (x < 1 * LED_PERIOD_BY_3)
	{
		y = LED_MAX_LEVEL - x;
	}
	else if (x < 2 * LED_PERIOD_BY_3)
	{
		y = 0;
	}
	else
	{	
		y = x - 2 * LED_MAX_LEVEL;
	}
	
	return y;
}

static uint8_t __LED_funcG(uint16_t x)
{
	x = x % LED_PERIOD;
	
	uint8_t y;
	if (x < 1 * LED_PERIOD_BY_3)
	{
		y = x;
	}
	else if (x < 2 * LED_PERIOD_BY_3)
	{
		y = 2 * LED_MAX_LEVEL - x;
	}
	else
	{
		y = 0;
	}
	
	return y;
}

static uint8_t __LED_funcB(uint16_t x)
{
		x = x % LED_PERIOD;
		
		uint8_t y;
		if (x < 1 * LED_PERIOD_BY_3)
		{
			y = 0;
		}
		else if (x < 2 * LED_PERIOD_BY_3)
		{
			y = x - LED_MAX_LEVEL;
		}
		else
		{
			y = 3 * LED_MAX_LEVEL - x;
		}
		
		return y;
}

void LED_ColorChangeEnable(void) {
	__LED_Control.colorChange = 1;
}

void LED_ColorChangeDisable(void) {
	__LED_Control.colorChange = 0;
}

Color_t LED_NextColor(void) {
	Color_t color;
	
	uint16_t step = __LED_Control.step++;
	
	color.r = __LED_funcR(step);
	color.g = __LED_funcG(step);
	color.b = __LED_funcB(step);
	
	return color;
}

