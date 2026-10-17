/* HSTMATCH module=hstp_trans_main.prx start=0x001d18b8 end=0x001d1978 symbol=FUN_001d18b8 lang=c99 */
/* Clone of src/eboot/FUN_001c352c_001c352c.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte-check return and float/pointer helper arguments; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003ea8ec;
extern undefined4 DAT_003ea914;
extern void *DAT_003f344c;
extern void FUN_00108f54();
extern int FUN_001204dc();
extern undefined4 FUN_001205f0();
extern void FUN_0019cdc8();
extern void FUN_001d5124(float,void *,int);
extern void FUN_001d8ec4();
extern void FUN_001dbab4();
extern void FUN_001dbf68();

void FUN_001d18b8(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001204dc(DAT_003ea8ec);
  if (iVar1 != 0) {
    FUN_00108f54(DAT_003ea8ec,1);
    iVar1 = FUN_001205f0(DAT_003ea8ec);
    if (iVar1 == 0) {
      FUN_001d8ec4(*(undefined4 *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0xe8) = 1;
      *(undefined1 *)(param_1 + 0xf0) = 0;
      FUN_0019cdc8(DAT_003ea914,3);
      FUN_001dbf68(param_1,8,1);
      FUN_001dbab4(*(undefined4 *)(param_1 + 0x18));
    }
    else {
      FUN_001dbf68(param_1,0,1);
      FUN_001d5124(1.0f,DAT_003f344c,1);
    }
  }
  return;
}
