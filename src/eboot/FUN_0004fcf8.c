/* HSTMATCH module=EBOOT.BIN start=0x0004fcf8 end=0x0004fe04 symbol=FUN_0004fcf8 lang=c99 */
/* Clone of src/sharing_main/FUN_000505ac.c (hstclone.py tag s10170158a1r4e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
extern undefined DAT_002d0d40;
extern undefined DAT_002d0a6c;
extern undefined DAT_00311170;
extern char DAT_002d0e24[];
extern int FUN_00014934(const char *, const char *);
extern void FUN_0004ea98(const char *, const char *);
extern void FUN_0004f010(void *, int, void *, int, void *);
extern void FUN_0004fe04(void *, int);

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

void FUN_0004fcf8(Table *t, const char *name)
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
        FUN_0004fe04(t, i);
        found = 1;
        break;
      }
    }
  }
  if (!found) {
    FUN_0004ea98(DAT_002d0e24, name);
    FUN_0004f010(&DAT_00311170, 0, &DAT_002d0a6c, 1546, &DAT_002d0d40);
  }
}
