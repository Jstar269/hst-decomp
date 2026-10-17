/* HSTMATCH module=hstp_trans_main.prx start=0x001dbf18 end=0x001dbf68 symbol=FUN_001dbf18 lang=c++ */
/* Clone of src/eboot/counter_step_001cd83c.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned int undefined4;

struct Obj {
  int f0;
  int f4;
  int f8;
  int fc;
  int f10;
};

extern "C" void FUN_001dcf40(Obj *, int);

extern "C" void FUN_001dbf18(Obj *o)
{
  if (o->f4 != o->f10) {
    int c = o->fc - 1;
    o->fc = c;
    if (c < 1) {
      FUN_001dcf40(o, o->f10);
      return;
    }
  }
  o->f8 = o->f8 + 1;
}
