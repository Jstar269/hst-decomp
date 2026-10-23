/* HSTMATCH module=EBOOT.BIN start=0x0012de6c end=0x0012e028 symbol=FUN_0012de6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0012de6c.c) corrected by hand: the if/else chain is a switch
   with the 2/3 group written before the 4 case (that is the order MWCC lays the bodies out in), the object's fields are a
   struct, the float-taking setters have their float parameter in signature position, and the pointer table is reached
   through a local int ** so the address add keeps retail's operand order; exact match verified; names and types await
   human review. */
extern int DAT_0033b574;
extern int DAT_0034a114;
extern char DAT_002bc410[];

extern int FUN_001cd594(int);
extern void FUN_0027be4c(int, int, int);
extern void FUN_00055044(int, const char *);
extern void FUN_000494d0(int, float, int, int);
extern void FUN_00058ddc(int, int, int);
extern void FUN_00058ec4(float, int, int);
extern void FUN_00058f38(float, int, int);
extern void FUN_0005f110(int, float);
extern void FUN_00059084(int, int);
extern void FUN_0012e7b4(void *, void *);
extern void FUN_0012e898(void *, void *, int);

typedef struct Obj {
  char pad0[0xf0];
  int mode;
  int pad1;
  int *f0f8;
  int pad1b;
  char f100[0x50];
  char f150[0xf0];
  int f240;
} Obj;

typedef struct Ent {
  char pad[0xc0];
  char f0c0;
  float f0c4;
  int pad2[2];
  float f0d0;
} Ent;

void FUN_0012de6c(Obj *self, int mode, int idx, int arg)
{
  Ent *e;
  int v;
  int **t;

  self->mode = mode;
  switch (mode) {
  case 2:
  case 3:
    t = (int **)DAT_0033b574;
    self->f0f8 = t[idx + 0x4e8];
    FUN_00055044(*(int *)self->f0f8, DAT_002bc410);
    FUN_000494d0((int)self->f0f8, 65534.0f, 0, 1);
    v = *(int *)self->f0f8;
    FUN_00058ddc(v, 0, -1);
    *(char *)(v + 0xc0) = 0;
    v = *(int *)self->f0f8;
    FUN_00058ec4(1.0f, v, -1);
    *(float *)(v + 0xc4) = 1.0f;
    e = (Ent *)*(int *)self->f0f8;
    FUN_00058f38(0.0f, (int)e, -1);
    FUN_0005f110((int)e, 0.0f);
    e = (Ent *)*(int *)self->f0f8;
    FUN_00059084((int)e, -1);
    e->f0d0 = e->f0c4;
    self->f240 = 0;
    FUN_0012e7b4(self, self->f100);
    FUN_0012e898(self, self->f150, (int)self->f0f8);
    break;
  case 4:
    v = FUN_001cd594(DAT_0034a114);
    if (v != 0) {
      v = FUN_001cd594(DAT_0034a114);
      FUN_0027be4c(v, idx, arg);
    }
    break;
  }
  if (mode != 4) {
    v = FUN_001cd594(DAT_0034a114);
    if (v != 0) {
      v = FUN_001cd594(DAT_0034a114);
      *(char *)(v + 100) = 0;
    }
  }
}
