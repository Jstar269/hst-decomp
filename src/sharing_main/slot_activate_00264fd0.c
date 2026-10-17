/* HSTMATCH module=hstp_trans_main.prx start=0x00264fd0 end=0x00265048 symbol=FUN_00264fd0 lang=c99 */
/* Clone of src/eboot/slot_activate_00254b58.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: replaced numeric address 0x3eaad8 with &DAT_003eaad8; exact match verified; names and types await human review. */

typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern char DAT_003eaad8;
extern undefined DAT_003f468c;
extern void FUN_001a164c();
extern undefined4 FUN_001bfc3c();
extern void FUN_002643dc();

void FUN_00264fd0(int param_1,int param_2)
{
  if (*(int *)(&DAT_003f468c + param_2 * 4) != 0) {
    FUN_001a164c(*(int *)(&DAT_003f468c + param_2 * 4),param_2,0,1);
    FUN_002643dc(param_2);
    *(undefined1 *)(param_2 + param_1 + 4) = 1;
    FUN_001bfc3c(&DAT_003eaad8,0x16);
  }
}
