/*
 * common.h
 *
 *  Created on: Jan 12, 2023
 *      Author: kaizen
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stm32f4xx_hal.h>
#include <stm32F4xx_hal_gpio.h>
#include "cmsis_os.h"
#include "main.h"

#define APPLICATION_INFO                                "SWIM Example"

#define ANSI_COLOR_RED               			        (0x031)
#define ANSI_COLOR_GREEN             			        (0x032)
#define ANSI_COLOR_YELLOW            			        (0x033)
#define ANSI_COLOR_BLUE              			        (0x034)
#define ANSI_COLOR_MAGENTA           			        (0x035)
#define ANSI_COLOT_CYAN              			        (0x036)

#define TRACE_MSG(fmt, ...) 							printf(fmt"\r\n", ##__VA_ARGS__)
#define TRACE_COLOR(COLOR_CODE, fmt, ...) 				printf("\033[%xm"fmt"\033[m\r\n", COLOR_CODE, ##__VA_ARGS__)

#define TRACE_COLOR_RED(fmt, ...) 						printf("\033[%xm"fmt"\033[m\r\n", ANSI_COLOR_RED, ##__VA_ARGS__)
#define TRACE_COLOR_GREEN(fmt, ...) 					printf("\033[%xm"fmt"\033[m\r\n", ANSI_COLOR_GREEN, ##__VA_ARGS__)
#define TRACE_COLOR_YELLOW(fmt, ...) 					printf("\033[%xm"fmt"\033[m\r\n", ANSI_COLOR_YELLOW, ##__VA_ARGS__)
#define TRACE_COLOR_BLUE(fmt, ...) 						printf("\033[%xm"fmt"\033[m\r\n", ANSI_COLOR_BLUE, ##__VA_ARGS__)
#define TRACE_COLOR_MAGENTA(fmt, ...) 					printf("\033[%xm"fmt"\033[m\r\n", ANSI_COLOR_MAGENTA, ##__VA_ARGS__)
#define TRACE_COLOR_CYAN(fmt, ...) 						printf("\033[%xm"fmt"\033[m\r\n", ANSI_COLOT_CYAN, ##__VA_ARGS__)

#define TRACE_DEBUG(fmt, ...)   						TRACE_MSG(fmt, ##__VA_ARGS__)
#define TRACE_INFO(fmt, ...)    						TRACE_COLOR_GREEN(fmt, ##__VA_ARGS__)
#define TRACE_WARN(fmt, ...)    						TRACE_COLOR_CYAN(fmt, ##__VA_ARGS__)
#define TRACE_ERROR(fmt, ...)   						TRACE_COLOR_RED(fmt, ##__VA_ARGS__)

#define TRACE_MSG_WITHOUT_NL(fmt, ...)          		printf(fmt, ##__VA_ARGS__)
#define TRACE_COLOR_WITHOUT_NL(COLOR_CODE, fmt, ...)	printf("\033[%xm"fmt"\033[m", COLOR_CODE, ##__VA_ARGS__)
#define TRACE_COLOR_RED_WITHOUT_NL(fmt, ...) 			printf("\033[%xm"fmt"\033[m", ANSI_COLOR_RED, ##__VA_ARGS__)
#define TRACE_COLOR_GREEN_WITHOUT_NL(fmt, ...) 			printf("\033[%xm"fmt"\033[m", ANSI_COLOR_GREEN, ##__VA_ARGS__)
#define TRACE_COLOR_YELLOW_WITHOUT_NL(fmt, ...) 		printf("\033[%xm"fmt"\033[m", ANSI_COLOR_YELLOW, ##__VA_ARGS__)
#define TRACE_COLOR_BLUE_WITHOUT_NL(fmt, ...) 			printf("\033[%xm"fmt"\033[m", ANSI_COLOR_BLUE, ##__VA_ARGS__)
#define TRACE_COLOR_MAGENTA_WITHOUT_NL(fmt, ...) 		printf("\033[%xm"fmt"\033[m", ANSI_COLOR_MAGENTA, ##__VA_ARGS__)
#define TRACE_COLOR_CYAN_WITHOUT_NL(fmt, ...) 			printf("\033[%xm"fmt"\033[m", ANSI_COLOT_CYAN, ##__VA_ARGS__)

#define TRACE_DEBUG_WITHOUT_NL(fmt, ...)   				TRACE_MSG_WITHOUT_NL(fmt, ##__VA_ARGS__)
#define TRACE_INFO_WITHOUT_NL(fmt, ...)    				TRACE_COLOR_GREEN_WITHOUT_NL(fmt, ##__VA_ARGS__)
#define TRACE_WARN_WITHOUT_NL(fmt, ...)    				TRACE_COLOR_CYAN_WITHOUT_NL(fmt, ##__VA_ARGS__)
#define TRACE_ERROR_WITHOUT_NL(fmt, ...)   				TRACE_COLOR_RED_WITHOUT_NL(fmt, ##__VA_ARGS__)


#define MIN(x,y)  ((x) < (y) ? (x) : (y))





typedef struct {

}COMMON_CONTROL;


#endif /* INC_COMMON_H_ */
