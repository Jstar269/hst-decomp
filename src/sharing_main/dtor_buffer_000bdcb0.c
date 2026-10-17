/* HSTMATCH module=hstp_trans_main.prx start=0x000bdcb0 end=0x000bdd24 symbol=FUN_000bdcb0 lang=c99 */
/* Clone of src/eboot/dtor_buffer_000ba96c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the free call takes the tested member (FUN_000009e4(param_1[2])); exact match verified; names and types await human review. */
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

extern undefined DAT_003b06b0;
extern void FUN_000009e4(undefined4);
extern void FUN_00000a00();

undefined4 * FUN_000bdcb0(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b06b0);
    if (param_1[2] != 0) {
      FUN_000009e4(param_1[2]);
      param_1[2] = 0;
    }
    param_1[1] = 0;
    param_1[3] = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
