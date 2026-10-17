/* HSTMATCH module=hstp_trans_main.prx start=0x000ee930 end=0x000ee9c4 symbol=FUN_000ee930 lang=c99 */
/* Clone of src/eboot/FUN_000e985c.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: the this argument Ghidra dropped from the base constructor call restored; exact match verified; names and types await human review. */
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

extern undefined DAT_002d1220;
extern undefined DAT_003b09d8;
extern void FUN_000007f4();
extern undefined4 * FUN_0001ec44();
extern void FUN_000eea54();
extern void FUN_000ec490();
extern void FUN_000ee9c4();

undefined4 * FUN_000ee930(undefined4 *param_1,undefined4 param_2)
{
  FUN_0001ec44(param_1);
  *param_1 = (unsigned int)(&DAT_003b09d8);
  FUN_000007f4(param_1 + 0x154,FUN_000ee9c4,FUN_000ec490,0x50,2);
  param_1[0xf] = param_2;
  FUN_000eea54(param_1);
  param_1[0x164] = (unsigned int)(&DAT_002d1220);
  param_1[0x178] = (unsigned int)(&DAT_002d1220);
  param_1[0x17e] = 0;
  param_1[0x17c] = 0x3f800000;
  param_1[0x17d] = 0;
  param_1[0x17f] = 0x1e;
  return param_1;
}
