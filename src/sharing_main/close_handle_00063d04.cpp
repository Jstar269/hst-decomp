/* HSTMATCH module=hstp_trans_main.prx start=0x00063d04 end=0x00063dac symbol=FUN_00063d04 lang=c++ */
/* Clone of src/eboot/close_handle_00062e40.cpp (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Closes the handle (when it is not negative), clears the cached handle at +0xc when it still
   matches, then spins up to 30 times calling FUN_00062fd4(30.0f)/FUN_002c7818() until the global
   counter DAT_003daec0 has changed from the value saved on entry. */
struct Obj {
  int pad[2];
  unsigned char f8;
  int fc;
};

extern "C" int DAT_003daec0;
extern "C" void FUN_00077c14(int a, int b);
extern "C" void FUN_00062fd4(float f);
extern "C" void FUN_002c7818();

extern "C" void FUN_00063d04(Obj *self, int handle)
{
  int old = DAT_003daec0;
  if (handle >= 0) {
    FUN_00077c14(handle, 0);
    if (self->f8 != 0 && self->fc == handle) {
      self->fc = -1;
    }
  }
  int i = 0;
  do {
    if (old - 1 == DAT_003daec0) {
      break;
    }
    FUN_00062fd4(30.0f);
    FUN_002c7818();
    i++;
  } while (i < 30);
}
