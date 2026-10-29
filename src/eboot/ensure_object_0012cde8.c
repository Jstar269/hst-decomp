/* HSTMATCH module=EBOOT.BIN start=0x0012cde8 end=0x0012ce50 symbol=FUN_0012cde8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Size of the object created when none exists yet. */
#define OBJECT_SIZE 0x250

extern int DAT_0033b580; /* the existing instance, or 0 */
extern int DAT_0034a114; /* game host */
extern int FUN_00000bcc(int);
extern int *FUN_0012dc4c(int *);
extern void FUN_0012d890(int);
extern void FUN_00145cfc(void);
extern void FUN_001c68a8(int, int *);

/* Creates the object and registers it with the host when none exists, then runs the common setup. */
void FUN_0012cde8(int arg)
{
  int *obj;
  FUN_00145cfc();
  if (DAT_0033b580 == 0) {
    obj = (int *)FUN_00000bcc(OBJECT_SIZE);
    if (obj != 0)
      obj = FUN_0012dc4c(obj);
    FUN_001c68a8(DAT_0034a114, obj);
  }
  FUN_0012d890(arg);
}
