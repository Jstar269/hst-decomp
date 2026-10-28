/* HSTMATCH module=EBOOT.BIN start=0x0015d960 end=0x0015dbbc symbol=FUN_0015d960 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002dcc1c;
extern u8 * DAT_00331b84;
extern u8 * DAT_003403f8;
extern u32 DAT_003415d4;
extern u8 DAT_0034a678;
extern u8 * DAT_0034a820;
extern u8 DAT_0034179c;
extern void FUN_00047864();
extern void FUN_0006391c(float, void *, int);
extern void FUN_0015a118();
extern void FUN_001905b8();
extern int FUN_00190724();
extern void FUN_001b3ea4(float, void *);
extern void FUN_00234158();
extern void FUN_002930c8(float, void *, int);

typedef struct Object {
  char pad0[0x3c];
  int state;
  int timer;
  char pad1[4];
  unsigned char flag;
  char pad2[9];
  unsigned char unk52;
} Object;

void FUN_0015d960(Object *param_1)
{
  int iVar1;
  
  FUN_0015a118(DAT_003403f8);
  if (*(int *)(DAT_003403f8 + 0x14) == 8) {
    iVar1 = param_1->state;
    switch (iVar1) {
    case 0:
    case 1:
    case 2:
      FUN_00047864();
      break;
    case 3:
      FUN_00234158(&DAT_0034a678,0x20);
      break;
    case 4:
      param_1->flag = 0;
      if (param_1->flag != 0) {
        FUN_002930c8(65534.0f,DAT_0034a820,0);
      }
      else {
        FUN_0006391c(65534.0f,DAT_00331b84,0xf);
      }
      FUN_001b3ea4(0.5f,&DAT_0034179c);
      *(u32 *)(DAT_003403f8 + 0x14) = 4;
      break;
    }
  }
  iVar1 = param_1->timer;
  if (iVar1 > 0) {
    param_1->timer = iVar1 + -1;
    if (iVar1 + -1 <= 0) {
      switch (param_1->state) {
      case 4:
        *(u32 *)(DAT_003403f8 + 0x14) = 8;
        FUN_00234158(&DAT_0034a678,DAT_002dcc1c);
        iVar1 = (int)(DAT_00331b84);
        *(u32 *)(DAT_00331b84 + 0xc) = 0;
        *(u8 *)(iVar1 + 0x52) = 0;
        break;
      }
    }
  }
  else if ((*(int *)(DAT_003403f8 + 0x14) == 3) && (iVar1 = FUN_00190724(DAT_003415d4), iVar1 != 0)) {
    param_1->timer = 5;
  }
  if (*(int *)(DAT_003403f8 + 0x14) == 5) {
    FUN_001905b8(DAT_003415d4,3);
    *(u32 *)(DAT_003403f8 + 0x14) = 3;
  }
  if (*(int *)(DAT_003403f8 + 0x14) == 4) {
    if (param_1->flag != 0) {
      if (*(float *)(DAT_0034a820 + 8) == 0.0f) {
        *(u32 *)(DAT_003403f8 + 0x14) = 5;
      }
    } else if (*(float *)(DAT_00331b84 + 0xc) == 0.0f) {
      *(u32 *)(DAT_003403f8 + 0x14) = 5;
    }
  }
}
