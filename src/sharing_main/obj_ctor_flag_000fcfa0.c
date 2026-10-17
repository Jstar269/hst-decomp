/* HSTMATCH module=hstp_trans_main.prx start=0x000fcfa0 end=0x000fd044 symbol=FUN_000fcfa0 lang=c99 */
/* Clone of src/eboot/obj_ctor_flag_000f78ac.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the if/else flag store is a single store of a bool local (r = DAT == 0x2a; if (r) r = f() != 0), callee returns int; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0a48;
extern undefined4 DAT_003f39a8;
extern undefined4 * FUN_0010873c();
extern int FUN_0023c334();

undefined4 * FUN_000fcfa0(undefined4 *param_1)
{
  int r;
  
  FUN_0010873c();
  *param_1 = (unsigned int)(&DAT_003b0a48);
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  r = DAT_003f39a8 == 0x2a;
  if (r) {
    r = FUN_0023c334() != 0;
  }
  *(unsigned char *)((int)param_1 + 0x156) = r;
  return param_1;
}
