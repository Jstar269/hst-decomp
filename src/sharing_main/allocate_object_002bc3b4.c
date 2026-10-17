/* HSTMATCH module=hstp_trans_main.prx start=0x002bc3b4 end=0x002bc4e4 symbol=FUN_002bc3b4 lang=c99 */
/* Clone of src/eboot/allocate_object_002acbf8.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: assigned the allocation result in the null-check expression and shared its return path; exact match verified; names and types await human review. */
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

extern undefined DAT_002cc260;
extern undefined DAT_003b0a68;
extern char DAT_002dc5a0[];
extern char DAT_002dc5a8[];
extern char DAT_002dc5b0[];
extern int FUN_00000bcc();
extern int FUN_00014934();
extern undefined4 FUN_00056cac();
extern undefined4 * FUN_001016c0();
extern undefined4 * FUN_00101748();
extern undefined4 * FUN_001017dc();

undefined4 * FUN_002bc3b4(int param_1,undefined4 param_2,undefined1 *param_3)
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00014934(param_2,DAT_002dc5b0);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    *(int *)(param_1 + 0x54) = iVar1 + -1;
    *param_3 = 0 < iVar1;
  }
  else {
    iVar1 = FUN_00014934(param_2,DAT_002dc5a8);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x58);
      *(int *)(param_1 + 0x58) = iVar1 + -1;
      *param_3 = 0 < iVar1;
    }
    else {
      iVar1 = FUN_00014934(param_2,DAT_002dc5a0);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 0x5c);
        *(int *)(param_1 + 0x5c) = iVar1 + -1;
        *param_3 = 0 < iVar1;
      }
      else {
        *param_3 = 0;
      }
    }
  }
  if ((puVar2 = (undefined4 *)FUN_00000bcc(0xd0)) == (undefined4 *)0x0) goto done;
  FUN_001017dc(puVar2);
  FUN_00056cac(puVar2 + 0xc);
  *puVar2 = (unsigned int)(&DAT_003b0a68);
  puVar2[0x1c] = 0;
  puVar2[0x1d] = 0xffffffff;
  puVar2[0x1e] = 0x3f800000;
  puVar2[0x1f] = 0x3f800000;
  FUN_00056cac(puVar2 + 0x20);
  puVar2[0x30] = param_2;
  FUN_00101748(puVar2,&DAT_002cc260);
  FUN_001016c0(puVar2 + 0x20,&DAT_002cc260);
done:
  return puVar2;
}
