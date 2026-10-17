/* HSTMATCH module=EBOOT.BIN start=0x00261bbc end=0x00261c24 symbol=FUN_00261bbc lang=c99 */
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

extern void FUN_000ffc70();

void FUN_00261bbc(int param_1,int param_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + param_2 * 0xf0);
  FUN_000ffc70(*puVar1,0x80808080);
  FUN_000ffc70(puVar1[3],0x80808080);
  FUN_000ffc70(puVar1[4],puVar1[6]);
  FUN_000ffc70(puVar1[5],0x80808080);
  return;
}
