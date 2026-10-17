/* HSTMATCH module=hstp_trans_main.prx start=0x000efa78 end=0x000efafc symbol=FUN_000efa78 lang=c99 */
/* Clone of src/eboot/alloc_pair_000ea868.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: merged each allocation store and restored the final constructor argument; exact match verified; names and types await human review. */
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

extern int FUN_00000bcc();
extern undefined4 * FUN_0005b814(undefined4 *, int, int, int, int, int);

void FUN_000efa78(int param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00000bcc(0x70);
  if (puVar1 != (undefined4 *)0x0)
    puVar1 = FUN_0005b814(puVar1,1,4,1,1,0);
  *(undefined4 **)(param_1 + 0x40) = puVar1;
  puVar1 = (undefined4 *)FUN_00000bcc(0x70);
  if (puVar1 != (undefined4 *)0x0)
    puVar1 = FUN_0005b814(puVar1,1,4,1,1,0);
  *(undefined4 **)(param_1 + 0x44) = puVar1;
  return;
}
