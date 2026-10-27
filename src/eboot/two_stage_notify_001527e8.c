/* HSTMATCH module=EBOOT.BIN start=0x001527e8 end=0x00152858 symbol=FUN_001527e8 lang=c99 data=0x002dc68c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu), not undefined4; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc68c-0x002dc69c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern unsigned char DAT_003402f0;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_002878cc();

undefined4 FUN_001527e8(int param_1,int param_2)
{
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_002878cc(*(int *)(param_2 + 0xc),*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8)
                );
  }
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("SePlay [%s:%d]\n",*(undefined4 *)(param_1 + 0xc),
                 *(undefined4 *)(param_1 + 8));
  }
  return 0;
}
