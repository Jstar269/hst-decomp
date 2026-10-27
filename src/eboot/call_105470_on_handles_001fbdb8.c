/* HSTMATCH module=EBOOT.BIN start=0x001fbdb8 end=0x001fbebc symbol=FUN_001fbdb8 lang=c99 */
/* Clone of src/sharing_main/call_105470_on_handles_0020a4d0.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Twin of EBOOT 0x1fbdb8. Sets the bit-0 flag of six handles through FUN_000ffb3c (the handle setter the
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

extern Cfg *DAT_003386b0;
extern void FUN_000ffb3c(void *, int);

void FUN_001fbdb8(Obj *o, int mode)
{
  if (DAT_003386b0->f4c) {
    FUN_000ffb3c(o->h0, 1);
    FUN_000ffb3c(o->h1, 1);
    FUN_000ffb3c(o->h2, 1);
    FUN_000ffb3c(o->h3, 1);
  } else if (mode == 0) {
    FUN_000ffb3c(o->h0, 0);
    FUN_000ffb3c(o->h1, 0);
    FUN_000ffb3c(o->h2, 1);
    FUN_000ffb3c(o->h3, 1);
    FUN_000ffb3c(o->h4, 1);
    FUN_000ffb3c(o->h5, 1);
  } else {
    FUN_000ffb3c(o->h0, 1);
    FUN_000ffb3c(o->h1, 1);
    FUN_000ffb3c(o->h2, 0);
    FUN_000ffb3c(o->h3, 0);
    FUN_000ffb3c(o->h4, 0);
    FUN_000ffb3c(o->h5, 0);
  }
}
