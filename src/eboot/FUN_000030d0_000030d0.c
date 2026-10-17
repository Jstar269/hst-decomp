/* HSTMATCH module=EBOOT.BIN start=0x000030d0 end=0x000030f8 symbol=FUN_000030d0 lang=c99 */
/* Clone of src/sharing_main/FUN_000030d0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_000030a8();

bool FUN_000030d0(void)
{
  uint *puVar1;
  
  puVar1 = (uint *)FUN_000030a8();
  return (*puVar1 & 1) != 0;
}
