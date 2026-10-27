/* HSTMATCH module=hstp_trans_main.prx start=0x0017cef0 end=0x0017d068 symbol=FUN_0017cef0 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/copy_profile_defaults_00170c24.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
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
extern Root *DAT_003e1a08;
extern char DAT_003eab08;
extern BytePair DAT_003eaba4;
extern unsigned char DAT_003eaba6;
extern unsigned char DAT_003eaba7;
extern signed char DAT_003eaba8;
extern Vec4 DAT_003eabac;
extern float DAT_003eabbc;
extern int DAT_003eabc0;
extern short DAT_003eabc4[];
extern void FUN_00099c98();
extern void FUN_001cf8c4();
void FUN_0017cef0(int param_1, int param_2)
{
  undefined4 uVar4;
  undefined4 uVar5;
  uVar4 = (**(code **)(param_1 + 0x540))();
  uVar5 = (**(code **)(param_1 + 0x540))();
  uVar5 = (**(code **)(param_1 + 1000))(uVar5);
  FUN_001cf8c4(0, uVar4, uVar5, 0, *(undefined4 *)(param_1 + 0x8c), 0);
  if (DAT_003e1a08 != 0) {
    int iVar6 = (int)DAT_003e1a08->child;
    DataRecord *dst = (DataRecord *)(iVar6 + 0x528);
    FUN_00099c98(dst, &DAT_003eab08);
    dst->bytes = DAT_003eaba4;
    dst->b9e = DAT_003eaba6;
    dst->b9f = DAT_003eaba7;
    dst->ba0 = DAT_003eaba8;
    dst->floats = DAT_003eabac;
    dst->f_b4 = DAT_003eabbc;
    dst->i_b8 = DAT_003eabc0;
    {
      ShortPair *src = (ShortPair *)DAT_003eabc4;
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
      int *obj = (int *)DAT_003e1a08->child;
      if (((unsigned char *)obj)[1] != 0)
        *(int *)((char *)obj + 0x61c) = 0;
    }
  }
}
