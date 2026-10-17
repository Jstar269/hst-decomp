/* HSTMATCH module=EBOOT.BIN start=0x0005ce3c end=0x0005cfb4 symbol=FUN_0005ce3c lang=c99 */
/* Clone of src/sharing_main/destroy_buffers_0005dc04.c (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: opt_strength_reduction off (the first loop recomputes index*4); the id loops keep an explicit byte-offset induction variable next to the counter, the offset initialised inside the non-empty guard; the two member-destructor calls each sit behind a doubled null test. */
typedef struct {
  int a;
  int b;
  int id;
} Ent;
typedef struct {
  void **data;
  unsigned count;
} VecA;
typedef struct {
  char *data;
  unsigned count;
} VecB;
typedef struct {
  unsigned char owns;
  void *f4;
  VecA va;
  char pad10[8];
  void *f18;
  void *f1c;
  char *ids;
  VecB vb;
} Obj;

extern void FUN_000009e4(void *);
extern void FUN_00000a00(void *);
extern void FUN_0004fe04(void *, int);
extern void *FUN_0005da44(void *, int);
extern void *FUN_0005dbf4(void *, int);
extern char DAT_00311170[];

#pragma opt_strength_reduction off
Obj *FUN_0005ce3c(Obj *self, short flag)
{
  unsigned n;
  int off;
  int i;
  Ent *e;
  char *p;
  if (self != 0) {
    if (self->owns != 0) {
      FUN_000009e4(self->f4);
      for (i = 0; i < self->va.count; i++) {
        FUN_000009e4(self->va.data[i]);
      }
      FUN_000009e4(self->f18);
      FUN_000009e4(self->f1c);
    }
    n = 0;
    if (self->va.count != 0) {
      off = 0;
      do {
        FUN_0004fe04(DAT_00311170, *(int *)(self->ids + off));
        n++;
        off += 4;
      } while (n < self->va.count);
    }
    FUN_000009e4(self->ids);
    n = 0;
    if (self->vb.count != 0) {
      off = 0;
      do {
        e = (Ent *)(self->vb.data + off);
        FUN_0004fe04(DAT_00311170, e->id);
        e->id = -1;
        n++;
        off += 12;
      } while (n < self->vb.count);
    }
    p = (char *)self + 0x24;
    if (p != 0) {
      if (p != 0) {
        FUN_0005dbf4(p, 0);
      }
    }
    p = (char *)self + 8;
    if (p != 0) {
      if (p != 0) {
        FUN_0005da44(p, 0);
      }
    }
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
