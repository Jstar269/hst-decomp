/* HSTMATCH module=EBOOT.BIN start=0x00118980 end=0x00118a5c symbol=FUN_00118980 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0011c8f0(void *);
extern void FUN_00118cf8(void *, void *);
extern void FUN_00118cf0(void *, void *);
extern void FUN_00118304(void *, int);
extern void FUN_0011cca0(void *);
extern void FUN_00118a64(void *, void *);
extern void FUN_00118a5c(void *, void *);
extern void FUN_001182ac(void *, int);
extern void FUN_0001f294(void *);
#pragma opt_strength_reduction off
typedef struct { char pad[0xb4]; char arr[27]; } Tail;
void FUN_00118980(char *o)
{
  char a[24];
  char b[24];
  int i;
  Tail *t = (Tail *)o;
  for (i = 0; i < 27; i++)
    t->arr[i] = 0;
  FUN_0011c8f0(o + 0x2e0);
  FUN_00118cf8(a, o + 0x2e0);
  FUN_00118cf0(a, o + 0x2e0);
  FUN_00118304(a, -1);
  FUN_0011cca0(o + 0x2f8);
  FUN_00118a64(b, o + 0x2f8);
  FUN_00118a5c(b, o + 0x2f8);
  FUN_001182ac(b, -1);
  FUN_0001f294(o);
  *(char *)(o + 0x44) = 0;
}
