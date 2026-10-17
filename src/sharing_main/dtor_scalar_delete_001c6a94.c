/* HSTMATCH module=hstp_trans_main.prx start=0x001c6a94 end=0x001c6b58 symbol=FUN_001c6a94 lang=c99 */
/* Clone of src/eboot/dtor_scalar_delete_001b8da8.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: restored the dropped delete argument (FUN_00000a00(param_1)) and passed &DAT_003eaad8 (lui/addiu) instead of the numeric address; exact match verified; names and types await human review. */
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

extern undefined DAT_003b258c;
extern undefined DAT_003eaad8;
extern void FUN_00000a00();
extern undefined4 * FUN_0001ed28();
extern void FUN_001c0454();
extern void FUN_001c1a28();
extern void FUN_001c71e4();

undefined4 * FUN_001c6a94(undefined4 *param_1,short param_2)
{
  int *piVar1;
  undefined4 uStack_4;
  int local_8;
  undefined4 *local_c;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b258c);
    FUN_001c1a28((int *)&DAT_003eaad8);
    if ((char *)param_1 + 0x3c != (char *)0) {
      FUN_001c0454(&DAT_003eaad8,0);
      piVar1 = (int *)(param_1 + 0xf);
      if (((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) && (piVar1 != (int *)0x0)) {
        local_c = param_1 + 0x10;
        local_8 = param_1[0x11];
        FUN_001c71e4(&uStack_4,piVar1,&local_8,&local_c);
      }
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
