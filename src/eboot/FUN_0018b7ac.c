/* HSTMATCH module=EBOOT.BIN start=0x0018b7ac end=0x0018b804 symbol=FUN_0018b7ac lang=c99 */
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

extern undefined4 DAT_0034152c;
extern int FUN_00000bcc();
extern undefined4 * FUN_0018b944();

void FUN_0018b7ac(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  if ((DAT_0034152c == 0) && (iVar1 = FUN_00000bcc(0x90), iVar1 != 0)) {
    FUN_0018b944(iVar1,param_1,param_2);
  }
  return;
}
