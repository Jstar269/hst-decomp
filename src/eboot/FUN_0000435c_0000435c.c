/* HSTMATCH module=EBOOT.BIN start=0x0000435c end=0x000043b4 symbol=FUN_0000435c lang=c99 */
/* Clone of src/sharing_main/FUN_0000435c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern uint FUN_00003100();
extern void FUN_00003de8();

void FUN_0000435c(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  
  uVar1 = FUN_00003100(param_1);
  FUN_00003de8(param_1,0,uVar1,param_2,param_3,0);
  return;
}
