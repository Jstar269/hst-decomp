/* HSTMATCH module=EBOOT.BIN start=0x00048fc8 end=0x00049094 symbol=FUN_00048fc8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. */
/* Starts a worker thread for a subsystem: the gate call FUN_00049094(0) is checked first, an sprintf'd name
   goes into the 64-byte stack buffer, FUN_002b7920 (thread create, see thread_create_wrapper_002918f0.cpp)
   gets the entry LAB_00048f64 in the same section, then the thread is started with the 4-byte argument this
   function was given (FUN_002b78d8) and a semaphore is waited on (FUN_002b7928). 0x10000 is the thread
   attribute word retail passes in a3 (it is `lui a3,0x1`, so the value is 65536, not 1).
   Steering trick: the two guards are spelled as the positive nest
   (`if (gate(...) != 0) { ... if (n > 0) { ... return 1; } } return 0;`) — the early-return spellings
   emit an inverted likely branch plus an extra `b`, and the negative wrap points the first branch at the
   wrong zero block. */
extern "C" {
extern char DAT_002d0730;
extern int DAT_002d0734;
extern int DAT_002d0738;
extern char DAT_00311140;
extern int DAT_00311144;
extern char DAT_002d073c[];
extern char DAT_002d074c[];
extern void LAB_00048f64();
extern int FUN_00049094(int);
extern int FUN_000143b0(char *, const char *, ...);
extern int FUN_002b7920(void *, void *, int, int, int, int);
extern int FUN_002b78d8(int, int, void *);
extern int FUN_002b7928(int, int, int);
}

extern "C" int FUN_00048fc8(char *self, int arg)
{
  char buf[64];
  if (FUN_00049094(0) != 0) {
    FUN_000143b0(buf, DAT_002d073c, DAT_002d074c, 115);
    int n = FUN_002b7920(buf, (void *)&LAB_00048f64, 111, 0x10000, 16384, 0);
    if (n > 0) {
      DAT_002d0738 = n;
      DAT_00311140 = 1;
      DAT_002d0730 = 0;
      DAT_00311144 = (int)self;
      FUN_002b78d8(n, 4, &arg);
      FUN_002b7928(DAT_002d0734, 1, 0);
      return 1;
    }
  }
  return 0;
}
