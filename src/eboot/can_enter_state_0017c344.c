/* HSTMATCH module=EBOOT.BIN start=0x0017c344 end=0x0017c39c symbol=FUN_0017c344 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: corrected the helper return type and short-circuit returns; exact match verified; names and types await human review. */
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

extern undefined4 FUN_001fe848();
extern int FUN_001fe974();

int FUN_0017c344(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001fe974(param_1 + 0x2e4,*(undefined4 *)(param_1 + 4));
  if (iVar1 == 0) {
    iVar1 = FUN_001fe848(param_1 + 0x5c,*(undefined4 *)(param_1 + 4),0);
    if (iVar1 == 0) return 1;
  }
  return 0;
}
