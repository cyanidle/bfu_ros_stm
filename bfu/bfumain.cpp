#include "main.h"
#include <string.h>

extern "C" {

extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;

}

const char* lol = "KEK!!!!\n";

extern "C" void bfumain() {

    HAL_UART_Transmit_DMA(&huart1, (uint8_t*)lol, strlen(lol));
}
