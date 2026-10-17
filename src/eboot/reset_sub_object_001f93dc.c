/* HSTMATCH module=EBOOT.BIN start=0x001f93dc end=0x001f94a4 symbol=FUN_001f93dc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Sub {
  char pad[0x10];
  float f10;
  float f14;
  float f18;
  float f1c;
} Sub;

typedef struct Obj {
  char pad[0x564];
  Sub *sub;
  unsigned char f568;
  char pad2[7];
  float f570;
  float f574;
  float f578;
  float f57c;
  float f580;
} Obj;

extern Sub *FUN_00218c00(Sub *);
extern void FUN_00219184(Sub *, int);
extern void FUN_00219210(Sub *);
extern void FUN_00219a50(Sub *, int);
extern void *FUN_00000bcc(unsigned);

void FUN_001f93dc(Obj *o)
{
  int i;
  Sub *mem;
  Sub *s;
  float f5, f6, f7, f8, f9;
  o->f568 = 1;
  o->f580 = 0.0f;
  if (o->sub != 0) {
    if (o->sub != 0) {
      FUN_00219184(o->sub, 1);
      o->sub = 0;
    }
    mem = FUN_00000bcc(0x20);
    if (mem != 0) {
      mem = FUN_00218c00(mem);
    }
    o->sub = mem;
  }
  FUN_00219a50(o->sub, 2);
  f7 = o->f574;
  f5 = o->f580;
  f8 = o->f57c;
  f6 = o->f578;
  s = o->sub;
  i = 0;
  f9 = f7 + f5;
  s->f10 = o->f570;
  s->f14 = f9;
  s->f18 = f6;
  s->f1c = f8;
  do {
    FUN_00219210(o->sub);
    i++;
  } while (i < 10);
}
