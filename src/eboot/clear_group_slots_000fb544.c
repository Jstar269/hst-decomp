/* HSTMATCH module=EBOOT.BIN start=0x000fb544 end=0x000fb590 symbol=FUN_000fb544 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: struct views (node-pointer array and 12-byte record array of one group), the two walking pointers turned into a counted for loop over g->nodes[i] / g->recs[i]; exact match verified; names and types await human review. */
typedef struct Node_000fb544 {
  char pad000[0x60];
  int f60;
  int f64;
  char pad068[0x10];
  int f78;
} Node_000fb544;

typedef struct Rec_000fb544 {
  int fa;
  int fb;
  int fc;
} Rec_000fb544;

typedef struct Group_000fb544 {
  char pad000[0x9c];
  Node_000fb544 *nodes[11];
  Rec_000fb544 recs[11];
} Group_000fb544;

typedef struct Obj_000fb544 {
  char pad000[0x3c];
  Group_000fb544 *group;
} Obj_000fb544;

void FUN_000fb544(Obj_000fb544 *o)
{
  Group_000fb544 *g = o->group;
  unsigned int i;
  for (i = 0; i < 11; i++) {
    Node_000fb544 *n = g->nodes[i];
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
