/* HSTMATCH module=EBOOT.BIN start=0x0026397c end=0x00263a40 symbol=FUN_0026397c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0c) corrected by hand: typed the float argument and deallocation receiver; exact match verified; names and types await human review. */
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

extern undefined DAT_00309aac;
extern undefined4 DAT_00331b84;
extern undefined4 DAT_003415ac;
extern void FUN_00000a00(undefined4 *);
extern void FUN_00063478(float,undefined4);
extern void FUN_00103628(undefined4, int);
extern undefined4 * FUN_00258180();
extern undefined4 * FUN_0025e600();

undefined4 * FUN_0026397c(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309aac);
    FUN_00063478(203000.0f,DAT_00331b84);
    FUN_00103628(DAT_003415ac,1);
    *(undefined1 *)(param_1[400] + 0x616) = 0;
    *(undefined1 *)(param_1[400] + 0x736) = 0;
    *(undefined1 *)(param_1[400] + 0x856) = 0;
    *(undefined1 *)(param_1[400] + 0x617) = 0;
    *(undefined1 *)(param_1[400] + 0x737) = 0;
    *(undefined1 *)(param_1[400] + 0x857) = 0;
    FUN_0025e600(param_1 + 0x618,-1);
    FUN_00258180(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
