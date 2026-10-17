/* HSTMATCH module=hstp_trans_main.prx start=0x0008c400 end=0x0008c498 symbol=FUN_0008c400 lang=c99 */
/* Clone of src/eboot/obj_update_slots_0008ad40.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a3/v10) corrected by hand: the byte flag at +0x4c is unsigned char (lbu) and the loop counter is declared before the pointer for the s-register assignment; exact match verified; names and types await human review. */
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

extern undefined DAT_003e19f8;
extern undefined4 DAT_003e1e30;
extern void FUN_000982d4();

void FUN_0008c400(char *param_1)
{
  uint uVar2;
  char *iVar1;
  
  if ((DAT_003e19f8 != '\0') && (DAT_003e1e30 != 0)) {
    uVar2 = 0;
    iVar1 = param_1;
    do {
      if (*(int *)(iVar1 + 0x70) != 0) {
        FUN_000982d4(*(int *)(iVar1 + 0x70),*(int *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 100))
        ;
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar2 < 4);
    if (*(unsigned char *)(param_1 + 0x4c) == 0) {
      *(undefined1 *)(param_1 + 0x4c) = 1;
      *(undefined4 *)(param_1 + 0x50) = 0x708;
    }
  }
  return;
}
