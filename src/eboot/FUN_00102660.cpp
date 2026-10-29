/* HSTMATCH module=EBOOT.BIN start=0x00102660 end=0x001026b8 symbol=FUN_00102660 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/node_item.h"

extern "C" {
extern void FUN_000ffdb4(...);
}
/* Node view with only the virtual call this source makes (slot 12). */
struct NodeView { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void m(int); };

/* Pass the item to its owned helper, then forward arg to the attached node. */
extern "C" void FUN_00102660(NodeItem *self,int arg)
{
  NodeView *node;

  if (self->unk1c != 0) {
    FUN_000ffdb4(self->unk1c,self);
  }
  node = (NodeView *)self->node;
  if (node != (NodeView *)0x0) {
    node->m(arg);
  }
}
