/* HSTMATCH module=EBOOT.BIN start=0x00195b08 end=0x00195b90 symbol=FUN_00195b08 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034174c;
extern int DAT_003070bc;
extern char DAT_002e15b0[];
extern char DAT_002e15d4[];
extern void *FUN_00000bcc(int size);
extern void FUN_000649c0(void *obj);
extern void FUN_000651b8(void *obj, char *name, int a, int b, char *c);
extern void FUN_0008c230(void *p);

void FUN_00195b08(void)
{
  int obj;

  if (DAT_0034174c == 0) {
    if ((obj = (int)FUN_00000bcc(0x30)) != 0) {
      FUN_000649c0((void *)obj);
      *(int *)obj = (int)&DAT_003070bc;
      FUN_0008c230((void *)(obj + 0x10));
      FUN_0008c230((void *)(obj + 0x20));
    }
    DAT_0034174c = obj;
    FUN_000651b8((void *)obj, DAT_002e15b0, 0, 0, DAT_002e15d4);
  }
}
