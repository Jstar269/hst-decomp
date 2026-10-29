/* HSTMATCH module=hstp_trans_main.prx start=0x002a51e0 end=0x002a5278 symbol=FUN_002a51e0 lang=c++ */
/* Clone of src/eboot/initialize_object_if_absent_00293bd4.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Csv {
  virtual ~Csv();
};

extern Csv *DAT_003f3b7c;
extern char DAT_003a8af0;
extern const char DAT_003a8ad8[];
extern "C" void *FUN_00000bcc(int);
extern "C" Csv *FUN_00065884(void *);
extern "C" int FUN_00065ab8(Csv *, const char *, int, void *);

/* Loads the shop item table the first time it is needed; drops it again if the load fails. */
extern "C" void FUN_002a51e0(void)
{
  if (DAT_003f3b7c == 0) {
    Csv *csv = (Csv *)FUN_00000bcc(0x10);
    if (csv != 0)
      csv = FUN_00065884(csv);
    DAT_003f3b7c = csv;

    int loaded = FUN_00065ab8(csv, DAT_003a8ad8, 1, &DAT_003a8af0);
    if (loaded == 0 && DAT_003f3b7c != 0) {
      delete DAT_003f3b7c;
      DAT_003f3b7c = 0;
    }
  }
}
