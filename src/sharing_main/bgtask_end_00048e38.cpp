/* HSTMATCH module=hstp_trans_main.prx start=0x00048e38 end=0x00048fb8 symbol=FUN_00048e38 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* bgtask.cpp: end the background task once. While it runs: with wait set, flush (0x516a0), signal 0x375e84 and
   wait on both semaphores (each "ret >= 0" asserted, lines 162/165/168); without it, poll 0x375e8c and give up
   (return 0) when the poll fails. Then 0x2c7748 on the task id (0 on failure), id = -1, finished flag = 1.
   The 0x2c76xx callees are firmware stubs (semaphore signal/wait/poll as their argument shapes suggest). */
extern "C" {
void FUN_00048d18(...);
void FUN_000516a0(void *, int);
int FUN_002c76b0(int sema, int signal);
int FUN_002c76c8(int sema, int signal, void *timeout);
int FUN_002c76e0(int sema, int signal);
int FUN_002c7748(int thid);
extern unsigned char DAT_00375e88; /* finished */
extern unsigned char DAT_003ba480; /* running */
extern int DAT_00375e84;
extern int DAT_00375e8c;
extern int DAT_00375e90;
extern char DAT_003ba4b0[];
extern char DAT_00375e94[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_00375ec0[]; /* "ret >= 0" */
extern char DAT_00375ecc[]; /* "bgtask.cpp" */
}

extern "C" int FUN_00048e38(int wait)
{
  if (DAT_00375e88) {
    return 1;
  }
  if (DAT_003ba480) {
    if (wait) {
      int ret;
      FUN_000516a0(DAT_003ba4b0, 0);
      ret = FUN_002c76b0(DAT_00375e84, 1);
      if (!(ret >= 0)) {
        FUN_00048d18(DAT_00375e94, DAT_00375ec0, DAT_00375ecc, 162);
        for (;;) {
        }
      }
      ret = FUN_002c76c8(DAT_00375e8c, 1, 0);
      if (!(ret >= 0)) {
        FUN_00048d18(DAT_00375e94, DAT_00375ec0, DAT_00375ecc, 165);
        for (;;) {
        }
      }
      ret = FUN_002c76c8(DAT_00375e84, 1, 0);
      if (!(ret >= 0)) {
        FUN_00048d18(DAT_00375e94, DAT_00375ec0, DAT_00375ecc, 168);
        for (;;) {
        }
      }
    } else {
      int sema = DAT_00375e8c;
      sema = FUN_002c76e0(sema, 1) == 0 ? sema : -1;
      if (DAT_00375e8c != sema) {
        return 0;
      }
    }
    DAT_003ba480 = 0;
  }
  if (FUN_002c7748(DAT_00375e90) != 0) {
    return 0;
  }
  DAT_00375e90 = -1;
  DAT_00375e88 = 1;
  return 1;
}
