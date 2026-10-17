/* HSTMATCH module=EBOOT.BIN start=0x00111010 end=0x00111044 symbol=FUN_00111010 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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

extern undefined4 DAT_0034176c;
extern void FUN_001031e8();

void FUN_00111010(void)
{
  *(undefined1 *)(DAT_0034176c + 0x88) = 1;
  FUN_001031e8();
  *(undefined1 *)(DAT_0034176c + 0x88) = 0;
  return;
}
