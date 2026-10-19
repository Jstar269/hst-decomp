/* HSTMATCH module=hstp_trans_main.prx start=0x00123b54 end=0x00123c30 symbol=FUN_00123b54 lang=c99 */
/* Clone of src/eboot/reset_state_and_containers_00118980.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00127ac4(void *);
extern void FUN_00123ecc(void *, void *);
extern void FUN_00123ec4(void *, void *);
extern void FUN_001234d8(void *, int);
extern void FUN_00127e74(void *);
extern void FUN_00123c38(void *, void *);
extern void FUN_00123c30(void *, void *);
extern void FUN_00123480(void *, int);
extern void FUN_0001f054(void *);
#pragma opt_strength_reduction off
typedef struct { char pad[0xb4]; char arr[27]; } Tail;
void FUN_00123b54(char *o)
{
  char a[24];
  char b[24];
  int i;
  Tail *t = (Tail *)o;
  for (i = 0; i < 27; i++)
    t->arr[i] = 0;
  FUN_00127ac4(o + 0x2e0);
  FUN_00123ecc(a, o + 0x2e0);
  FUN_00123ec4(a, o + 0x2e0);
  FUN_001234d8(a, -1);
  FUN_00127e74(o + 0x2f8);
  FUN_00123c38(b, o + 0x2f8);
  FUN_00123c30(b, o + 0x2f8);
  FUN_00123480(b, -1);
  FUN_0001f054(o);
  *(char *)(o + 0x44) = 0;
}
