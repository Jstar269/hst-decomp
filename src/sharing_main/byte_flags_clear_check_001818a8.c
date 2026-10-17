/* HSTMATCH module=hstp_trans_main.prx start=0x001818a8 end=0x00181960 symbol=FUN_001818a8 lang=c99 */
/* Clone of src/eboot/byte_flags_clear_check_00175464.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the three byte tests written as one || chain (if (b8 != 0 || b11 != 0 || b12 != 0) bVar1 = false; else bVar1 = true;) instead of Ghidra's nested if/else; exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned int undefined4;
#define true 1
#define false 0
typedef int (*Fn)();

undefined4 FUN_001818a8(int param_1)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = ((Fn)*(int *)(param_1 + 0x558))();
  if ((iVar2 != 0x7fff) && (iVar2 = ((Fn)*(int *)(param_1 + 0x558))(), iVar2 != 0x7ffe)) {
    iVar2 = *(int *)(param_1 + 0x538);
    iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 8) * 0xc) +
                    *(int *)(iVar2 + 4) * 4);
    if (*(uchar *)(iVar2 + 8) != 0 || *(uchar *)(iVar2 + 0xb) != 0 || *(uchar *)(iVar2 + 0xc) != 0) bVar1 = false; else bVar1 = true;
    if (bVar1) return 1;
  }
  return 0;
}
