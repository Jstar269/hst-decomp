/* HSTMATCH module=EBOOT.BIN start=0x000baaa4 end=0x000baac8 symbol=FUN_000baaa4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64d); exact match verified; names and types await human review. */
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

extern int FUN_002b7ef8();

bool FUN_000baaa4(void)
{
  int iVar1;
  
  iVar1 = FUN_002b7ef8();
  return iVar1 == 1;
}
