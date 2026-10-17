/* HSTMATCH module=EBOOT.BIN start=0x00153584 end=0x001535f0 symbol=FUN_00153584 lang=c99 */
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
extern undefined * DAT_0034a114;
extern char DAT_002dc760[];
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001c7d30();

undefined4 FUN_00153584(int param_1,undefined4 param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dc760,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(param_1 + 0xc));
  }
  FUN_001c7d30(DAT_0034a114,*(undefined4 *)(DAT_0034a114 + 0xcc),*(int *)(param_1 + 8) + -1,
               *(undefined4 *)(param_1 + 0xc),0);
  return 0;
}
