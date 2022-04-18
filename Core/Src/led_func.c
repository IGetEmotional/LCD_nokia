#include "led_func.h"

extern SPI_HandleTypeDef hspi1;

#define STEP_2 0x21
#define STEP_3 0x90
#define LCD_X 84
#define LCD_Y 48

uint8_t command_byte[8]= {1,1,0,0,0,1,1,1};
uint8_t buffer[1] = {0};
static int dataLen = 8;

void led_init(void){
  HAL_GPIO_WritePin(LCD1_CE_GPIO_Port, LCD1_CE_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD1_RST_GPIO_Port, LCD1_RST_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD1_RST_GPIO_Port, LCD1_RST_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LCD1_CLK_GPIO_Port, LCD1_CLK_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LCD1_DC_GPIO_Port, LCD1_DC_Pin, GPIO_PIN_RESET);
  //step 2
  buffer[0] = 0x21;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  //step 3
  buffer[0] = 0xC0;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0xBA;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x04;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x14;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  //step 4
  buffer[0] = 0x20;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  //step 5
  buffer[0] = 0x0C;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
}
void loop(){
  while(1){
    HAL_GPIO_WritePin(LCD1_DC_GPIO_Port, LCD1_DC_Pin, GPIO_PIN_RESET);
  buffer[0] = 0x20;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x40;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x80;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  HAL_GPIO_WritePin(LCD1_DC_GPIO_Port, LCD1_DC_Pin, GPIO_PIN_SET);
  
  buffer[0] = 0x00;                                                   //n
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x4;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                                    //e
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
   buffer[0] = 0x15;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                               
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x1F;                                                      //s
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x11;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                                       //o
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
   buffer[0] = 0x11;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                                        //v
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x15;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0xA;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                                        //e
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
   buffer[0] = 0x15;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                                         //t
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                                         //u
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x13;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0xC;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
   buffer[0] = 0x3;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                                         //yu
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
   buffer[0] = 0x4;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x11;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x1F;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  
  buffer[0] = 0x00;                                                          // !
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x17;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x00;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  HAL_Delay(50);
 // HAL_GPIO_WritePin(LCD1_RST_GPIO_Port, LCD1_RST_Pin, GPIO_PIN_RESET);
 // buffer[0] = 0xD;
 // HAL_GPIO_WritePin(LCD1_DC_GPIO_Port, LCD1_DC_Pin, GPIO_PIN_RESET);
  //HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
}
 
}

void lcd_clear(void){
  buffer[0] = 0x00;
  HAL_GPIO_WritePin(LCD1_DC_GPIO_Port, LCD1_DC_Pin, GPIO_PIN_SET);
  for(int xy = 0; xy < LCD_X * LCD_Y / 8; xy++){
  HAL_SPI_Transmit(&hspi1, (uint8_t*) buffer, 1, 50);
  }
   HAL_GPIO_WritePin(LCD1_DC_GPIO_Port, LCD1_DC_Pin, GPIO_PIN_RESET);
  }

  void get_letter(uint8_t letter){
  HAL_GPIO_WritePin(LCD1_DC_GPIO_Port, LCD1_DC_Pin, GPIO_PIN_SET);
    if(letter <= 0x7F){                                                   //latin
  HAL_SPI_Transmit(&hspi1, (uint8_t*)ASCII[letter - 0x20], 5, 10);
    }
    if(letter >= 0x90 && letter <= 0xA8 && letter != 0x91){                                 //cyrillic big 
    HAL_SPI_Transmit(&hspi1, (uint8_t*)RUS[letter - 0x90], 5, 10);
    }
    if(letter >= 0xA9 && letter <=0xAF){
    HAL_SPI_Transmit(&hspi1, (uint8_t*)RUS_add[letter - 0xA9], 6, 10);
    }
    if(letter >= 0xB0 && letter <= 0xBF){
    HAL_SPI_Transmit(&hspi1, (uint8_t*)RUS_2[letter-0xB0], 5, 10);
    }
    if(letter >= 0x80 && letter <= 0x88 && letter != 0x81){
    HAL_SPI_Transmit(&hspi1, (uint8_t*)RUS_2[letter - 0x80 + 16], 5, 10);
    }
    if(letter >= 0x89 && letter <= 0x8F){
    HAL_SPI_Transmit(&hspi1, (uint8_t*)RUS_add_2[letter - 0x89], 6, 10);
    }
    if(letter == 0x91){
    HAL_SPI_Transmit(&hspi1, (uint8_t*)yo_little, 5, 20);
    }
    if(letter == 0x81){
    HAL_SPI_Transmit(&hspi1, (uint8_t*)yo_big, 3, 10);
    }

            buffer[0] = 0x00; 
    HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 10);
  }
  
  void set_position(uint8_t X, uint8_t Y){
  HAL_GPIO_WritePin(LCD1_DC_GPIO_Port, LCD1_DC_Pin, GPIO_PIN_RESET);
  buffer[0] = 0x20;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x40+ Y;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  buffer[0] = 0x80 + X;
  HAL_SPI_Transmit(&hspi1, (uint8_t*)buffer, 1, 100);
  }

    
