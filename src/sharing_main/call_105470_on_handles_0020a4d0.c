/* HSTMATCH module=hstp_trans_main.prx start=0x0020a4d0 end=0x0020a5d4 symbol=FUN_0020a4d0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Twin of EBOOT 0x1fbdb8. Sets the bit-0 flag of six handles through FUN_00105470 (the handle setter the
   neighbouring 0x20a5d4 also calls): all four first handles on while the global config byte +0x4c is set,
   otherwise handles 0-1 off and 2-5 on for mode 0, the reverse for any other mode. Names provisional. */
typedef struct Cfg {
  char pad[0x4c];
  unsigned char f4c;
} Cfg;

typedef struct Obj {
  char pad[0x58];
  void *h0;
  void *h1;
  void *h2;
  void *h3;
  void *h4;
  void *h5;
} Obj;

extern Cfg *DAT_003e19f0;
extern void FUN_00105470(void *, int);

void FUN_0020a4d0(Obj *o, int mode)
{
  if (DAT_003e19f0->f4c) {
    FUN_00105470(o->h0, 1);
    FUN_00105470(o->h1, 1);
    FUN_00105470(o->h2, 1);
    FUN_00105470(o->h3, 1);
  } else if (mode == 0) {
    FUN_00105470(o->h0, 0);
    FUN_00105470(o->h1, 0);
    FUN_00105470(o->h2, 1);
    FUN_00105470(o->h3, 1);
    FUN_00105470(o->h4, 1);
    FUN_00105470(o->h5, 1);
  } else {
    FUN_00105470(o->h0, 1);
    FUN_00105470(o->h1, 1);
    FUN_00105470(o->h2, 0);
    FUN_00105470(o->h3, 0);
    FUN_00105470(o->h4, 0);
    FUN_00105470(o->h5, 0);
  }
}
