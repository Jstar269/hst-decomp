/* HSTMATCH module=EBOOT.BIN start=0x0026f998 end=0x0026fcec symbol=FUN_0026f998 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand, starting from lane sn3's near-miss wip: the tail calls of the fifth loop pass the shared constant 3 as fourth argument too (Ghidra dropped it), which colours the element and kind registers like retail; prototypes added; readability pass; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
/* 0x30-byte element of the five lists. */
typedef struct Elem {
  unsigned char active; /* 0x00 */
  char unk1;
  unsigned char unk2;   /* 0x02 must be 0 for the element to be handled */
  char unk3;
  unsigned char unk4;   /* 0x04 must be non-zero for the element to be handled */
  char pad5[3];
  int id;               /* 0x08 passed to the handler */
  char padc[0xc];
  int kind;             /* 0x18 selects the handler argument in the last list */
  char pad1c[0x14];
} Elem;
typedef struct Vec {
  Elem *data;
  unsigned size;
} Vec;
typedef struct Obj {
  char pad[0x90];
  Vec vec90;
  char pad98[0x10];
  Vec veca8;
  char padb0[4];
  Vec vecb4;
  char padbc[4];
  Vec vecc0;
  char padc8[4];
  Vec veccc;
} Obj;

extern char *DAT_003415a8;
extern char *DAT_00341ccc;
extern void FUN_001bf884(char *, int, int);
extern void FUN_001bf980(char *, int, int);
extern void FUN_001bf948(char *, int, int);
extern void FUN_001bf9b8(char *, int, int);
extern void FUN_001bfdd0(char *, int, int, int);

/* Walks the five lists and hands every active element with unk2 == 0 and unk4 != 0 to its list's handler. */
void FUN_0026f998(Obj *self)
{
  unsigned i;
  Elem *e;

  i = 0;
  if (self->vec90.size != 0) {
    do {
      e = &self->vec90.data[i];
      if (e->active != 0) {
        if (e->unk2 == 0 && e->unk4 != 0) {
          FUN_001bf884(DAT_003415a8 + 0x80, e->id, 3);
        }
      }
      i++;
    } while (i < self->vec90.size);
  }
  i = 0;
  if (self->veca8.size != 0) {
    do {
      e = &self->veca8.data[i];
      if (e->active != 0) {
        if (e->unk2 == 0 && e->unk4 != 0) {
          FUN_001bf980(DAT_003415a8 + 0x80, e->id, 3);
        }
      }
      i++;
    } while (i < self->veca8.size);
  }
  i = 0;
  if (self->vecb4.size != 0) {
    do {
      e = &self->vecb4.data[i];
      if (e->active != 0) {
        if (e->unk2 == 0 && e->unk4 != 0) {
          FUN_001bf948(DAT_003415a8 + 0x80, e->id, 3);
        }
      }
      i++;
    } while (i < self->vecb4.size);
  }
  i = 0;
  if (self->vecc0.size != 0) {
    do {
      e = &self->vecc0.data[i];
      if (e->active != 0) {
        if (e->unk2 == 0 && e->unk4 != 0) {
          FUN_001bf9b8(DAT_003415a8 + 0x80, e->id, 3);
        }
      }
      i++;
    } while (i < self->vecc0.size);
  }
  i = 0;
  if (self->veccc.size != 0) {
    do {
      e = &self->veccc.data[i];
      if (e->active != 0) {
        if (e->unk2 == 0 && e->unk4 != 0) {
          int k = e->kind;
          if (k == 0) {
            FUN_001bfdd0(DAT_00341ccc, 7, e->id, 3);
          } else if (k == 1) {
            FUN_001bfdd0(DAT_00341ccc, 8, e->id, 3);
          } else if (k == 2) {
            FUN_001bfdd0(DAT_00341ccc, 9, e->id, 3);
          } else if (k == 3) {
            FUN_001bfdd0(DAT_00341ccc, 10, e->id, 3);
          } else if (k == 4) {
            FUN_001bfdd0(DAT_00341ccc, 11, e->id, 3);
          } else if (k == 5) {
            *(unsigned char *)(DAT_00341ccc + 0x1024) = 3;
          } else if (k == 7) {
            FUN_001bfdd0(DAT_00341ccc, 5, e->id, 3);
          } else if (k == 6) {
            FUN_001bfdd0(DAT_00341ccc, 6, e->id, 3);
          }
        }
      }
      i++;
    } while (i < self->veccc.size);
  }
}
