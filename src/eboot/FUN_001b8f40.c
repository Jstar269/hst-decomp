/* HSTMATCH module=EBOOT.BIN start=0x001b8f40 end=0x001b8f94 symbol=FUN_001b8f40 lang=c99 */
/* Clone of src/sharing_main/FUN_001c6c2c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0034179c;
extern char DAT_002e99c3[];
extern void FUN_00000020();
extern void FUN_00000028();
extern void FUN_001b3a0c();

void FUN_001b8f40(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_00000020(DAT_002e99c3 + 1);
  FUN_001b3a0c((int)&DAT_0034179c,param_2,param_3);
  FUN_00000028();
  return;
}
