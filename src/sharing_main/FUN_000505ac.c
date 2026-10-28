/* HSTMATCH module=hstp_trans_main.prx start=0x000505ac end=0x000506b8 symbol=FUN_000505ac lang=c99 data=0x00376928 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00376928-0x00376964) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
extern u8 DAT_003767fc;
extern u8 DAT_003763c8;
extern u8 DAT_003ba4b0;
extern int FUN_00014934(const char *, const char *);
extern void FUN_0004efe0(const char *, const char *);
extern void FUN_0004f864(void *, int, void *, int, void *);
extern void FUN_000506b8(void *, int);

typedef struct {
  char *name;
  int pad[3];
} Entry;

typedef struct {
  char pad0[0x204];
  Entry entries[576];
  char pad1[0x19b84 - 0x204 - 576 * 16];
  short used[576];
  int count;
} Table;

void FUN_000505ac(Table *t, const char *name)
{
  int found;
  int n;
  int i;

  n = t->count;
  found = 0;
  for (i = 0; i < 576 && n > 0; i++) {
    if (t->used[i] != 0) {
      n--;
      if (FUN_00014934(t->entries[i].name, name) == 0) {
        FUN_000506b8(t, i);
        found = 1;
        break;
      }
    }
  }
  if (!found) {
    FUN_0004efe0("I3d::DeleteTexture(const char* pTexName) can not found %s.\n", name);
    FUN_0004f864(&DAT_003ba4b0, 0, &DAT_003763c8, 1546, &DAT_003767fc);
  }
}
