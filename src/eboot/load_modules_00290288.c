/* HSTMATCH module=EBOOT.BIN start=0x00290288 end=0x002903cc symbol=FUN_00290288 lang=c99 data=0x002ff474 */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode ram-0x00290288.c as a guide): early return for the already-loaded flag, shared fail label placed after the success return, declaration order i, name, id, names, handles for the saved registers; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002ff474-0x002ff4e2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern unsigned char DAT_0034a7f8;
extern int DAT_0034a7fc[];
extern char *DAT_002ff028[];
extern int FUN_00014a58(char *, char *, int);
extern int FUN_002b7cf0(int, int);
extern int FUN_002b7830(char *, int, int);
extern int FUN_002b7820(int, int, int, int, int);
extern void FUN_0028fb44();
extern void FUN_002903cc(void);

int FUN_00290288(void)
{
  unsigned int i;
  char *name;
  int id;
  char **names;
  int *handles;
  int r;
  int s;

  if (DAT_0034a7f8 != 0) {
    return 1;
  }
  i = 0;
  names = DAT_002ff028;
  handles = DAT_0034a7fc;
  do {
    name = *names;
    r = FUN_00014a58(name, "disc0:", 5);
    if (r == 0 && (r = FUN_002b7cf0(0x20, 0), r < 0)) {
      goto fail;
    }
    FUN_0028fb44("LoadModule(): %s\n", name);
    id = FUN_002b7830(name, 0, 0);
    if (id < 0) {
      FUN_0028fb44("ERROR: sceKernelLoadModule(): 0x%08x\n", id);
      goto fail;
    }
    s = FUN_002b7820(id, 0, 0, 0, 0);
    if (s < 0) {
      FUN_0028fb44("ERROR: sceKernelStartModule(): %s 0x%08x\n", name, s);
      goto fail;
    }
    i++;
    *handles = id;
    handles++;
    names++;
  } while (i < 2);
  DAT_0034a7f8 = 1;
  return 1;
fail:
  FUN_002903cc();
  return 0;
}
