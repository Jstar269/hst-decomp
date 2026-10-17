/* HSTMATCH module=EBOOT.BIN start=0x00088880 end=0x000888dc symbol=FUN_00088880 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003386b8 is unsigned char, slots addressed through a typed struct, else branch re-reads slot 0; exact match verified; names and types await human review. */
typedef struct Ent {
  char pad[0x148];
  int key;
} Ent;
typedef struct Owner {
  char pad[0x70];
  Ent *slots[1];
} Owner;

extern unsigned char DAT_003386b8;
extern char *DAT_00338ac4;

int FUN_00088880(Owner *param_1, int param_2)
{
  Ent *e;
  
  e = 0;
  if ((DAT_003386b8 != 0) &&
     (*(unsigned char *)(DAT_00338ac4 + *(int *)(DAT_00338ac4 + 0x198) * 7 + 0x5e) != 0)) {
    e = param_1->slots[*(int *)(DAT_00338ac4 + 0x198)];
  }
  if (e == 0) {
    e = param_1->slots[0];
  }
  return param_2 == e->key;
}
