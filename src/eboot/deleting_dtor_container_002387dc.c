/* HSTMATCH module=EBOOT.BIN start=0x002387dc end=0x002388d4 symbol=FUN_002387dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: unified element pointer in reverse destruction loop, typed buffer delete; readability pass; exact match verified; names and types await human review. */

extern void FUN_00000788(void *, void *, int, int);
extern void FUN_00000a00(void *);
extern int FUN_002388d4(void *);
extern void FUN_00235c04(void);

enum { ELEM_SIZE = 560, PART_COUNT = 3, PART_SIZE = 24 };

typedef struct Elem {
    char pad00[196];
    char parts[PART_COUNT][PART_SIZE]; /* 0xc4, destroyed with an array-destroy helper */
    char padec[ELEM_SIZE - 196 - PART_COUNT * PART_SIZE];
} Elem;

/* Block-array container: element storage pointer, element count and a start offset in elements. */
typedef struct ElemBlock {
    Elem *data;     /* 0x00 */
    int count;      /* 0x04 */
    int unk8;       /* 0x08 */
    int unkc;       /* 0x0c */
    int start;      /* 0x10 first live element */
} ElemBlock;

/* Deleting destructor: destroy the live elements back to front, release the storage, free self when requested. */
ElemBlock * FUN_002387dc(ElemBlock *self, short flags)
{
  Elem *first;
  Elem *last;

  if (self != (ElemBlock *)0) {
    first = self->data + self->start;
    last = first + self->count;
    if (first < last) {
      do {
        --last;
        if (last != 0) {
          FUN_00000788(last->parts, FUN_00235c04, PART_SIZE, PART_COUNT);
        }
      } while (first < last);
      self->count = 0;
    }
    else {
      self->count = 0;
    }
    if (self != 0) {
      FUN_002388d4(self);
      if (self->data != 0) {
        FUN_00000a00(self->data);
      }
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
