/* HSTMATCH module=EBOOT.BIN start=0x000d8c24 end=0x000d8c98 symbol=FUN_000d8c24 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#define GROUP_REMAP_FROM 4 /* group id that is treated as group 3 */
#define GROUP_REMAP_TO 3
#define ELEM_UNUSED (-1)   /* marker in an element's byte at +0x60 */

/* One group of element pointers: three words, the pointer array and its length. */
typedef struct ElemGroup {
  int unk0;        /* 0x0 */
  void **items;    /* 0x4 */
  unsigned count;  /* 0x8 */
} ElemGroup;

/* Look up element [index] of a group; returns 0 for a bad index, a null slot or an unused element. */
void * FUN_000d8c24(int table,int group,int index)
{
  ElemGroup *g;
  void *p;
  int off;

  if (group == GROUP_REMAP_FROM) {
    group = GROUP_REMAP_TO;
  }
  if (index >= 0) {
    off = group * 12;
    g = (ElemGroup *)(off + table);
    if ((unsigned int)index < g->count) {
      p = g->items[index];
      if (p != 0) {
        if (*(signed char *)((int)p + 0x60) != ELEM_UNUSED) {
          return p;
        }
      }
    }
  }
  return 0;
}
