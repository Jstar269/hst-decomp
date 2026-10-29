/* HSTMATCH module=EBOOT.BIN start=0x000f6b7c end=0x000f6c48 symbol=FUN_000f6b7c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0001342c();

#define SLOT_COUNT 0x20   /* slots walked */
#define SLOT_STRIDE 0x40  /* bytes between slots */

/* Count down every active slot; on each even count with a positive source value, draw a new random-style value into the slot. */
void FUN_000f6b7c(int self)
{
  u32 index = 0;
  char *entry = (char *)self;
  do {
    if (*(unsigned char *)(entry + 0x30) != 0) {
      int count = *(int *)(entry + 0x60);
      if (count > 0) {
        count = count - 1;
        *(int *)(entry + 0x60) = count;
        if (*(unsigned char *)(entry + 0x30) != 0) {
          float value = *(float *)(*(int *)(*(int *)(self + 0x830) +
                                      *(int *)(entry + 0x34) * 4) + 8);
          if (value > 0.0f) {
            count = *(int *)(entry + 0x60);
            if (count % 2 == 0) {
              *(int *)(entry + 0x68) = FUN_0001342c();
            }
          }
        }
      } else {
        *(unsigned char *)(entry + 0x30) = 0;
      }
    }
    index = index + 1;
    entry = entry + SLOT_STRIDE;
  } while (index < SLOT_COUNT);
}
