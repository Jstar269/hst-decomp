/* HSTMATCH module=EBOOT.BIN start=0x00286c6c end=0x00286cb8 symbol=FUN_00286c6c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined4 * FUN_0014c794();
extern int FUN_0014c820();
extern undefined4 * FUN_0014c914();

void FUN_00286c6c(int param_1)
{
  undefined1 auStack_24 [36];
  
  FUN_0014c794(auStack_24,0,0,0);
  FUN_0014c914(*(undefined4 *)(param_1 + 8),auStack_24);
  FUN_0014c820(auStack_24,0xffffffff);
  return;
}
