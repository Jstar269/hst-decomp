/* HSTMATCH module=hstp_trans_main.prx start=0x00197b20 end=0x00197bdc symbol=FUN_00197b20 lang=c99 */
/* Clone of src/eboot/pair_toggle_0018b3d4.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: flag byte at +0x6f is unsigned char (lbu), loop index split from the call-result temporary and declared before the pointer (saved-register assignment); exact match verified; names and types await human review. */
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

extern char DAT_003881c4[];
extern char DAT_003881dc[];
extern char DAT_00388237[];
extern void FUN_00105470();
extern int FUN_00108124();
extern void FUN_00108aec();
extern int FUN_00109304();

void FUN_00197b20(int param_1)
{
  int iVar1;
  int j;
  int *piVar2;
  int local_8 [2];
  
  if (*(int *)(param_1 + 0x54) != 4) {
    iVar1 = FUN_00109304(param_1,(byte *)DAT_003881c4,0);
    local_8[0] = FUN_00108124(iVar1,(byte *)DAT_003881dc);
    iVar1 = FUN_00109304(param_1,(byte *)DAT_003881c4,0);
    local_8[1] = FUN_00108124(iVar1,(byte *)(DAT_00388237 + 1));
    j = 0;
    piVar2 = local_8;
    do {
      FUN_00105470(*piVar2,*(unsigned char *)(param_1 + 0x6f) != '\0' ^ 1);
      j = j + 1;
      piVar2 = piVar2 + 1;
    } while (j < 2);
    FUN_00108aec(param_1);
  }
  return;
}
