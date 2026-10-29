/* HSTMATCH module=EBOOT.BIN start=0x000bcf88 end=0x000bd014 symbol=FUN_000bcf88 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/member_session.h"

extern char DAT_002d53ec[];
extern int DAT_00338ac4;
extern void FUN_000ba3ac(char *tag);
extern int FUN_000bda40(int a, int b, unsigned short c, int d, int e);

enum { MODE_START = 11 };

void FUN_000bcf88(MemberSession *self)
{
  int env;

  FUN_000ba3ac(DAT_002d53ec);
  self->prev_count = self->count;
  self->count = 0;
  self->mode = MODE_START;
  switch (self->mode) {
  case 4:
  case 8:
    env = DAT_00338ac4; /* environment object and its address +0x38 are passed */
    self->unk17c =
        FUN_000bda40(env, env + 0x38, self->unk10, 1444, 0) & 0xff;
    break;
  case 10:
    break;
  }
}
