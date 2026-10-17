/* HSTMATCH module=hstp_trans_main.prx start=0x00063544 end=0x000635c8 symbol=FUN_00063544 lang=c99 */
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
extern void FUN_00062fd4(float);
extern void FUN_00063608(Obj *);
extern void FUN_000637c8(Obj *, int);

void FUN_00063544(Obj *self)
{
  if (self->active != 0) {
    FUN_000637c8(self, self->state);
    FUN_00062fd4(30.0f);
    self->active = 0;
    if (self->child != 0) {
      if (self->child != 0) {
        FUN_000104e0(self->child);
        self->child = 0;
      }
    }
  }
  FUN_00063608(self);
  if (self->first != 0) {
    FUN_000104e0((void *)self->first);
    self->first = 0;
  }
}
