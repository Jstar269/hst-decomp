/* HSTMATCH module=EBOOT.BIN start=0x0004d2d4 end=0x0004d320 symbol=FUN_0004d2d4 lang=c99 */
/* Clone of src/sharing_main/FUN_0004d5f8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002bc410;
extern undefined4 * FUN_00022570();
extern undefined4 * FUN_0002260c();

void FUN_0004d2d4(undefined4 param_1,undefined4 param_2)
{
  undefined1 auStack_40 [64];
  
  FUN_0002260c(auStack_40,&DAT_002bc410);
  FUN_00022570(param_1,param_2,auStack_40);
  return;
}
