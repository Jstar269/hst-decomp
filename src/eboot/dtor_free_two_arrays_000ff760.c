/* HSTMATCH module=EBOOT.BIN start=0x000ff760 end=0x000ff7d8 symbol=FUN_000ff760 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed struct, the free calls take the tested members as arguments; exact match verified; names and types await human review. */
typedef struct Obj {
  int pad0;
  void *b;
  void *a;
} Obj;

extern void FUN_000009e4(void *);
extern void FUN_00000a00(void *);

Obj *FUN_000ff760(Obj *p, short flags)
{
  if (p != 0) {
    if (p->a != 0) {
      FUN_000009e4(p->a);
      p->a = 0;
    }
    if (p->b != 0) {
      FUN_000009e4(p->b);
      p->b = 0;
    }
    if (0 < flags) {
      FUN_00000a00(p);
    }
  }
  return p;
}
