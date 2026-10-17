/* HSTMATCH module=hstp_trans_main.prx start=0x0020a5d4 end=0x0020a63c symbol=FUN_0020a5d4 lang=c99 */
/* Clone of src/eboot/call_ffb3c_on_four_handles_001fbebc.c (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad[0x58];
  void *h0;
  void *h1;
  void *h2;
  void *h3;
} Obj;

extern int FUN_00048984();
extern void FUN_00105470(void *, int);
extern void FUN_00108a2c(Obj *);

void FUN_0020a5d4(Obj *o)
{
  if (FUN_00048984() != 0) {
    FUN_00105470(o->h0, 1);
    FUN_00105470(o->h1, 1);
    FUN_00105470(o->h2, 1);
    FUN_00105470(o->h3, 1);
  }
  FUN_00108a2c(o);
}
