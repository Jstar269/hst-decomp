/* HSTMATCH module=hstp_trans_main.prx start=0x000e8534 end=0x000e8668 symbol=FUN_000e8534 lang=c99 */
/* Hand-written reconstruction from the disassembly; two-function run (0xe8534 ends in a tail call `j` to the next function 0xe861c, defined in the same file); exact match verified; names and types await human review. */

extern void FUN_00051d38(float, void *);
extern void FUN_00051d40(void *, int);
extern void FUN_00051d9c(void *, int);

typedef struct { short s0; short count; } Info;
typedef struct { char b0; char pad[111]; } Rec;
typedef struct {
  char pad0[0x3c];
  Info *info;
  char pad1[8];
  void *h48;
  char pad2[4];
  Rec *recs;
  char buf[0xc0 - 0x54];
} Obj;

void FUN_000e861c(Obj *o);

void FUN_000e8534(Obj *o)
{
  char *p = (char *)o + 0x54;
  int n = 0xc0 - ((int)p - (int)o);
  int i;
  for (i = 0; i < n; i++) {
    *p++ = 0;
  }
  o->buf[4] = 1;
  o->buf[5] = 1;
  {
    int j;
    for (j = 0; j < o->info->count; j++) {
      o->recs[j].b0 = 0;
    }
  }
  FUN_000e861c(o);
}

void FUN_000e861c(Obj *o)
{
  FUN_00051d40(o->h48, 1);
  FUN_00051d9c(o->h48, 1);
  FUN_00051d38(5500.0f, o->h48);
}
