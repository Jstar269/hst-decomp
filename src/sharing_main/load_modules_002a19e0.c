/* HSTMATCH module=hstp_trans_main.prx start=0x002a19e0 end=0x002a1b24 symbol=FUN_002a19e0 lang=c99 data=0x003a8380 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x003a8380-0x003a83ee) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Sharing twin of src/eboot/load_modules_00290288.c (EBOOT 0x290288), the same source with the addresses substituted:
   early return for the already-loaded flag, shared fail label placed after the success return, declaration order
   i, name, id, names, handles for the saved registers. Loads and starts the two PSMF player modules. */
extern unsigned char DAT_003f3b28;
extern int DAT_003f3b2c[];
extern char *DAT_003a7f7c[];
extern int FUN_00014a58(char *, char *, int);
extern int FUN_002c7a88(int, int);
extern int FUN_002c74a0(char *, int, int);
extern int FUN_002c7490(int, int, int, int, int);
extern void FUN_002a130c();
extern void FUN_002a1b24(void);

int FUN_002a19e0(void)
{
  unsigned int i;
  char *name;
  int id;
  char **names;
  int *handles;
  int r;
  int s;

  if (DAT_003f3b28 != 0) {
    return 1;
  }
  i = 0;
  names = DAT_003a7f7c;
  handles = DAT_003f3b2c;
  do {
    name = *names;
    r = FUN_00014a58(name, "disc0:", 5);
    if (r == 0 && (r = FUN_002c7a88(0x20, 0), r < 0)) {
      goto fail;
    }
    FUN_002a130c("LoadModule(): %s\n", name);
    id = FUN_002c74a0(name, 0, 0);
    if (id < 0) {
      FUN_002a130c("ERROR: sceKernelLoadModule(): 0x%08x\n", id);
      goto fail;
    }
    s = FUN_002c7490(id, 0, 0, 0, 0);
    if (s < 0) {
      FUN_002a130c("ERROR: sceKernelStartModule(): %s 0x%08x\n", name, s);
      goto fail;
    }
    i++;
    *handles = id;
    handles++;
    names++;
  } while (i < 2);
  DAT_003f3b28 = 1;
  return 1;
fail:
  FUN_002a1b24();
  return 0;
}
