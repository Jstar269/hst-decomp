/* HSTMATCH module=hstp_trans_main.prx start=0x00132ae0 end=0x00132c90 symbol=FUN_00132ae0 lang=c99 */
/* Clone of src/eboot/FUN_00127870.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e4830;
extern undefined4 DAT_003e4834;
extern undefined4 DAT_003e4838;
extern undefined4 DAT_003e483c;
extern undefined4 DAT_003e4840;
extern undefined4 DAT_003e4844;
extern undefined4 DAT_003e4848;
extern undefined4 DAT_003e484c;
extern undefined4 DAT_003e4850;
extern undefined4 DAT_003e4854;
extern undefined4 DAT_003e4858;
extern undefined4 DAT_003e485c;
extern undefined4 DAT_003e4860;
extern undefined4 DAT_003e4864;
extern undefined4 DAT_003e4868;
extern undefined4 DAT_003e486c;
extern undefined4 DAT_003e4870;
extern undefined4 DAT_003e4874;

int FUN_00132ae0(int param_1)
{
  return ((((((((((((((((param_1 != DAT_003e4830 && param_1 != DAT_003e4834) &&
                       param_1 != DAT_003e4838) && param_1 != DAT_003e483c) &&
                     param_1 != DAT_003e4840) && param_1 != DAT_003e4844) &&
                   param_1 != DAT_003e4848) && param_1 != DAT_003e484c) &&
                 param_1 != DAT_003e4850) && param_1 != DAT_003e4854) && param_1 != DAT_003e4858)
              && param_1 != DAT_003e485c) && param_1 != DAT_003e4860) && param_1 != DAT_003e4864)
           && param_1 != DAT_003e4868) && param_1 != DAT_003e486c) && param_1 != DAT_003e4870) &&
         param_1 != DAT_003e4874;
}
