/* HSTMATCH module=EBOOT.BIN start=0x001ca8f0 end=0x001ca92c symbol=FUN_001ca8f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern undefined4 * FUN_001ca92c();
extern uint * FUN_0022a744();
extern int FUN_0022a930();

void FUN_001ca8f0(void)
{
  char *iVar1;
  uint *puVar2;
  uint auStack_1250 [1172];
  
  iVar1 = (char *)(FUN_0022a930());
  puVar2 = FUN_0022a744(auStack_1250);
  FUN_001ca92c((undefined4 *)(iVar1 + 0xa210),puVar2);
  return;
}
