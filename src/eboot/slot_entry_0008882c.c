/* HSTMATCH module=EBOOT.BIN start=0x0008882c end=0x00088880 symbol=FUN_0008882c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v3) corrected by hand: modelled on src/eboot/slot_key_equals_00088880.c (typed slot array, else branch re-reads slot 0), the 7-byte flag records as a typed array reached through a local record pointer; exact match verified; names and types await human review. */
typedef struct Ent {
  char pad[0x148];
  int key;
} Ent;
typedef struct Owner {
  char pad[0x70];
  Ent *slots[4];
} Owner;
typedef struct Row7 {
  unsigned char on;
  char pad[6];
} Row7;
typedef struct Sel {
  char pad0[0x5e];
  Row7 ent[4];
  char pad1[0x198 - 0x5e - 28];
  int cur;
} Sel;

extern unsigned char DAT_003386b8;
extern Sel *DAT_00338ac4;

Ent *FUN_0008882c(Owner *param_1)
{
  Ent *e = 0;
  if (DAT_003386b8 != 0) {
    Row7 *r = &DAT_00338ac4->ent[DAT_00338ac4->cur];
    if (r->on != 0) {
      e = param_1->slots[DAT_00338ac4->cur];
    }
  }
  if (e == 0) {
    e = param_1->slots[0];
  }
  return e;
}
