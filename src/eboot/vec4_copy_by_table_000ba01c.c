/* HSTMATCH module=EBOOT.BIN start=0x000ba01c end=0x000ba07c symbol=FUN_000ba01c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the 16-byte copy typed as four float fields (interleaved lwc1/swc1), table pointer global typed as a struct pointer with the index scaled first; exact match verified; names and types await human review. */
typedef struct V4 { float x, y, z, w; } V4;
typedef struct Ent { char pad[0x5bc]; int k; } Ent;
typedef struct Tab { char pad[0x70]; Ent *e[1]; } Tab;
typedef struct Arg { char pad[8]; int idx; } Arg;

extern Tab *DAT_003386b0;
extern V4 *FUN_00093838(int);

void FUN_000ba01c(V4 *param_1, Arg *param_2)
{
  V4 *p = FUN_00093838(DAT_003386b0->e[param_2->idx]->k);
  param_1->x = p->x;
  param_1->y = p->y;
  param_1->z = p->z;
  param_1->w = p->w;
}
