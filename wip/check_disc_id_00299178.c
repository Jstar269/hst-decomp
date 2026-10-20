/* HSTMATCH module=EBOOT.BIN start=0x00299178 end=0x0029928c symbol=FUN_00299178 lang=c99 */
// NEAR MISS (70/69 words, 68 differ, first at +0x4): mechanically generated candidate, measured as
// received. Retail's shape is a two-stage API wrapper: default result 0x800001fe in t2 (reloaded in the
// early-out delay slot), one FUN_002b7710 query into a 4-byte stack slot, `!local` as xori+sltiu giving
// the 0x80020321/result selection through movn, then the second stage guarded by that selection and a
// FUN_002b7a10(0) call, ending with the 0x8001000d special case and a second query. Everything differs
// in register colouring (t2/t3/t1 for the status words, s0 for the name pointer); no source-level
// change was attempted in this session.
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

extern undefined DAT_002cb3d0;
extern char DAT_002cb3c8[];
extern int FUN_0029928c();
extern int FUN_002b7710();
extern void FUN_002b79f8();
extern int FUN_002b7a10();

uint FUN_00299178(char *param_1)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int local_1c [3];
  int local_20;
  
  uVar3 = 0x800001fe;
  if ((param_1 != (char *)0x0) && (uVar3 = 0x800001fe, *param_1 != '\0')) {
    uVar1 = FUN_002b7710(DAT_002cb3c8,0x2425823,0,0,&local_20,4);
    if (-1 < (int)uVar1) {
      uVar1 = (uint)(local_20 == 1);
    }
    uVar3 = 0x80020321;
    if (uVar1 != 0) {
      uVar3 = uVar1;
    }
    if ((uVar1 == 1) && (uVar3 = FUN_002b7a10(0), uVar3 == 0)) {
      uVar3 = FUN_0029928c(param_1);
      FUN_002b79f8(0);
      if (uVar3 == 0x8001000d) {
        iVar2 = FUN_002b7710(&DAT_002cb3d0,0x2425824,0,0,local_1c,4);
        if (iVar2 < 0) {
          local_1c[0] = iVar2;
        }
        if (local_1c[0] == 1) {
          uVar3 = 0xffffffff;
        }
      }
    }
  }
  return uVar3;
}
// near miss from lane ds1 (unreviewed)
