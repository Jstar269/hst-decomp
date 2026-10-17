/* HSTMATCH module=hstp_trans_main.prx start=0x0013b72c end=0x0013b82c symbol=FUN_0013b72c lang=c99 */
/* Clone of src/eboot/FUN_00130174.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
extern char DAT_003822a0[]; extern char DAT_003822b0[]; extern char DAT_003822bc[]; extern char DAT_003822c8; extern char DAT_003822d0[]; extern char DAT_003822e0[]; extern char DAT_003822e8[];
extern int FUN_00014d64(const char *, const char *);
int FUN_0013b72c(undefined4 unused, const char *name) {
  int result = 0;
  if (name == 0) {
    result = 0;
  } else {
    if (FUN_00014d64(name,DAT_003822a0) != 0) result = 1;
    else if (FUN_00014d64(name,DAT_003822b0) != 0) result = 2;
    else if (FUN_00014d64(name,DAT_003822bc) != 0) result = 3;
    else if (FUN_00014d64(name,&DAT_003822c8) != 0) result = 5;
    else if (FUN_00014d64(name,DAT_003822d0) != 0) result = 4;
    else if (FUN_00014d64(name,DAT_003822e0) != 0) result = 6;
    else if (FUN_00014d64(name,DAT_003822e8) != 0) result = 7;
  }
  return result;
}
