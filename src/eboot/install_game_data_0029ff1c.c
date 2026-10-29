/* HSTMATCH module=EBOOT.BIN start=0x0029ff1c end=0x002a0058 symbol=FUN_0029ff1c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass the saved status as the variadic error argument. */
#include "hst/types.h"

/* Install job as seen by the worker thread (the thread argument points at a pointer to it). */
typedef struct InstallJobView {
  char pad00[8];
  u32 unk8;         /* 0x08 */
  char pad0c[0x20 - 0xc];
  int result;       /* 0x20: negative on failure, -1 once a failure was reported */
} InstallJobView;

extern char DAT_002cbdc0[];
extern char DAT_002cbe10[];
extern char DAT_002cbe1c[];
extern char DAT_002cbe28[];
extern char DAT_002cbe74[];
extern char DAT_002cbebc[];
extern char DAT_002cbec8[];
extern char DAT_002cbf18[];
extern char DAT_002cbf60[];
extern char DAT_002cbf6c[];
extern u32 FUN_000fe448();
extern int FUN_00296d60();
extern int FUN_00296ff8();
extern int FUN_002973a4();
extern void FUN_0029e3cc(const char *, ...);
extern int FUN_002b79b0();

/* Worker thread body: runs the install steps, logs the outcome and exits. */
u32 FUN_0029ff1c(u32 arg_size,InstallJobView **argp)
{
  int ret;
  int status;
  InstallJobView *job;
  
  job = *argp;
  ret = FUN_000fe448(DAT_002cbf6c,DAT_002cbf60,
                       job->unk8,0x218000);
  if (ret < 0) {
    FUN_0029e3cc(DAT_002cbf18,job->result);
    job->result = -1;
  }
  else {
    status = FUN_00296d60();
    job->result = status;
    if (status < 0) {
      FUN_0029e3cc(DAT_002cbec8,status);
      goto report_result;
    }
    ret = FUN_002973a4(DAT_002cbebc,job->unk8,ret);
    job->result = ret;
    if (ret < 0) {
      FUN_0029e3cc(DAT_002cbe74,ret);
    }
    else {
      ret = FUN_00296ff8();
      job->result = ret;
      if (ret < 0) {
        FUN_0029e3cc(DAT_002cbe28,ret);
      }
    }
  }
report_result:
  ret = job->result;
  if (ret >= 0) {
    FUN_0029e3cc(DAT_002cbe1c);
  } else {
    FUN_0029e3cc(DAT_002cbe10,ret);
  }
  ret = FUN_002b79b0(0);
  if (ret < 0) {
    FUN_0029e3cc(DAT_002cbdc0,ret);
  }
  return 0;
}
