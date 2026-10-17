/* HSTMATCH module=EBOOT.BIN start=0x001a4998 end=0x001a49dc symbol=FUN_001a4998 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: struct view with the two list cursor words and the item count, typed prototypes (matching idiom: the item count member is `volatile int`; with a plain int MWCC sinks the load behind the address arithmetic of the first two arguments, retail loads a2 from a0 before `move s0,a0`); exact match verified; names and types await human review. */
typedef struct Obj_001a4998 {
  char pad000[0x68];
  char sub068[0x294];
  int p2fc;
  int p300;
  int p304;
  char pad308[0x80];
  volatile int count;
} Obj_001a4998;

extern void FUN_001af9f4(void *);
extern void FUN_001fedc4(int *, int *, int, int, int, int);

void FUN_001a4998(Obj_001a4998 *o, int param_2)
{
  FUN_001fedc4(&o->p2fc, &o->p304, o->count, 9, param_2, 0);
  FUN_001af9f4(o->sub068);
}
