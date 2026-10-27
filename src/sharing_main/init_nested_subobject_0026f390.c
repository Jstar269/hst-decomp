/* HSTMATCH module=hstp_trans_main.prx start=0x0026f390 end=0x0026f428 symbol=FUN_0026f390 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/init_nested_subobject_0025e568.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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

extern int DAT_003b0a68;
extern int DAT_003a68a0;
extern int DAT_002cc260;
extern void FUN_001017dc(SubObject *);
extern void FUN_00056cac(void *);
extern void FUN_00101748(SubObject *, int *);
extern void FUN_001016c0(void *, int *);

int FUN_0026f390(char *self)
{
  SubObject *sub = (SubObject *)(self + 0x20);

  FUN_001017dc(sub);
  FUN_00056cac((char *)sub + 0x30);
  sub->vtable = (int)&DAT_003b0a68;
  sub->field70 = 0;
  sub->field74 = -1;
  sub->field78 = 0x3f800000;
  sub->field7c = 0x3f800000;
  FUN_00056cac((char *)sub + 0x80);
  sub->fieldc0 = (int)&DAT_003a68a0;
  FUN_00101748(sub, &DAT_002cc260);
  FUN_001016c0(&((SubObjectSecondView *)sub)->field80, &DAT_002cc260);
  return (int)self;
}
