/* HSTMATCH module=hstp_trans_main.prx start=0x000bd360 end=0x000bd3c0 symbol=FUN_000bd360 lang=c99 */
/* Clone of src/eboot/vec4_copy_by_table_000ba01c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the 16-byte copy typed as four float fields (interleaved lwc1/swc1), table pointer global typed as a struct pointer with the index scaled first; exact match verified; names and types await human review. */
typedef struct V4 { float x, y, z, w; } V4;
typedef struct Ent { char pad[0x5bc]; int k; } Ent;
typedef struct Tab { char pad[0x70]; Ent *e[1]; } Tab;
typedef struct Arg { char pad[8]; int idx; } Arg;

extern Tab *DAT_003e19f0;
extern V4 *FUN_0009575c(int);

void FUN_000bd360(V4 *param_1, Arg *param_2)
{
  V4 *p = FUN_0009575c(DAT_003e19f0->e[param_2->idx]->k);
  param_1->x = p->x;
  param_1->y = p->y;
  param_1->z = p->z;
  param_1->w = p->w;
}
