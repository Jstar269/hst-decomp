/* HSTMATCH module=EBOOT.BIN start=0x00127870 end=0x00127a20 symbol=FUN_00127870 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: the return type is int, not bool (no 0xff mask in retail); exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 DAT_0033b4f0;
extern undefined4 DAT_0033b4f4;
extern undefined4 DAT_0033b4f8;
extern undefined4 DAT_0033b4fc;
extern undefined4 DAT_0033b500;
extern undefined4 DAT_0033b504;
extern undefined4 DAT_0033b508;
extern undefined4 DAT_0033b50c;
extern undefined4 DAT_0033b510;
extern undefined4 DAT_0033b514;
extern undefined4 DAT_0033b518;
extern undefined4 DAT_0033b51c;
extern undefined4 DAT_0033b520;
extern undefined4 DAT_0033b524;
extern undefined4 DAT_0033b528;
extern undefined4 DAT_0033b52c;
extern undefined4 DAT_0033b530;
extern undefined4 DAT_0033b534;

int FUN_00127870(int param_1)
{
  return ((((((((((((((((param_1 != DAT_0033b4f0 && param_1 != DAT_0033b4f4) &&
                       param_1 != DAT_0033b4f8) && param_1 != DAT_0033b4fc) &&
                     param_1 != DAT_0033b500) && param_1 != DAT_0033b504) &&
                   param_1 != DAT_0033b508) && param_1 != DAT_0033b50c) &&
                 param_1 != DAT_0033b510) && param_1 != DAT_0033b514) && param_1 != DAT_0033b518)
              && param_1 != DAT_0033b51c) && param_1 != DAT_0033b520) && param_1 != DAT_0033b524)
           && param_1 != DAT_0033b528) && param_1 != DAT_0033b52c) && param_1 != DAT_0033b530) &&
         param_1 != DAT_0033b534;
}
