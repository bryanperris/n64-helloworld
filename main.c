#include <stdio.h>
#include <libdragon.h>

int main(void)
{
   init_interrupts();
   display_init(RESOLUTION_320x240, DEPTH_32_BPP, 1, GAMMA_NONE, ANTIALIAS_OFF);
   console_init();
   console_set_render_mode(RENDER_MANUAL);
   console_clear();
   printf("Hello, World!");
   console_render();
}
