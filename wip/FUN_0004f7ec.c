/* HSTMATCH module=hstp_trans_main.prx start=0x0004f7ec end=0x0004f864 symbol=FUN_0004f7ec lang=c99 */
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

extern undefined DAT_0001a0a8;
extern undefined DAT_003d4570;
extern void FUN_00000a00();
extern void FUN_00050c4c();
extern int * FUN_000517e8();

int FUN_0004f7ec(int param_1,short param_2)
{
  undefined *puVar1;
  
  if (param_1 != 0) {
    DAT_003d4570 = 0;
    FUN_00050c4c();
    puVar1 = (undefined *)(0x0001a0a8 + param_1);
    if ((puVar1 != (undefined *)0x0) && (puVar1 != (undefined *)0x0)) {
      FUN_000517e8(puVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

// NEAR MISS: 3 words differ at +0x28..+0x30; the address constant is materialized in v0 instead of the retail at register.
// near miss from lane u1r2-0 (unreviewed)
