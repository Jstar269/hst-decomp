/* HSTMATCH module=EBOOT.BIN start=0x00170c24 end=0x00170d9c symbol=FUN_00170c24 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct BytePair { unsigned char first, second; } BytePair;
typedef struct ShortPair { short first, second; } ShortPair;
typedef struct Root { char pad[0x40]; void *child; } Root;
typedef struct DataRecord {
  char pad0[0x9c];
  BytePair bytes;
  unsigned char b9e, b9f;
  signed char ba0;
  char pad1[3];
  Vec4 floats;
  float f_b4;
  int i_b8;
  short shorts[6];
} DataRecord;
typedef struct State { char pad[1]; unsigned char byte1; } State;
extern Root *DAT_003386c8;
extern char DAT_003417d0;
extern BytePair DAT_0034186c;
extern unsigned char DAT_0034186e;
extern unsigned char DAT_0034186f;
extern signed char DAT_00341870;
extern Vec4 DAT_00341874;
extern float DAT_00341884;
extern int DAT_00341888;
extern short DAT_0034188c[];
extern void FUN_00097b2c();
extern void FUN_001c16b0();
void FUN_00170c24(int param_1, int param_2)
{
  u32 uVar4;
  u32 uVar5;
  uVar4 = (**(code **)(param_1 + 0x540))();
  uVar5 = (**(code **)(param_1 + 0x540))();
  uVar5 = (**(code **)(param_1 + 1000))(uVar5);
  FUN_001c16b0(0, uVar4, uVar5, 0, *(u32 *)(param_1 + 0x8c), 0);
  if (DAT_003386c8 != 0) {
    int iVar6 = (int)DAT_003386c8->child;
    DataRecord *dst = (DataRecord *)(iVar6 + 0x528);
    FUN_00097b2c(dst, &DAT_003417d0);
    dst->bytes = DAT_0034186c;
    dst->b9e = DAT_0034186e;
    dst->b9f = DAT_0034186f;
    dst->ba0 = DAT_00341870;
    dst->floats = DAT_00341874;
    dst->f_b4 = DAT_00341884;
    dst->i_b8 = DAT_00341888;
    {
      ShortPair *src = (ShortPair *)DAT_0034188c;
      ShortPair *out = (ShortPair *)dst->shorts;
      int count = 3;
      do {
        ShortPair pair = *src;
        --count;
        *out = pair;
        ++src;
        ++out;
      } while (count > 0);
    }
    if (param_2 != 0) {
      int *obj = (int *)DAT_003386c8->child;
      if (((unsigned char *)obj)[1] != 0)
        *(int *)((char *)obj + 0x61c) = 0;
    }
  }
}
