/* HSTMATCH module=EBOOT.BIN start=0x00003088 end=0x000030a8 symbol=FUN_00003088 lang=c99 */
/* Clone of src/sharing_main/FUN_00003088.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

undefined4 FUN_00003088(void)
{
  int iVar1;
  
  iVar1 = FUN_000030a8();
  return *(undefined4 *)(iVar1 + 8);
}
