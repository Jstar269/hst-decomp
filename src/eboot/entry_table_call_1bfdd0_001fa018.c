/* HSTMATCH module=EBOOT.BIN start=0x001fa018 end=0x001fa0e4 symbol=FUN_001fa018 lang=c99 */
/* Hand-written reconstruction from the disassembly (matching idiom: the call arguments read the entry kind through the inline getter Kind(); plain member reads are CSE'd with the compares); exact match verified; names and types await human review. */
typedef struct Obj {
  char pad[0x12e0];
  int kind;
  int val;
} Obj;
static inline int Kind(const Obj *o) { return o->kind; }

extern void FUN_001bfdd0(int, int, int, int);

void FUN_001fa018(Obj *param_1, int param_2)
{
  int i = 0;
  Obj *p = param_1;
  do {
    if (p->kind == 0xc) {
      if (p->val == 1) {
        FUN_001bfdd0(param_2, Kind(p), 5, 0);
      } else if (p->val == 2) {
        FUN_001bfdd0(param_2, Kind(p), 10, 0);
      } else {
        FUN_001bfdd0(param_2, Kind(p), 1, 0);
      }
    } else {
      FUN_001bfdd0(param_2, Kind(p), p->val, 4);
    }
    i++;
    p = (Obj *)((char *)p + 12);
  } while (i < 10);
}
