/* HSTMATCH module=EBOOT.BIN start=0x00092d10 end=0x00092dc8 symbol=FUN_00092d10 lang=c++ data=0x002d2a0c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Obj struct, new-with-ctor store through one local, dropped call arguments restored (FUN_0004cfd0 receives the open result, FUN_00057034 receives the two tested members); readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d2a0c-0x002d2a3a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/char_model.h"

enum { MESH_OBJ_SIZE = 0x10 };

extern "C" void *FUN_00000bcc(int);
extern "C" void FUN_000143b0(char *, char *, int);
extern "C" int FUN_0004ccb8(char *, int, int);
extern "C" void FUN_0004cfd0(int);
extern "C" ModelMesh *FUN_00055df8(void *, char *, int);
extern "C" void FUN_00057034(ModelItem *, ModelMesh *);
extern "C" void FUN_00092dc8(CharModel *);

/* Loads the body-type model file for body_type: if it opens, drops the previous body type,
   builds the mesh object from the file, and hands it to item 2. */
extern "C" void FUN_00092d10(CharModel *self, int body_type)
{
  char buf[256];
  FUN_000143b0(buf, "data/chara/model/body_type/body_type_%03d.i3m", body_type);
  int r = FUN_0004ccb8(buf, 1, 1);
  if (r >= 0) {
    FUN_0004cfd0(r);
    FUN_00092dc8(self);
    self->body_type = body_type;
    ModelMesh *mem = (ModelMesh *)FUN_00000bcc(MESH_OBJ_SIZE);
    if (mem) mem = FUN_00055df8(mem, buf, 0);
    self->mesh = (struct ModelMesh *)mem;
    if (self->item[2] != 0 && self->mesh != 0) FUN_00057034(self->item[2], self->mesh);
  }
}
