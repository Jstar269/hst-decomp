/* HSTMATCH module=hstp_trans_main.prx start=0x00120a94 end=0x00120ac8 symbol=FUN_00120a94 lang=c99 */
/* Clone of src/eboot/FUN_00115b78.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001079b4();

void FUN_00120a94(int param_1,undefined2 param_2)
{
  FUN_001079b4();
  *(undefined2 *)(param_1 + 0x908) = param_2;
  return;
}
