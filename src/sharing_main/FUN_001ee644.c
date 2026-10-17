/* HSTMATCH module=hstp_trans_main.prx start=0x001ee644 end=0x001ee7f8 symbol=FUN_001ee644 lang=c99 */
/* Clone of src/eboot/FUN_001e0420.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b26f0;
extern void FUN_00000a00();
extern undefined4 * FUN_0001ed28();
extern void FUN_001ef500();
extern int FUN_0022667c();

undefined4 * FUN_001ee644(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b26f0);
    FUN_001ef500();
    FUN_0022667c(param_1 + 0xa0a,0xffffffff);
    FUN_0022667c(param_1 + 0x9e7,0xffffffff);
    FUN_0022667c(param_1 + 0x94b,0xffffffff);
    FUN_0022667c(param_1 + 0x920,0xffffffff);
    FUN_0022667c(param_1 + 0x8b1,0xffffffff);
    FUN_0022667c(param_1 + 0x856,0xffffffff);
    FUN_0022667c(param_1 + 0x833,0xffffffff);
    FUN_0022667c(param_1 + 0x810,0xffffffff);
    FUN_0022667c(param_1 + 0x7ed,0xffffffff);
    FUN_0022667c(param_1 + 0x7ca,0xffffffff);
    FUN_0022667c(param_1 + 0x736,0xffffffff);
    FUN_0022667c(param_1 + 0x713,0xffffffff);
    FUN_0022667c(param_1 + 0x6f0,0xffffffff);
    FUN_0022667c(param_1 + 0x6cd,0xffffffff);
    FUN_0022667c(param_1 + 0x632,0xffffffff);
    FUN_0022667c(param_1 + 0x60f,0xffffffff);
    FUN_0022667c(param_1 + 0x24a,0xffffffff);
    FUN_0022667c(param_1 + 0x227,0xffffffff);
    FUN_0022667c(param_1 + 0x1e1,0xffffffff);
    FUN_0022667c(param_1 + 0x1be,0xffffffff);
    FUN_0022667c(param_1 + 0x19b,0xffffffff);
    FUN_0022667c(param_1 + 0x178,0xffffffff);
    FUN_0022667c(param_1 + 0x155,0xffffffff);
    FUN_0022667c(param_1 + 0x132,0xffffffff);
    FUN_0022667c(param_1 + 0x10f,0xffffffff);
    FUN_0022667c(param_1 + 0xeb,0xffffffff);
    FUN_0022667c(param_1 + 0x5a,0xffffffff);
    FUN_0022667c(param_1 + 0x12,0xffffffff);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
