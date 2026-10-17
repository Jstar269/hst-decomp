/* HSTMATCH module=EBOOT.BIN start=0x000626bc end=0x00062740 symbol=FUN_000626bc lang=c99 */
/* Clone of src/sharing_main/field_cleanup_00063544.c (hstclone.py tag u6cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj {
  int first;
  char pad_4[4];
  unsigned char active;
  char pad_9[3];
  int state;
  void *child;
} Obj;

extern void FUN_000104e0(void *);
extern void FUN_00062150(float);
extern void FUN_00062780(Obj *);
extern void FUN_00062904(Obj *, int);

void FUN_000626bc(Obj *self)
{
  if (self->active != 0) {
    FUN_00062904(self, self->state);
    FUN_00062150(30.0f);
    self->active = 0;
    if (self->child != 0) {
      if (self->child != 0) {
        FUN_000104e0(self->child);
        self->child = 0;
      }
    }
  }
  FUN_00062780(self);
  if (self->first != 0) {
    FUN_000104e0((void *)self->first);
    self->first = 0;
  }
}
