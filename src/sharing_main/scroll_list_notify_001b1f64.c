/* HSTMATCH module=hstp_trans_main.prx start=0x001b1f64 end=0x001b1fa8 symbol=FUN_001b1f64 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: struct view with the two list cursor words and the item count, typed prototypes, adapted from the matched EBOOT twin src/eboot/scroll_list_notify_001a4998.c (matching idiom: the item count member is `volatile int`; with a plain int MWCC sinks the load behind the address arithmetic of the first two arguments, retail loads a2 from a0 before `move s0,a0`); exact match verified; names and types await human review. */
typedef struct Obj_001b1f64 {
  char pad000[0x68];
  char sub068[0x294];
  int p2fc;
  int p300;
  int p304;
  char pad308[0x80];
  volatile int count;
} Obj_001b1f64;

extern void FUN_001bd0cc(void *);
extern void FUN_0020d594(int *, int *, int, int, int, int);

void FUN_001b1f64(Obj_001b1f64 *o, int param_2)
{
  FUN_0020d594(&o->p2fc, &o->p304, o->count, 9, param_2, 0);
  FUN_001bd0cc(o->sub068);
}
