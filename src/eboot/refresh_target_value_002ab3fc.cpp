/* HSTMATCH module=EBOOT.BIN start=0x002ab3fc end=0x002ab4ec symbol=FUN_002ab3fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/vshistory.h"

struct Target {
  virtual void s0();
  virtual void s1(int);
  char pad[0xe0 - 4];
  float value; /* 0xe0 */
};
/* View of the page-3 object (page 3 is the 0x3138-byte part of the VS-history screen). */
struct Page3 {
  char pad0[0x1034];
  int selector;              /* 0x1034 */
  Target *target;            /* 0x1038 */
  char pad1[0x30c4 - 0x103c];
  unsigned char side_flag;   /* 0x30c4 */
  unsigned char unk30c5;     /* 0x30c5 */
  char pad2[2];
  int unk30c8;               /* 0x30c8 */
  int unk30cc;               /* 0x30cc */
  char pad3[0x30f0 - 0x30d0];
  CountRow rows[2];          /* 0x30f0 */
};

extern "C" {
extern char DAT_0034179c;
void FUN_002a8fbc(Page3 *);
void FUN_001b1c44(char *, int);
void FUN_0010b8cc(int, int, int);
void FUN_002ab180(Page3 *);
void FUN_00103128(Page3 *);
}

/* Re-read the page state: play the change cue, mirror the value into the target and enable it by row count. */
extern "C" void FUN_002ab3fc(Page3 *page)
{
  int old_30cc = page->unk30cc;
  int old_30c8 = page->unk30c8;
  FUN_002a8fbc(page);
  if (old_30cc != page->unk30cc || old_30c8 != page->unk30c8) {
    FUN_001b1c44(&DAT_0034179c, 1);
    if (old_30c8 != page->unk30c8) FUN_0010b8cc(page->selector, page->unk30c8, 0);
  }
  page->target->value = (float)page->unk30cc;
  unsigned char row = (page->side_flag != 0) ^ 1;
  int enable = 1;
  if (page->rows[row].count > 5) {
    if (page->unk30c5 == 0) enable = 0;
  }
  page->target->s1(enable);
  FUN_002ab180(page);
  FUN_00103128(page);
}
