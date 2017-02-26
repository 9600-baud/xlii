 
#include "serial.h"
#include <strutil.h>

extern unsigned char _binary_bootrd_img_start;

void _main(void);

void _main(void) {
  serial_init(SERIAL_COM1);
  sputs(SERIAL_COM1, "-- system start --\n");
  unsigned char *foo = &_binary_bootrd_img_start;

  char *num;
  itoa(255, num, 16);

  sputs(SERIAL_COM1, "0x");
  sputs(SERIAL_COM1, num);
  for(;;);
}

