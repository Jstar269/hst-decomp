/* HSTMATCH module=hstp_trans_main.prx start=0x000e8274 end=0x000e8340 symbol=FUN_000e8274 lang=c99 */
/* Clone of src/eboot/ctor_zero_table_000e3944.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: pointer local declared and initialised before the counter (swaps the v1/a0 registers of the unrolled clear loop), typed arguments; exact match verified; names and types await human review. */
extern char DAT_002d093c[];
extern char DAT_003b095c[];
extern void *FUN_0001ec44(void *);
extern void FUN_000e83a4(void *);
extern void FUN_000e8534(void *);

typedef struct O { void *vt; char pad[0x38]; void *m3c; int tab[25]; } O;

unsigned *FUN_000e8274(unsigned *param_1, unsigned param_2, unsigned param_3, unsigned param_4)
{
  unsigned *puVar2;
  int iVar1;
  FUN_0001ec44(param_1);
  *param_1 = (unsigned)DAT_003b095c;
  puVar2 = param_1 + 0xf;
  iVar1 = 0;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    iVar1 = iVar1 + 8;
    puVar2[7] = 0;
    puVar2 = puVar2 + 8;
  } while (iVar1 < 0x19);
  *puVar2 = 0;
  param_1[0x13] = param_2;
  param_1[0x12] = param_3;
  param_1[0xf] = (unsigned)DAT_002d093c;
  if (param_4 != 0) {
    param_1[0xf] = param_4;
  }
  FUN_000e83a4(param_1);
  FUN_000e8534(param_1);
  param_1[0x2a] = 0x43000000;
  param_1[0x2b] = 0;
  return param_1;
}
