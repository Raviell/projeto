#include "functions.h"

void tecla6() {
    // Frame 1: Desenho do topo do número 6
    uint32_t frame1[5][5] = {
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 0x00000000}
    };
    renderRGBMatrix(frame1);
    sleep_ms(500);

    // Frame 2: Parte superior e linha lateral do 6
    uint32_t frame2[5][5] = {
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0xff0000ff, 0xff0000ff, 0x00000000},
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 0x00000000}
    };
    renderRGBMatrix(frame2);
    sleep_ms(500);

    // Frame 3: Adiciona o arco inferior do número 6
    uint32_t frame3[5][5] = {
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0xff0000ff, 0xff0000ff, 0x00000000},
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff}
    };
    renderRGBMatrix(frame3);
    sleep_ms(500);

    // Frame 4: Adiciona o preenchimento interno do número 6
    uint32_t frame4[5][5] = {
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0xff0000ff, 0xff0000ff, 0x00000000},
        {0xff0000ff, 0x00000000, 0xff0000ff, 0xff0000ff, 0x00000000},
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff}
    };
    renderRGBMatrix(frame4);
    sleep_ms(500);

    // Frame 5: Completa o número 6 com todos os detalhes
    uint32_t frame5[5][5] = {
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0xff0000ff, 0xff0000ff, 0x00000000},
        {0xff0000ff, 0x00000000, 0xff0000ff, 0xff0000ff, 0x00000000},
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff}
    };
    renderRGBMatrix(frame5);
    sleep_ms(500);
}
