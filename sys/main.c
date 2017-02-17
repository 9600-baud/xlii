 
#include <types.h>
#include <video.h>
#include <serial.h>

void _main(void);

void _main(void) {
  video_init();
  serial_init(SERIAL_COM1);
  vputs("Hello, World! This is a test message\n to ensure that wrapping is working. We shall see. Anyhow, blah blah blah blah foobar biz baz!");
  sputc(SERIAL_COM1, 'A');
  sputs(SERIAL_COM1, "Hello, World!");
  
  for(;;);
}

