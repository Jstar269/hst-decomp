/* HSTMATCH module=hstp_trans_main.prx start=0x001236c0 end=0x0012376c symbol=FUN_001236c0 lang=c99 */
/* Clone of src/eboot/FUN_001184ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b12c8;
extern undefined4 DAT_003e47a0;
extern void FUN_00000a00();
extern undefined4 * FUN_0001ed28();
extern void FUN_00123a9c();
extern void FUN_001244f0();
extern int FUN_00127df0();
extern int FUN_001281a0();

undefined4 * FUN_001236c0(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b12c8);
    DAT_003e47a0 = 0;
    FUN_001244f0();
    FUN_00123a9c(param_1);
    puVar1 = param_1 + 0xbe;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_001281a0(puVar1,0);
    }
    puVar1 = param_1 + 0xb8;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_00127df0(puVar1,0);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
