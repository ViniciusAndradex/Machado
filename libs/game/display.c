#include "pico/stdlib.h"
#include "libs/ssd1306/ssd1306.h"
#include "modules/display.h"
#include "modules/globals.h"
#include "stdio.h"
#include <string.h>

void setup_i2c(int s) {
  gpio_set_function(s, GPIO_FUNC_I2C); 
  gpio_pull_up(s);
}

void print_layout(char *linha1, char *linha2, char *linha3) {
    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, sizeof(ssd));

    struct render_area frame_area = {
        .start_column = 0,
        .end_column = ssd1306_width - 1,
        .start_page = 0,
        .end_page = ssd1306_n_pages - 1
    };

    calculate_render_area_buffer_length(&frame_area);

    // Calcula a posição inicial do primeiro texto para centralizar verticalmente
    int total_height = 3 * 8 + 8; // 3 linhas de texto (8px cada) + 8px de espaçamento
    int start_y = (ssd1306_height - total_height) / 2;

    // Desenha os textos centralizados
    ssd1306_draw_string(ssd, 0, start_y, linha1);
    ssd1306_draw_string(ssd, 0, start_y + 16, linha2); // Pulando uma linha (8px) entre
    ssd1306_draw_string(ssd, 0, start_y + 24, linha3);

    render_on_display(ssd, &frame_area);
}


void print_result(char *linha1, char *linha2) {
    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, sizeof(ssd));

    struct render_area frame_area = {
        .start_column = 0,
        .end_column = ssd1306_width - 1,
        .start_page = 0,
        .end_page = ssd1306_n_pages - 1
    };

    calculate_render_area_buffer_length(&frame_area);

    // Calcula o centro do eixo Y
    int centerY = ssd1306_height / 2;
    int y1, y2;

    // Define a posição Y centralizada
    y1 = centerY - 4;  // Ajuste para centralizar no eixo Y
    y2 = y1 - 16;      // Aumenta o espaçamento para garantir que as linhas não fiquem muito próximas

    // Desenha as duas linhas de texto
    ssd1306_draw_string(ssd, 0, y2, linha1); // Linha acima
    ssd1306_draw_string(ssd, 0, y1, linha2); // Linha principal
    render_on_display(ssd, &frame_area);
}


void game_template(int num1, int num2, int num3) {
    char linha[64];
    
    snprintf(linha, sizeof(linha), " %d\t ||\t\tX\t\t||  X\t\t", num1);
    print_result("  MACHADO BET", linha);
    sleep_ms(2000);  

    snprintf(linha, sizeof(linha), " %d\t ||\t\t%d\t\t||  X\t\t", num1, num2);
    print_result("  MACHADO BET", linha);
    sleep_ms(2000);  
        
    snprintf(linha, sizeof(linha), " %d\t ||\t\t%d\t\t||  %d\t\t", num1, num2, num3);
    print_result("  MACHADO BET", linha);
}