/* HSTMATCH module=hstp_trans_main.prx start=0x00089fd8 end=0x0008a034 symbol=FUN_00089fd8 lang=c99 */
/* Clone of src/eboot/slot_key_equals_00088880.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e19f8 is unsigned char, slots addressed through a typed struct, else branch re-reads slot 0; exact match verified; names and types await human review. */
typedef struct Ent {
  char pad[0x148];
  int key;
} Ent;
typedef struct Owner {
  char pad[0x70];
  Ent *slots[1];
} Owner;

extern unsigned char DAT_003e19f8;
extern char *DAT_003e1e04;

int FUN_00089fd8(Owner *param_1, int param_2)
{
  Ent *e;
  
  e = 0;
  if ((DAT_003e19f8 != 0) &&
     (*(unsigned char *)(DAT_003e1e04 + *(int *)(DAT_003e1e04 + 0x198) * 7 + 0x5e) != 0)) {
    e = param_1->slots[*(int *)(DAT_003e1e04 + 0x198)];
  }
  if (e == 0) {
    e = param_1->slots[0];
  }
  return param_2 == e->key;
}
