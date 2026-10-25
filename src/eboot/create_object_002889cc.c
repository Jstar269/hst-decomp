/* HSTMATCH module=EBOOT.BIN start=0x002889cc end=0x00288a84 symbol=FUN_002889cc lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: reuse the allocated object pointer as the constructor result; exact match verified; names and types await human review. */
extern void *DAT_0034a114;
extern int DAT_002feae4[];
extern int DAT_002feb08[];
extern int FUN_001c70c0(void *, int);
extern void FUN_00286acc(int *, int, int);
extern int FUN_00000bcc(int);
extern int FUN_0029343c(int);
extern void FUN_00293564(int, int);
extern void FUN_001c6b38(void *, int, int);

void FUN_002889cc(int param_1, int param_2)
{
  int obj;
  int r;

  if (FUN_001c70c0(DAT_0034a114, param_1) != 0) {
    FUN_00286acc(DAT_002feae4, param_1, param_2);
  }
  else {
    FUN_00286acc(DAT_002feb08, param_1, param_2);
    obj = FUN_00000bcc(0x90);
    if (obj != 0) obj = FUN_0029343c(obj);
    r = obj;
    FUN_00293564(r, param_2);
    FUN_001c6b38(DAT_0034a114, param_1, r);
  }
}

