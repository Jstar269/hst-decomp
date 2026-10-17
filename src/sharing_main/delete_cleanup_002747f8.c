/* HSTMATCH module=hstp_trans_main.prx start=0x002747f8 end=0x002748bc symbol=FUN_002747f8 lang=c99 */
/* Clone of src/eboot/delete_cleanup_0026397c.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2d94;
extern undefined4 DAT_003daec4;
extern undefined4 DAT_003ea8ec;
extern void FUN_00000a00(undefined4 *);
extern void FUN_0006433c(float,undefined4);
extern void FUN_00108f54(undefined4, int);
extern undefined4 * FUN_00268630();
extern undefined4 * FUN_0026f428();

undefined4 * FUN_002747f8(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2d94);
    FUN_0006433c(203000.0f,DAT_003daec4);
    FUN_00108f54(DAT_003ea8ec,1);
    *(undefined1 *)(param_1[400] + 0x616) = 0;
    *(undefined1 *)(param_1[400] + 0x736) = 0;
    *(undefined1 *)(param_1[400] + 0x856) = 0;
    *(undefined1 *)(param_1[400] + 0x617) = 0;
    *(undefined1 *)(param_1[400] + 0x737) = 0;
    *(undefined1 *)(param_1[400] + 0x857) = 0;
    FUN_0026f428(param_1 + 0x618,-1);
    FUN_00268630(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
