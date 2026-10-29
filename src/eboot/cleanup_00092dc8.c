/* HSTMATCH module=EBOOT.BIN start=0x00092dc8 end=0x00092e1c symbol=FUN_00092dc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: test the first field directly before loading the second; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/char_model.h"

extern int FUN_00055e48();
extern void FUN_0005734c();

/* Releases the loaded body type: item 2, the mesh object, and the body-type id. */
void FUN_00092dc8(CharModel *self)
{
  struct ModelMesh *mesh;

  if (self->item[2] != 0) {
    FUN_0005734c(self->item[2]);
  }
  mesh = self->mesh;
  if (mesh != 0) {
    FUN_00055e48(mesh,1);
    self->mesh = 0;
  }
  self->body_type = CHAR_INDEX_NONE;
}
