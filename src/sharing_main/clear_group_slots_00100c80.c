/* HSTMATCH module=hstp_trans_main.prx start=0x00100c80 end=0x00100ccc symbol=FUN_00100c80 lang=c99 */
/* Clone of src/eboot/clear_group_slots_000fb544.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: struct views (node-pointer array and 12-byte record array of one group), the two walking pointers turned into a counted for loop over g->nodes[i] / g->recs[i]; exact match verified; names and types await human review. */
typedef struct Node_00100c80 {
  char pad000[0x60];
  int f60;
  int f64;
  char pad068[0x10];
  int f78;
} Node_00100c80;

typedef struct Rec_00100c80 {
  int fa;
  int fb;
  int fc;
} Rec_00100c80;

typedef struct Group_00100c80 {
  char pad000[0x9c];
  Node_00100c80 *nodes[11];
  Rec_00100c80 recs[11];
} Group_00100c80;

typedef struct Obj_00100c80 {
  char pad000[0x3c];
  Group_00100c80 *group;
} Obj_00100c80;

void FUN_00100c80(Obj_00100c80 *o)
{
  Group_00100c80 *g = o->group;
  unsigned int i;
  for (i = 0; i < 11; i++) {
    Node_00100c80 *n = g->nodes[i];
    if (n != 0) {
      g->recs[i].fa = 0;
      n->f60 = 0;
      g->recs[i].fb = 0;
      n->f64 = 0;
      g->recs[i].fc = 0;
      n->f78 = 0;
    }
  }
}
