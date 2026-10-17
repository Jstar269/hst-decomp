/* HSTMATCH module=EBOOT.BIN start=0x0004ad98 end=0x0004ae08 symbol=FUN_0004ad98 lang=c99 */
/* Clone of src/sharing_main/FUN_0004af74.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0004ae58();
extern undefined4 FUN_0004ae68();

undefined4 FUN_0004ad98(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5)
{
  FUN_0004ae58(param_1);
  FUN_0004ae68(param_1,param_2,param_3,param_4,param_5);
  return param_1;
}
