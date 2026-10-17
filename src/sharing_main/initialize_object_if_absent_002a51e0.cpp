/* HSTMATCH module=hstp_trans_main.prx start=0x002a51e0 end=0x002a5278 symbol=FUN_002a51e0 lang=c++ */
/* Clone of src/eboot/initialize_object_if_absent_00293bd4.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VirtualObject {
  virtual void setMode(int);
};

extern int *DAT_003f3b7c;
extern char DAT_003a8af0;
extern const char DAT_003a8ad8[];
extern "C" void *FUN_00000bcc(int);
extern "C" int *FUN_00065884(void *);
extern "C" int FUN_00065ab8(int *, const char *, int, void *);

extern "C" void FUN_002a51e0(void)
{
  if (DAT_003f3b7c == 0) {
    int *object = (int *)FUN_00000bcc(0x10);
    if (object != 0)
      object = FUN_00065884(object);
    DAT_003f3b7c = object;

    int result = FUN_00065ab8(object, DAT_003a8ad8, 1, &DAT_003a8af0);
    if (result == 0 && DAT_003f3b7c != 0) {
      if (DAT_003f3b7c != 0)
        ((VirtualObject *)DAT_003f3b7c)->setMode(1);
      DAT_003f3b7c = 0;
    }
  }
}
