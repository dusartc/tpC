#include "peripherals.h"


#define ADDR_OFFSET(addr, offset) ((uint32_t*)((uint8_t*)(addr) + offset));

void select_gpio_out_mode(uint32_t p) {
    uint32_t register_idx = 2*GET_PORT(p);
    uint32_t pin = GET_PIN(p);
    volatile uint32_t *dir_register;

    if (pin >= 16)
    {
    	pin -= 16;
    	register_idx++;
    }
    /* Configure function */
    PINSEL[register_idx] &= ~(3 << (pin * 2)); /* Clear the two function bits -> gpio mode (p. 108) */

    /* Configure mode */
    PINMODE[register_idx] &= ~(3 << (pin * 2)); /* Clear the two mode bit -> pull-up resistor */

    /* Configure opendrain */
    PINMODE_OD[GET_PORT(p)] &= ~(1 << GET_PIN(p)); /* Clear bit -> normal (not opendrain) mode */

    /* Set GPIO mode to output */
    dir_register = ADDR_OFFSET(&FIO0DIR, 0x20 * GET_PORT(p));
    *dir_register |= (1 << GET_PIN(p)); /* set bit to 1 -> set pin to output */
}

void select_gpio_in_mode(uint32_t p){
    uint32_t register_idx = 2*GET_PORT(p);
    uint32_t pin = GET_PIN(p);
    volatile uint32_t *dir_register;

    if (pin >= 16)
    {
        pin -= 16;
        register_idx++;
    }
    /* Configure function */
    PINSEL[register_idx] &= ~(3 << (pin * 2)); /* Clear the two function bits -> gpio mode (p. 108) */

    /* Configure mode */
    PINMODE[register_idx] |= (3 << (pin * 2)); /* Clear the two mode bit -> pull-up resistor */

    /* Configure opendrain */
    PINMODE_OD[GET_PORT(p)] &= ~(1 << GET_PIN(p)); /* Clear bit -> normal (not opendrain) mode */

    /* Set GPIO mode to output */
    dir_register = ADDR_OFFSET(&FIO0DIR, 0x20 * GET_PORT(p));
    *dir_register |= (2 << GET_PIN(p)); /* set bit to 1 -> set pin to output */
}

/* Set pin to HIGH */
void set_pin(uint32_t p)
{
    volatile uint32_t *set_register = ADDR_OFFSET(&FIO0SET, 0x20 * GET_PORT(p));
    volatile uint32_t *mask_register = ADDR_OFFSET(&FIO0MASK, 0x20 * GET_PORT(p));

    *mask_register = ~(1 << GET_PIN(p)); /* Affected pin are those whose mask is 0 */
    *set_register = (1 << GET_PIN(p)); /* Set pin to HIGH */
}

/* Clear pin to GND */
void clr_pin(uint32_t p)
{
    volatile uint32_t *clr_register = ADDR_OFFSET(&FIO0CLR, 0x20 * GET_PORT(p));
    volatile uint32_t *mask_register = ADDR_OFFSET(&FIO0MASK, 0x20 * GET_PORT(p));

    *mask_register = ~(1 << GET_PIN(p)); /* Affected pin are those whose mask is 0 */
    *clr_register = (1 << GET_PIN(p)); /* Set pin to GND */
}

int read_pin(uint32_t p){
    volatile uint32_t *pin_register = ADDR_OFFSET(&FIO0PIN, 0x20 * GET_PORT(p));
    volatile uint32_t *mask_register = ADDR_OFFSET(&FIO0MASK, 0x20 * GET_PORT(p));
    *mask_register = ~(1 << GET_PIN(p));
    return ((*pin_register & (1 << GET_PIN(p))) ? 1 : 0);
}


void wait(void)
{
    int i;
    uint32_t j;
    for (i=0 ; i < (10000) ; ++i)
       j = FIO0MASK;
    /* avoids an unused variable 'j' warning */
   if (j == (1000000))
       return ;
}

