/* HSTMATCH module=hstp_trans_main.prx start=0x00268630 end=0x00268744 symbol=FUN_00268630 lang=c99 */
/* Clone of src/eboot/construct_cleanup_children_00258180.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed the pointer walk and ordered the cursor and count locals to match the loop registers; exact match verified; names and types await human review. */
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

extern undefined DAT_003b264c;
extern undefined DAT_003b2c34;
extern undefined DAT_003eaad8;
extern void FUN_00000788();
extern void FUN_00000a00(void *);
extern undefined4 FUN_00048e38();
extern int FUN_0005c688();
extern undefined4 * FUN_001087a8();
extern void FUN_001c1138();
extern void FUN_001c20b8();
extern int FUN_0026a598();
extern void FUN_0008eec4();

undefined4 * FUN_00268630(undefined4 *param_1,short param_2)
{
  uint uVar2;
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2c34);
    FUN_001c20b8((int *)&DAT_003eaad8);
    FUN_001c1138((int *)&DAT_003eaad8);
    FUN_00000788((int)(param_1 + 0x1bc),FUN_0008eec4,0x458,4);
    if ((char *)param_1 + 0x60 != (char *)0) {
      FUN_00048e38(1);
      uVar2 = 0;
      puVar1 = param_1;
      do {
        if (puVar1[0x30] != 0) {
          FUN_0005c688(puVar1[0x30],1);
          puVar1[0x30] = 0;
        }
        uVar2 = uVar2 + 1;
        puVar1 = puVar1 + 1;
      } while (uVar2 < 4);
      puVar1 = param_1 + 0x93;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_0026a598((int)puVar1,0);
      }
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b264c);
      FUN_001087a8(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
