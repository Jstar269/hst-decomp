/* HSTMATCH module=EBOOT.BIN start=0x00170344 end=0x0017049c symbol=FUN_00170344 lang=c99 */
/* Clone of src/sharing_main/update_entry_data_0017c590.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-decompiled: inverted if/else, 6-int stack array with 0x7fffffff bounds, struct assignment for 4-short payload, &DAT_0034179c symbol reference; exact match verified. */
#include "hst/types.h"
typedef int code();

extern void FUN_0016fd94(int);
extern void FUN_0017c204(u32);
extern void FUN_0017d590(u32, int *, int, int);
extern void FUN_001b34b4(void *);
extern void *DAT_0034179c;

void FUN_00170344(int param_1, int param_2)
{
  u32 uVar4;
  u32 uVar5;
  int arr[6];

  if (param_2 != 0) {
    short *puVar6;
    *(u8 *)(param_1 + 0x59c) = 0;
    uVar4 = (**(code **)(param_1 + 0x558))();
    uVar5 = (**(code **)(param_1 + 0x558))();
    uVar5 = (**(code **)(param_1 + 0x550))(uVar5);
    puVar6 = (short *)(**(code **)(param_1 + 0x3ec))(uVar4, uVar5);
    struct S4 { short s[4]; };
    *(struct S4 *)puVar6 = *(struct S4 *)(param_1 + 0x59e);
    *(u8 *)((char *)puVar6 + 8) = *(u8 *)(param_1 + 0x5a6);
    *(u8 *)((char *)puVar6 + 9) = *(u8 *)(param_1 + 0x5a7);
    *(u8 *)((char *)puVar6 + 10) = *(u8 *)(param_1 + 0x5a8);
  }
  else {
    u16 *puVar7;
    int i;
    *(u8 *)(param_1 + 0x59c) = 0;
    uVar4 = (**(code **)(param_1 + 0x558))();
    uVar5 = (**(code **)(param_1 + 0x558))();
    uVar5 = (**(code **)(param_1 + 0x550))(uVar5);
    puVar7 = (u16 *)(**(code **)(param_1 + 0x3ec))(uVar4, uVar5);
    for (i = 0; i < 6; i++) {
      arr[i] = 0x7fffffff;
    }
    arr[1] = puVar7[0];
    arr[2] = puVar7[1];
    arr[3] = puVar7[2];
    arr[4] = puVar7[3];
    FUN_0017d590(*(u32 *)(param_1 + 0x178), arr, 0, 0);
  }
  FUN_0016fd94(param_1);
  FUN_001b34b4(&DAT_0034179c);
  FUN_0017c204(*(u32 *)(param_1 + 0x178));
}
