#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"
#include "Projeto-matriz-contagem.pio.h"

#define LED_PIN_RED 13
#define NUM_PIXELS 25
#define LED_PIN 7
#define BOTAO_A 5
#define BOTAO_B 6

int static volatile indice = 0;
uint count = 0;
uint actual_time = 0;
uint valor_led;
uint sm;
PIO pio = pio0;

void piscar_led(){
  gpio_put(LED_PIN_RED, true);
  sleep_ms(25);
  gpio_put(LED_PIN_RED, false);
  sleep_ms(175);
}

uint matrix_rgb(float r, float g, float b){
  unsigned char R, G, B;
  R = r * 255;
  G = g * 255;
  B = b * 255;
  return (G << 24) | (R << 16) | (B << 8);
}

int getIndex(int x, int y){
  if (y % 2 == 0){
    return 24 - (y * 5 + x);
  }else{
    return 24 - (y * 5 + (4 - x));
  }
}

void new_index(){
  if (indice > 10){
    indice = 0;
  }else if(indice < 0){
    indice = 10;
  }
}

void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b){
  for (int16_t i = 0; i < NUM_PIXELS; i++)
  {
    valor_led = matrix_rgb(desenho[i] * r, desenho[i] * g, desenho[i] * b);
    pio_sm_put_blocking(pio, sm, valor_led);
  };
}

double apagar_leds[25] ={
              0.0, 0.0, 0.0, 0.0, 0.0,          
              0.0, 0.0, 0.0, 0.0, 0.0, 
              0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0};

double numero0[25] = {
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 1.0, 0.0, 0.0, 1.0,
            1.0, 0.0, 1.0, 0.0, 1.0,
            1.0, 0.0, 0.0, 1.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0};
        
double numero1[25] = {
            0.0, 1.0, 1.0, 1.0, 0.0,
            0.0, 0.0, 1.0, 0.0, 0.0,
            0.0, 0.0, 1.0, 0.0, 0.0,
            0.0, 1.0, 1.0, 0.0, 0.0,
            0.0, 0.0, 1.0, 0.0, 0.0};
          
double numero2[25] = {
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 0.0,
            1.0, 1.0, 1.0, 1.0, 1.0,
            0.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0};
        
double numero3[25] = {
            1.0, 1.0, 1.0, 1.0, 1.0,
            0.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0,
            0.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0};

double numero4[25] = {
            1.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 1.0};
          
double numero5[25] = {
            1.0, 1.0, 1.0, 1.0, 1.0,
            0.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 0.0,
            1.0, 1.0, 1.0, 1.0, 1.0};

double numero6[25] = {
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 0.0,
            1.0, 1.0, 1.0, 1.0, 1.0};

double numero7[25] = {
            1.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0};

double numero8[25] = {
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0};

double numero9[25] = {
            1.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 1.0, 1.0};

double *numeros[11] = {apagar_leds, numero0, numero1, numero2, numero3, numero4, numero5, numero6, numero7, numero8, numero9};

void callback_button(uint gpio, uint32_t events) {
    uint time = to_ms_since_boot(get_absolute_time());
    if (time - actual_time > 250) {
        actual_time = time;
        if (gpio == BOTAO_A) {
            indice++;
            new_index();
            desenho_pio(numeros[indice], valor_led, pio, sm, 1.0, 0.5, 0.0); // Alterado para laranja
            count++;
        } else if (gpio == BOTAO_B) {
            indice--;
            new_index();
            desenho_pio(numeros[indice], valor_led, pio, sm, 1.0, 0.5, 0.0); // Alterado para laranja
            count++;
        }
    }
}
        
int main() {
  bool frequenciaClock;
  uint16_t i;
  float r, g, b;
  pio = pio0;
  uint32_t valor_led = 0;

  frequenciaClock = set_sys_clock_khz(128000, false);
  stdio_init_all();
  gpio_init(LED_PIN);
  gpio_init(LED_PIN_RED);
  gpio_init(BOTAO_A);
  gpio_init(BOTAO_B);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  gpio_set_dir(LED_PIN_RED, GPIO_OUT);
  gpio_set_dir(BOTAO_A, GPIO_IN);
  gpio_set_dir(BOTAO_B, GPIO_IN);
  gpio_pull_up(BOTAO_A);
  gpio_pull_up(BOTAO_B);

  printf("iniciando a transmissão PIO");
  if (frequenciaClock){
    printf("clock set to %ld\n", clock_get_hz(clk_sys));
  }else if(!frequenciaClock){
    printf("erro ao configurar a frequencia do clock");
  }
  uint offset = pio_add_program(pio, &pio_matrix_program);
  sm = pio_claim_unused_sm(pio, true);
  pio_matrix_program_init(pio, sm, offset, LED_PIN);
    
  desenho_pio(apagar_leds, valor_led, pio, sm, r, g, b);

  gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &callback_button);
  gpio_set_irq_enabled_with_callback(BOTAO_B, GPIO_IRQ_EDGE_FALL, true, &callback_button);

  while (1) {
    piscar_led();
  }
  return 0;
}
