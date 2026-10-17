/* HSTMATCH module=hstp_trans_main.prx start=0x001b1f20 end=0x001b1f64 symbol=FUN_001b1f20 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: struct view with the two list cursor words and the item count, typed prototypes, adapted from the matched EBOOT twin src/eboot/scroll_list_notify_001a4954.c (matching idiom: the item count member is `volatile int`; with a plain int MWCC sinks the load behind the address arithmetic of the first two arguments, retail loads a2 from a0 before `move s0,a0`); exact match verified; names and types await human review. */
typedef struct Obj_001b1f20 {
  char pad000[0x68];
  char sub068[0x258];
  int p2c0;
  int p2c4;
  int p2c8;
  char pad2cc[0xb0];
  volatile int count;
} Obj_001b1f20;

extern void FUN_001bcfbc(void *);
extern void FUN_0020d594(int *, int *, int, int, int, int);

void FUN_001b1f20(Obj_001b1f20 *o, int param_2)
{
  FUN_0020d594(&o->p2c0, &o->p2c8, o->count, 6, param_2, 0);
  FUN_001bcfbc(o->sub068);
}
