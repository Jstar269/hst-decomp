/* HSTMATCH module=EBOOT.BIN start=0x0012fdb0 end=0x0012ffac symbol=FUN_0012fdb0 lang=c99 */
/* Hand-written reconstruction from the disassembly (replaces the fm9 nested Ghidra draft with a flat else-if chain); matching idiom: the null-name arm assigns r = 0 explicitly (a bare early return folds to move v0,zero instead of retail's move v0,s0); exact match verified; names and types await human review. */
extern char DAT_002daf5c[];
extern char DAT_002daf68[];
extern char DAT_002daf74[];
extern char DAT_002daf84[];
extern char DAT_002daf90[];
extern char DAT_002daf9c[];
extern char DAT_002dafa8[];
extern char DAT_002dafb4[];
extern char DAT_002dafc0[];
extern char DAT_002dafd0[];
extern char DAT_002dafe0[];
extern char DAT_002dafe8[];
extern char DAT_002daff4[];
extern char DAT_002db004[];
extern char DAT_002db014[];
extern char DAT_002db01c[];
extern int FUN_00014d64(const char *, const char *);

int FUN_0012fdb0(void *self, const char *name)
{
  int r = 0;

  if (name == 0) {
    r = 0;
  } else {
    if (FUN_00014d64(name, DAT_002daf5c) != 0) {
      r = 0;
    }
    else if (FUN_00014d64(name, DAT_002daf68) != 0) {
      r = 1;
    }
    else if (FUN_00014d64(name, DAT_002daf74) != 0) {
      r = 2;
    }
    else if (FUN_00014d64(name, DAT_002daf84) != 0) {
      r = 3;
    }
    else if (FUN_00014d64(name, DAT_002daf90) != 0) {
      r = 4;
    }
    else if (FUN_00014d64(name, DAT_002daf9c) != 0) {
      r = 5;
    }
    else if (FUN_00014d64(name, DAT_002dafa8) != 0) {
      r = 6;
    }
    else if (FUN_00014d64(name, DAT_002dafb4) != 0) {
      r = 7;
    }
    else if (FUN_00014d64(name, DAT_002dafc0) != 0) {
      r = 8;
    }
    else if (FUN_00014d64(name, DAT_002dafd0) != 0) {
      r = 9;
    }
    else if (FUN_00014d64(name, DAT_002dafe0) != 0) {
      r = 10;
    }
    else if (FUN_00014d64(name, DAT_002dafe8) != 0) {
      r = 11;
    }
    else if (FUN_00014d64(name, DAT_002daff4) != 0) {
      r = 12;
    }
    else if (FUN_00014d64(name, DAT_002db004) != 0) {
      r = 13;
    }
    else if (FUN_00014d64(name, DAT_002db014) != 0) {
      r = 14;
    }
    else if (FUN_00014d64(name, DAT_002db01c) != 0) {
      r = 15;
    }
  }
  return r;
}