void config(){
    PINSEL[1] &= ~(1<<16);
    PINMODE[1] |= 3;
    PINMODE_OD[0] &= ~(1<<16);
    FIO0DIR &= ~(2<<16);
    FIO0MASK &= ~(1<<16);
}

int potentioActif(){
    if (((FIO0PIN) & ~(1<<16)) == (FIO0PIN)) {
        return 0;
    }else{
        return 1;
    }
}

void main(void)
{
    select_gpio_out_mode(MBED_BASE_LED1);
    select_gpio_out_mode(MBED_BASE_LED2);
    select_gpio_out_mode(MBED_BASE_LED3);
    select_gpio_out_mode(MBED_BASE_LED4);

    select_gpio_in_mode(MBED_BASE_DIP12);
    select_gpio_in_mode(MBED_BASE_DIP13);
    select_gpio_in_mode(MBED_BASE_DIP14);
    select_gpio_in_mode(MBED_BASE_DIP15);
    select_gpio_in_mode(MBED_BASE_DIP16);
    
    clr_pin(MBED_BASE_LED1);
    clr_pin(MBED_BASE_LED2);
    clr_pin(MBED_BASE_LED3);
    clr_pin(MBED_BASE_LED4);
    //config();
    
    while(1){
        if (read_pin(MBED_BASE_DIP12)){
            clr_pin(MBED_BASE_LED1);
            clr_pin(MBED_BASE_LED2);
            clr_pin(MBED_BASE_LED3);
            clr_pin(MBED_BASE_LED4);      
        }else if (read_pin(MBED_BASE_DIP13)){
            set_pin(MBED_BASE_LED1);
        }else if (read_pin(MBED_BASE_DIP14)){
            set_pin(MBED_BASE_LED2);
        }else if (read_pin(MBED_BASE_DIP15)){
            set_pin(MBED_BASE_LED3);
        }else if (read_pin(MBED_BASE_DIP16)){
            set_pin(MBED_BASE_LED4);
        }
        wait();
    }
}

void select_pwm_mode(void){
    (*(volatile uint32_t *) 0x400FC0C4) &= ~(1<<6);
    (*(volatile uint32_t *) 0x400FC1A8) &= ~(13 << 12);
}
    // select_gpio_out_mode(MBED_BASE_LED1);
    // select_gpio_out_mode(MBED_BASE_LED2);
    // select_gpio_out_mode(MBED_BASE_LED3);
    // select_gpio_out_mode(MBED_BASE_LED4);

    // select_gpio_in_mode(MBED_BASE_DIP12);
    // select_gpio_in_mode(MBED_BASE_DIP13);
    // select_gpio_in_mode(MBED_BASE_DIP14);
    // select_gpio_in_mode(MBED_BASE_DIP15);
    // select_gpio_in_mode(MBED_BASE_DIP16);
    
    // clr_pin(MBED_BASE_LED1);
    // clr_pin(MBED_BASE_LED2);
    // clr_pin(MBED_BASE_LED3);
    // clr_pin(MBED_BASE_LED4);
    // //config();
    
    // while(1){
    //     if (read_pin(MBED_BASE_DIP12) == 1){
    //         clr_pin(MBED_BASE_LED1);
    //         clr_pin(MBED_BASE_LED2);
    //         clr_pin(MBED_BASE_LED3);
    //         clr_pin(MBED_BASE_LED4);      
    //     }else if (read_pin(MBED_BASE_DIP13) == 1){
    //         set_pin(MBED_BASE_LED1);
    //     }else if (read_pin(MBED_BASE_DIP14) == 1){
    //         set_pin(MBED_BASE_LED2);
    //     }else if (read_pin(MBED_BASE_DIP15) == 1){
    //         set_pin(MBED_BASE_LED3);
    //     }else if (read_pin(MBED_BASE_DIP16) == 1){
    //         set_pin(MBED_BASE_LED4);
    //     }
    //     wait();
    // }