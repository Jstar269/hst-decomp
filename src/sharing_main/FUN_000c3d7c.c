/* HSTMATCH module=hstp_trans_main.prx start=0x000c3d7c end=0x000c3d90 symbol=FUN_000c3d7c lang=c99 */
/* Clone of src/eboot/FUN_000c06dc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


int FUN_000c3d7c(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x18) + 0x10) - *(int *)(*(int *)(param_1 + 0x18) + 0xc);
}
