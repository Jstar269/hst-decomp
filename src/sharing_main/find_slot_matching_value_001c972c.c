/* HSTMATCH module=hstp_trans_main.prx start=0x001c972c end=0x001c98a0 symbol=FUN_001c972c lang=c99 */
/* Clone of src/eboot/find_slot_matching_value_001bb944.c (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (matching idioms: static inline bounds-checked SlotAt() that still dereferences its null result, bool flag set in both arms of an && / else, switch on the kind with cases in source order 1,2,3); exact match verified; names and types await human review. */
typedef unsigned char bool;
typedef struct Ent { char pad0[4]; unsigned char state; char pad1[0x33]; } Ent;
typedef struct Block { Ent ents[15]; } Block;
typedef struct Rec { char pad0[2]; short s2; short s4; short s6; short s8; } Rec;
typedef struct Res { char pad[0x60]; char f60; } Res;

extern int DAT_003e1e48;
extern Res *FUN_000dca74(int, int, int);
extern Rec *FUN_0019fc84(int);

static inline unsigned char *SlotAt(Block *b, int idx)
{
  if (idx >= 0 && idx < 15)
    return &b->ents[idx].state;
  return 0;
}

int FUN_001c972c(Block *param_1, int param_2, int param_3)
{
  int i;
  for (i = 0; i < 15; i++) {
    bool found = 0;
    if (param_1 != 0 && (unsigned)(*SlotAt(param_1, i) - 4) < 2) {
      found = 1;
    } else {
      if (FUN_000dca74(DAT_003e1e48, 0, i)->f60 == 1)
        found = 1;
    }
    if (found) {
      Rec *r = FUN_0019fc84(i);
      if (r != 0) {
        switch (param_2) {
        case 1:
          if (r->s2 == param_3) return 1;
          break;
        case 2:
          if (r->s4 == param_3) return 1;
          break;
        case 3:
          if (param_3 != 0 && r->s6 == param_3) return 1;
          if (param_3 != 0 && r->s8 == param_3) return 1;
          break;
        }
      }
    }
  }
  return 0;
}
