#include <stdio.h>
#include <libdragon.h>

int main(void)
{
   init_interrupts();
   console_init();
   console_set_render_mode(RENDER_MANUAL);
   console_clear();
   printf("Hello, World!\n");
   console_render();
}
