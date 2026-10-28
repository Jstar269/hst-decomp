/* HSTMATCH module=hstp_trans_main.prx start=0x000fc270 end=0x000fc33c symbol=FUN_000fc270 lang=c99 */
/* Clone of src/eboot/FUN_000f6b7c_000f6b7c.c (hstclone.py tag u3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0001342c();

void FUN_000fc270(int param_1)
{
  u32 index = 0;
  char *entry = (char *)param_1;
  do {
    if (*(unsigned char *)(entry + 0x30) != 0) {
      int count = *(int *)(entry + 0x60);
      if (count > 0) {
        count = count - 1;
        *(int *)(entry + 0x60) = count;
        if (*(unsigned char *)(entry + 0x30) != 0) {
          float value = *(float *)(*(int *)(*(int *)(param_1 + 0x830) +
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
    entry = entry + 0x40;
  } while (index < 0x20);
}
