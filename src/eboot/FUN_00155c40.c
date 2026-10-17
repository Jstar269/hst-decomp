/* HSTMATCH module=EBOOT.BIN start=0x00155c40 end=0x00155cac symbol=FUN_00155c40 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q3); exact match verified; names and types await human review. */
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

extern undefined DAT_003402f0;
extern undefined4 DAT_0034a114;
extern char DAT_002dcb90[];
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern int FUN_001c70c0();
extern void FUN_00293764();

undefined4 FUN_00155c40(int param_1,undefined4 param_2)
{
  int iVar1;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dcb90,*(undefined4 *)(param_1 + 8));
  }
  iVar1 = FUN_001c70c0(DAT_0034a114,*(undefined4 *)(param_1 + 8));
  if (iVar1 != 0) {
    FUN_00293764(iVar1,0);
  }
  return 0;
}
