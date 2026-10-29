/* HSTMATCH module=EBOOT.BIN start=0x001fa018 end=0x001fa0e4 symbol=FUN_001fa018 lang=c99 */
/* Hand-written reconstruction from the disassembly (matching idiom: the call arguments read the entry kind through the inline getter Kind(); plain member reads are CSE'd with the compares); exact match verified; names and types await human review. */
#define ENTRY_COUNT 10
#define ENTRY_STRIDE 12
#define ENTRY_KIND_SELECT 0xc /* kind whose val is mapped to 5, 10 or 1 */

/* Table of 12-byte entries starting at 0x12e0; p walks over the (kind, val) pairs. */
typedef struct Obj {
  char pad[0x12e0];
  int kind;
  int val;
} Obj;
static inline int Kind(const Obj *o) { return o->kind; }

extern void FUN_001bfdd0(int, int, int, int);

void FUN_001fa018(Obj *self, int ctx)
{
  int i = 0;
  Obj *p = self;
  do {
    if (p->kind == ENTRY_KIND_SELECT) {
      if (p->val == 1) {
        FUN_001bfdd0(ctx, Kind(p), 5, 0);
      } else if (p->val == 2) {
        FUN_001bfdd0(ctx, Kind(p), 10, 0);
      } else {
        FUN_001bfdd0(ctx, Kind(p), 1, 0);
      }
    } else {
      FUN_001bfdd0(ctx, Kind(p), p->val, 4);
    }
    i++;
    p = (Obj *)((char *)p + ENTRY_STRIDE);
  } while (i < ENTRY_COUNT);
}
