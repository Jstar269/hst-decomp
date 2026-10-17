/* HSTMATCH module=EBOOT.BIN start=0x000fbed0 end=0x000fbee4 symbol=FUN_000fbed0 lang=c99 */
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


void FUN_000fbed0(int param_1,int param_2)
{
  *(char *)(param_1 + 0x58) = (char)param_2;
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  return;
}
