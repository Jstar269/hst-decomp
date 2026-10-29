/* HSTMATCH module=EBOOT.BIN start=0x002665dc end=0x0026665c symbol=FUN_002665dc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the loop-bound member is declared `volatile int` (a non-volatile member or an untyped base makes MWCC hoist the bound address into v1 and re-read it through that pointer); names and types await human review. */
#include "hst/mover.h"

/* Returns 1 when every track of the body, first..last, has reached its limit, else 0. */
int FUN_002665dc(Mover *self)
{
  MoverBody *body = self->body;
  int i;
  for (i = body->first; i <= body->last; i++) {
    /* track row i, addressed by byte offset to keep the loop shape */
    char *row = (char *)body + i * 52;
    MoverRef *ref = *(MoverRef **)(row + 0xf4);
    float limit;
    if (ref) { limit = ref->data->limit; } else { limit = 0.0f; }
    if (*(float *)(row + 0x104) < limit) return 0;
  }
  return 1;
}
