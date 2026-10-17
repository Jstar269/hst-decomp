/* HSTMATCH module=hstp_trans_main.prx start=0x000e3fe4 end=0x000e40ac symbol=FUN_000e3fe4 lang=c99 */
/* Clone of src/eboot/ctor_two_sub_objects_000dfdf8.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: sub-object allocation is 'p = alloc(); if (p) p = ctor(p, 1, 4, 1, 1, 0); m = p;' with the dropped sixth argument; exact match verified; names and types await human review. */
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

extern undefined DAT_003b09a0;
extern int FUN_00000bcc();
extern undefined4 * FUN_0001ec44();
extern undefined4 * FUN_0005b814();

undefined4 * FUN_000e3fe4(undefined4 *param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  
  FUN_0001ec44(param_1);
  *param_1 = (unsigned int)(&DAT_003b09a0);
  param_1[0xf] = param_2;
  puVar1 = (undefined4 *)FUN_00000bcc(0x70);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = FUN_0005b814(puVar1,1,4,1,1,0);
  }
  param_1[0x1c] = (unsigned int)(puVar1);
  puVar1 = (undefined4 *)FUN_00000bcc(0x70);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = FUN_0005b814(puVar1,1,4,1,1,0);
  }
  param_1[0x1d] = (unsigned int)(puVar1);
  param_1[0x14] = 0x3f800000;
  param_1[0x18] = 0x43000000;
  param_1[0x19] = 0x43000000;
  param_1[0x1a] = 0x43000000;
  param_1[0x1b] = 0x42800000;
  param_1[0x1e] = 0;
  return param_1;
}
