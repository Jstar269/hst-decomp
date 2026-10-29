/* HSTMATCH module=EBOOT.BIN start=0x000c7894 end=0x000c7928 symbol=FUN_000c7894 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_003386cc;
extern u8 DAT_00338b04;
extern void FUN_0005c780(int, float *);
extern void FUN_0005c810(int, int, float *);

/* When the flag is set, set two RGBA colours (alpha 1.0) on the model handle. */
void FUN_000c7894(void)
{
  float color_a[4];
  float color_b[4];

  if (DAT_00338b04 != 0) {
    color_a[0] = 1.0f;
    color_a[3] = 1.0f;
    color_a[1] = 0.55f;
    color_a[2] = 0.75f;
    FUN_0005c780(DAT_003386cc, color_a);
    color_b[0] = 0.4f;
    color_b[1] = 0.2f;
    color_b[2] = 0.3f;
    color_b[3] = 1.0f;
    FUN_0005c810(DAT_003386cc, 0, color_b);
  }
}
