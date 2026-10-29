/* HSTMATCH module=hstp_trans_main.prx start=0x0013b368 end=0x0013b564 symbol=FUN_0013b368 lang=c99 */
/* Clone of src/eboot/name_to_index_0012fdb0.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (replaces the fm9 nested Ghidra draft with a flat else-if chain); matching idiom: the null-name arm assigns r = 0 explicitly (a bare early return folds to move v0,zero instead of retail's move v0,s0); exact match verified; names and types await human review. */
extern char DAT_00382168[];
extern char DAT_00382174[];
extern char DAT_00382180[];
extern char DAT_00382190[];
extern char DAT_0038219c[];
extern char DAT_003821a8[];
extern char DAT_003821b4[];
extern char DAT_003821c0[];
extern char DAT_003821cc[];
extern char DAT_003821dc[];
extern char DAT_003821ec[];
extern char DAT_003821f4[];
extern char DAT_00382200[];
extern char DAT_00382210[];
extern char DAT_00382220[];
extern char DAT_00382228[];
extern int FUN_00014d64(const char *, const char *);

int FUN_0013b368(void *self, const char *name)
{
  int r = 0;

  if (name == 0) {
    r = 0;
  } else {
    if (FUN_00014d64(name, DAT_00382168) != 0) {
      r = 0;
    }
    else if (FUN_00014d64(name, DAT_00382174) != 0) {
      r = 1;
    }
    else if (FUN_00014d64(name, DAT_00382180) != 0) {
      r = 2;
    }
    else if (FUN_00014d64(name, DAT_00382190) != 0) {
      r = 3;
    }
    else if (FUN_00014d64(name, DAT_0038219c) != 0) {
      r = 4;
    }
    else if (FUN_00014d64(name, DAT_003821a8) != 0) {
      r = 5;
    }
    else if (FUN_00014d64(name, DAT_003821b4) != 0) {
      r = 6;
    }
    else if (FUN_00014d64(name, DAT_003821c0) != 0) {
      r = 7;
    }
    else if (FUN_00014d64(name, DAT_003821cc) != 0) {
      r = 8;
    }
    else if (FUN_00014d64(name, DAT_003821dc) != 0) {
      r = 9;
    }
    else if (FUN_00014d64(name, DAT_003821ec) != 0) {
      r = 10;
    }
    else if (FUN_00014d64(name, DAT_003821f4) != 0) {
      r = 11;
    }
    else if (FUN_00014d64(name, DAT_00382200) != 0) {
      r = 12;
    }
    else if (FUN_00014d64(name, DAT_00382210) != 0) {
      r = 13;
    }
    else if (FUN_00014d64(name, DAT_00382220) != 0) {
      r = 14;
    }
    else if (FUN_00014d64(name, DAT_00382228) != 0) {
      r = 15;
    }
  }
  return r;
}
