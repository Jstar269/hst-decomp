/* HSTMATCH module=EBOOT.BIN start=0x0024b8e8 end=0x0024ba68 symbol=FUN_0024b8e8 lang=c99 */
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

extern undefined DAT_00309910;
extern int ** DAT_0034a768;
extern int DAT_0034a76c;
extern undefined4 DAT_0034a770;
extern int DAT_0034a774;
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern int FUN_00053718();
extern undefined4 * FUN_00056cb0();
extern int * FUN_001466dc();
extern void FUN_0022909c();

undefined4 * FUN_0024b8e8(undefined4 *param_1,short param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_4;
  uint local_8;
  int local_c;
  struct V { undefined1 *data; int size; int cap; } v;
  volatile char pad[16];
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309910);
    DAT_0034a774 = DAT_0034a774 + -1;
    if (DAT_0034a774 < 1) {
      uVar4 = 0;
      if (DAT_0034a76c != 0) {
        do {
          iVar3 = (int)DAT_0034a768[uVar4];
          if (iVar3 != 0) {
            FUN_00053718(iVar3,1);
            DAT_0034a768[uVar4] = 0;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < DAT_0034a76c);
      }
      { int n = DAT_0034a76c; DAT_0034a76c -= n; }
      v.data = 0;
      v.size = 0;
      v.cap = 0;
      FUN_0022909c(&v,DAT_0034a768,DAT_0034a768 + DAT_0034a76c,(int)pad[12]);
      iVar3 = DAT_0034a770;
      DAT_0034a770 = v.cap;
      v.cap = iVar3;
      iVar3 = (int)DAT_0034a768;
      DAT_0034a768 = (int **)v.data;
      v.data = (undefined1 *)iVar3;
      iVar3 = DAT_0034a76c;
      DAT_0034a76c = v.size;
      v.size = iVar3;
      FUN_001466dc(&v,0);
    }
    FUN_00056cb0(param_1 + 0x14,0xffffffff);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss from lane ds1018ar1-0 (unreviewed)
