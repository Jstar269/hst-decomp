/* HSTMATCH module=EBOOT.BIN start=0x0011b634 end=0x0011b7f0 symbol=FUN_0011b634 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_00307fc4;
extern unsigned char DAT_0033b488;
extern undefined4 DAT_0033b48c;
extern undefined4 * FUN_0001f06c();
extern void FUN_0001f1fc();
extern void FUN_0001f21c();
extern undefined4 * FUN_0005a8ec();
extern void FUN_0011cd48();

undefined4 * FUN_0011b634(undefined4 *param_1,int param_2)
{
  undefined4 *puVar1;
  uint *puVar2;
  
  FUN_0001f06c(param_1);
  *param_1 = (unsigned int)(&DAT_00307fc4);
  param_1[0xf] = param_2;
  FUN_0005a8ec(param_1 + 0x10);
  *(undefined1 *)(param_1 + 0x32) = 0;
  FUN_0001f21c(param_2,(int)param_1);
  DAT_0033b488 = 1;
  DAT_0033b48c = (unsigned int)(param_1);
  param_1[0x33] = 0;
  puVar2 = (uint *)(param_2 + 0x2f8);
  if (puVar2[5] == 0) {
    FUN_0001f1fc((int)param_1,0);
    DAT_0033b488 = 0;
  }
  else {
    puVar1 = (undefined4 *)
             (*(int *)(puVar2[3] + ((puVar2[2] + puVar2[4] / 0x2a) % puVar2[0]) * 4) +
              (puVar2[4] % 0x2a) * 0xc);
    param_1[0x2c] = *puVar1;
    param_1[0x2d] = puVar1[1];
    *(float *)(param_1 + 0x2e) = *(float *)(puVar1 + 2);
    FUN_0011cd48((int)puVar2);
    if (puVar2[5] == 0) {
      param_1[0x30] = 0;
    }
    else {
      puVar1 = (undefined4 *)
               (*(int *)(puVar2[3] + ((puVar2[2] + puVar2[4] / 0x2a) % puVar2[0]) * 4) +
                (puVar2[4] % 0x2a) * 0xc);
      param_1[0x2f] = *puVar1;
      param_1[0x30] = puVar1[1];
      *(float *)(param_1 + 0x31) = *(float *)(puVar1 + 2);
      FUN_0011cd48((int)puVar2);
    }
    param_1[0x33] = 0x2d;
  }
  return param_1;
}
// near miss: 112/111 words, 52 differ, first at +0x7c. Retail opens the index expression with
// `lw a1,8(s0); lw v1,0(s0)` (the struct fields loaded in source order into a1/v1) and does the
// `% 0x2a` with `divu zero,t1,t0` + `mfhi`, while our draft keeps the quotient sequence in v0/v1 and
// adds one extra `b` at 0x11b6b0. Fixed for real along the way: DAT_0033b488 is a BYTE (retail
// `sb v1`/`sb zero`, our `undefined4` gave `sw`), the +0x2f8 block is best reached through one
// pointer (`puVar2[0..5]` for +0x2f8/+0x300/+0x304/+0x308/+0x30c) instead of param_2 offsets, and
// the record's third word is a FLOAT (`lwc1 $f0,8(v1); swc1 $f0,..`) not an int.
// near miss from lane fm9 (unreviewed)
