#include "platform.h"
#include "lolevel.h"
#include "sd1200_debug.h"

void vid_bitmap_refresh()
{
    _ScreenLock();
    _RefreshPhysicalScreen(1);
}

void shutdown()
{
    volatile long *p = (void*)0xc022001C; // from task_by (not really complete)

    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");

    *p = 0x44;

    while(1);
}

int get_flash_params_count(void){
 return 0x7a;   // Found @0xffd1c038
}


// from  Microfunguy in
// http://chdk.setepontos.com/index.php/topic,4324.msg55475.html#msg55475
void camera_set_led(int led, int state, int bright)
{
   int leds[] = {0x134,0x138,0x134,0x130,0x134,0x3030,0x3030};  //  green=4 | (yellow) | (not used) | orange | (not used) | af beam | timer
   volatile long *p=(void*)0xc0220000 + leds[(led-4)%sizeof(leds)];
   if (state)
      p[0]=0x46;
   else
      p[0]=0x44;
}

#define DEBUG_LED LED_IO_Y
void debug_led(int state)
{
    * (int *) DEBUG_LED = state ? 0x46 : 0x44;
}

int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }  //Found @ 0xffcadeb0 fw 100b

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x49d4+0x14)); // "Add: %p Width : %ld Hight : %ld", sub_ffcadf5c
}


void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern int** palette_buffer_ptr;
    return (palette_buffer_ptr[active_palette_buffer]+16);
}
