/* This file is part of rflpc. Copyright 2010-2011 Michael Hauspie
 *
 * rflpc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rflpc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rflpc.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
  Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>
  Created:
  Time-stamp: <2012-03-21 09:40:41 (hauspie)>
*/
#include <rflpc17xx/rflpc17xx.h>
#include <external_libs/nhd_spi_lcd/nhd_spi_lcd.h>

  // int binary(){
  // 	int i;
  // 	for (i = 1; i < 15; ++i){
  // 		rflpc_led_clr(RFLPC_LED_1);
  //     rflpc_led_clr(RFLPC_LED_2);
  //     rflpc_led_clr(RFLPC_LED_3);
  //     rflpc_led_clr(RFLPC_LED_4);
  //     rflpc_led_binary_value(i);
  //     int j;
  //     for (j = 0; j < 10000000; ++j);
  //     return 0;
  //   }
  // }

  static uint8_t buffer[(128*4)];

  void lcd_clear(void){
    int i=0;
    for (i = 0; i < sizeof(buffer); ++i) {
      buffer[i]=0x0;
    }
  }

  void set_pixel(int x, int y){
    buffer[(y>>3)*128+x] |= (1<<(y%8));
  }

  void draw_ball(int x, int y){
    set_pixel(x,y);set_pixel(x+1,y);
    set_pixel(x+1,y+1);set_pixel(x,y+1);

    // etat de la balle affiché au led
    if (x < 32){
      rflpc_led_set(RFLPC_LED_1);
      rflpc_led_clr(RFLPC_LED_2);
      rflpc_led_clr(RFLPC_LED_3);
      rflpc_led_clr(RFLPC_LED_4);
    }else if (x > 32 && x < 64){
      rflpc_led_clr(RFLPC_LED_1);
      rflpc_led_set(RFLPC_LED_2);
      rflpc_led_clr(RFLPC_LED_3);
      rflpc_led_clr(RFLPC_LED_4);
    }else if (x > 64 && x < 96){
      rflpc_led_clr(RFLPC_LED_1);
      rflpc_led_clr(RFLPC_LED_2);
      rflpc_led_set(RFLPC_LED_3);
      rflpc_led_clr(RFLPC_LED_4);
    }else if (x > 96 && x < 128){
      rflpc_led_clr(RFLPC_LED_1);
      rflpc_led_clr(RFLPC_LED_2);
      rflpc_led_clr(RFLPC_LED_3);
      rflpc_led_set(RFLPC_LED_4);
    }
  }

  void draw_paddle(int x,int y){
    int i,j;
    for(i=0;i<2;i++){
      for(j=0;j<8;j++){
        set_pixel(x+i,y+j);
      }
    }
  }

  void draw_net(void){
    int x=64;
    int i,flag=0;
    for(i=0;i<32;i++){
      if(i%4==0){
        if(flag){
          flag = 0;
        }else{
          flag = 1;
        }
      }
      if(flag){
        set_pixel(x,i);
      }
    }
  }

  int lire_pot(uint8_t pin){
    return (rflpc_adc_read(pin)/200);
  }

  int closeEnough(int yp,int yb){
    if (yb >= yp && yb <= yp+7){
      return 1;
    }return 0;
  }

  uint8_t chiffres[10][8] = {{0,0x7E, 0x7E, 0x42, 0x42, 0x7E, 0x7E, 0}, 
      {0, 0   , 0   , 0   , 0   , 0x7E, 0x7E, 0},
      {0, 0x72, 0x72, 0x52, 0x52, 0x5E, 0x5E, 0},
      {0, 0x52, 0x52, 0x52, 0x52, 0x7E, 0x7E, 0},
      {0, 0x1E, 0x1E, 0x10, 0x10, 0x7E, 0x7E, 0},
      {0, 0x5E, 0x5E, 0x52, 0x52, 0x72, 0x72, 0},
      {0, 0x7E, 0x7E, 0x52, 0x52, 0x72, 0x72, 0},
      {0, 0x02, 0x02, 0x02, 0x02, 0x7E, 0x7E, 0},
      {0, 0x7E, 0x7E, 0x52, 0x52, 0x7E, 0x7E, 0},
      {0, 0x5E, 0x5E, 0x52, 0x52, 0x7E, 0x7E, 0}};


  void draw_digit(int digit,int x){
    int i;
    for (i=0; i < 8; i ++){
     buffer[i+x] = chiffres[digit][i];
    }
  }

  int main(){
	#ifdef RFLPC_CONFIG_ENABLE_UART
    rflpc_uart_init(RFLPC_UART0);
	#endif

	#ifdef RFLPC_CONFIG_ENABLE_PRINTF
    printf("Hello World\r\n");
	#endif
    rflpc_led_init();
    nhd_spi_lcd_init(NHD_MAKE_SIZE(128,32), MBED_DIP6, MBED_DIP8, MBED_DIP11, RFLPC_SPI1);
    rflpc_adc_burst_init(RFLPC_CCLK, NULL);
    rflpc_adc_burst_enable(MBED_DIP19);
    rflpc_adc_burst_enable(MBED_DIP20);
    rflpc_adc_burst_start();
    lcd_clear();
    int xp1=0,yp1=1;
    draw_paddle(xp1,yp1);
    int xp2=126,yp2=1;
    draw_paddle(xp2,yp2);
    draw_net();
    int xb=3,yb=20;
    draw_ball(xb,yb);
    int down=1,right=1;
    int j1=0,j2=0;
    while (j1 != 9 && j2 != 9){
      if(down == 1 && right == 1){
        xb++;yb++;
      }
      if(down == 1 && right == 0){
        xb++;yb--;
      }
      if(down == 0 && right == 1){
        xb--;yb++;
      }
      if(down == 0 && right == 0){
        xb--;yb--;
      }

      yp1 = lire_pot(MBED_DIP19);
      yp2 = lire_pot(MBED_DIP20);

      if(xb == 0){
        if(closeEnough(yp1,yb) == 1){
          down = 1;
        }else{
           j2++;
           xb=64;
           yb=16;
          down = 1;
        }
      }
      else if(xb == 126){
        if(closeEnough(yp2,yb) == 1){
          down = 0;
        }else{
           j1++;
           xb=64;
           yb=16;
          down = 0;
        }
      }
      if(yb == 30){right = 0;}
      if(yb == 0){right = 1;}

      lcd_clear();
      draw_ball(xb,yb);
      draw_paddle(xp1,yp1);
      draw_paddle(xp2,yp2);
      draw_digit(j1,48);
      draw_digit(j2,72);
      draw_net();

      nhd_spi_lcd_display_buffer(buffer);
      int i;
      for (i = 0; i < 1000000; ++i);
    }
    if (j1 == 9){
      while(1){
        rflpc_led_set(RFLPC_LED_1);
        rflpc_led_clr(RFLPC_LED_2);
        rflpc_led_clr(RFLPC_LED_3);
        rflpc_led_clr(RFLPC_LED_4);
      }
    }else{
      while(1){
        rflpc_led_clr(RFLPC_LED_1);
        rflpc_led_clr(RFLPC_LED_2);
        rflpc_led_clr(RFLPC_LED_3);
        rflpc_led_set(RFLPC_LED_4);
      }
    }

    return 0;
  }


