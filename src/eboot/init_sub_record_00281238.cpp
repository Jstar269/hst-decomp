/* HSTMATCH module=EBOOT.BIN start=0x00281238 end=0x0028144c symbol=FUN_00281238 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ mode, non-POD struct memberwise copy assignment for 16-byte buffer, and 64-bit integer copy at tail; exact match verified; names and types await human review. */

#include "hst/types.h"

extern "C" void *DAT_003415a8;
extern "C" u32 *FUN_000114c0(void *, int, int);

struct Array16 {
  char data[16];
  Array16() {}
};

extern "C" void FUN_00281238(int *param_1)
{
  u32 uVar4;
  int *puVar6;
  char *p;
  
  uVar4 = 0;
  puVar6 = param_1;
  do {
    uVar4 = uVar4 + 1;
    *puVar6 = -1;
    puVar6 = puVar6 + 1;
  } while (uVar4 < 4);
  param_1[4] = -1;
  *(char *)(param_1 + 5) = 0;
  FUN_000114c0(param_1 + 6, 0, 0x1c);
  param_1[8] = 1;
  
  p = (char *)param_1;
  p[264] = 0;
  p[267] = 0;
  p[265] = 0;
  p[301] = 0;
  p[302] = 0;
  p[303] = 0;
  p[304] = 0;
  param_1[0x4d] = -1;
  param_1[0x4e] = -1;
  param_1[0x4f] = 0x40a00000;
  p[320] = 10;
  p[321] = 0;
  param_1[0x51] = 0;

  p[0x10c] = -29;
  p[0x10d] = -127;
  p[0x10e] = -65;
  p[0x10f] = -29;
  p[0x110] = -126;
  p[0x111] = -109;
  p[0x112] = -29;
  p[0x113] = -125;
  p[0x114] = -122;
  p[0x115] = -29;
  p[0x116] = -125;
  p[0x117] = -117;
  p[0x118] = 80;
  p[0x10c] = 0;

  p[552] = 0;
  p[555] = 0;
  p[553] = 0;
  p[589] = 0;
  p[590] = 0;
  p[591] = 0;
  p[592] = 0;
  param_1[0x95] = -1;
  param_1[0x96] = -1;
  param_1[0x97] = 0x40a00000;
  p[608] = 10;
  p[609] = 0;
  param_1[0x99] = 0;

  p[0x22c] = -29;
  p[0x22d] = -127;
  p[0x22e] = -65;
  p[0x22f] = -29;
  p[0x230] = -126;
  p[0x231] = -109;
  p[0x232] = -29;
  p[0x233] = -125;
  p[0x234] = -122;
  p[0x235] = -29;
  p[0x236] = -125;
  p[0x237] = -117;
  p[0x238] = 80;

  p[840] = 0;
  p[843] = 0;
  p[841] = 0;
  p[877] = 0;
  p[878] = 0;
  p[879] = 0;
  p[880] = 0;
  param_1[0xdd] = -1;
  param_1[0xde] = -1;
  param_1[0xdf] = 0x40a00000;
  p[896] = 10;
  p[897] = 0;
  param_1[0xe1] = 0;

  p[0x34c] = -29;
  p[0x34d] = -127;
  p[0x34e] = -65;
  p[0x34f] = -29;
  p[0x350] = -126;
  p[0x351] = -109;
  p[0x352] = -29;
  p[0x353] = -125;
  p[0x354] = -122;
  p[0x355] = -29;
  p[0x356] = -125;
  p[0x357] = -117;
  p[0x358] = 80;

  p[0x22c] = 0;
  p[0x34c] = 0;

  char *src = (char *)DAT_003415a8;
  *(Array16 *)(p + 328) = *(Array16 *)(src + 4);
  *(long long *)(p + 344) = *(long long *)(src + 24);
}
