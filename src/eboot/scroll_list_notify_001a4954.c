/* HSTMATCH module=EBOOT.BIN start=0x001a4954 end=0x001a4998 symbol=FUN_001a4954 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: struct view with the two list cursor words and the item count, typed prototypes (matching idiom: the item count member is `volatile int`; with a plain int MWCC sinks the load behind the address arithmetic of the first two arguments, retail loads a2 from a0 before `move s0,a0`); exact match verified; names and types await human review. */
typedef struct Obj_001a4954 {
  char pad000[0x68];
  char sub068[0x258];
  int p2c0;
  int p2c4;
  int p2c8;
  char pad2cc[0xb0];
  volatile int count;
} Obj_001a4954;

extern void FUN_001af8e4(void *);
extern void FUN_001fedc4(int *, int *, int, int, int, int);

void FUN_001a4954(Obj_001a4954 *o, int param_2)
{
  FUN_001fedc4(&o->p2c0, &o->p2c8, o->count, 6, param_2, 0);
  FUN_001af8e4(o->sub068);
}
