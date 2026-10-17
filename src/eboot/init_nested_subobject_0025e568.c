/* HSTMATCH module=EBOOT.BIN start=0x0025e568 end=0x0025e600 symbol=FUN_0025e568 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct SubObject {
  int vtable;
  char pad0[0x6c];
  int field70;
  int field74;
  int field78;
  int field7c;
  char pad1[0x40];
  int fieldc0;
} SubObject;

typedef struct SubObjectSecondView {
  char pad[0x80];
  int field80;
} SubObjectSecondView;

extern int DAT_0030779c;
extern int DAT_002fdc90;
extern int DAT_002bc410;
extern void FUN_000fc0a0(SubObject *);
extern void FUN_00056098(void *);
extern void FUN_000fc00c(SubObject *, int *);
extern void FUN_000fbf84(void *, int *);

int FUN_0025e568(char *self)
{
  SubObject *sub = (SubObject *)(self + 0x20);

  FUN_000fc0a0(sub);
  FUN_00056098((char *)sub + 0x30);
  sub->vtable = (int)&DAT_0030779c;
  sub->field70 = 0;
  sub->field74 = -1;
  sub->field78 = 0x3f800000;
  sub->field7c = 0x3f800000;
  FUN_00056098((char *)sub + 0x80);
  sub->fieldc0 = (int)&DAT_002fdc90;
  FUN_000fc00c(sub, &DAT_002bc410);
  FUN_000fbf84(&((SubObjectSecondView *)sub)->field80, &DAT_002bc410);
  return (int)self;
}
