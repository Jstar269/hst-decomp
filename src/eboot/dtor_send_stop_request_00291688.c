/* HSTMATCH module=EBOOT.BIN start=0x00291688 end=0x002917ac symbol=FUN_00291688 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/player_service.h"

#define SEND_RESULT_SPECIAL (-0x7ffdfe4d) /* result that gets its own log message */

extern int DAT_00309db4;
extern ServiceHolder *DAT_0034a818;
extern int DAT_0034a81c;
extern char DAT_002ff534[];
extern char DAT_002ff56c[];
extern char DAT_002ff5a4[];
extern void FUN_0028fb44(const char *, ...);
extern int FUN_002b7988(int, void *, int, int, int *);
extern void FUN_0028ff38(PlayerService *);
extern void FUN_00290ff0(ServiceHolder *, int);
extern void FUN_000510c0(void *, int);
extern void FUN_00000a00(void *);

/* Destructor: sends the stop request if the service is ready, tears down the holder, frees self when delete_flag > 0. */
void *FUN_00291688(void *self, short delete_flag)
{
  if (self != 0) {
    int sent;
    PlayerService *svc;
    *(int **)self = &DAT_00309db4;
    svc = DAT_0034a818->service;
    if (svc->ready == 0) {
      FUN_0028fb44(DAT_002ff534);
    } else {
      int r;
      svc->req_cmd = 0;
      svc->req_flag = 0;
      svc->req_arg = 0;
      r = FUN_002b7988(svc->pipe, &svc->req_cmd, SERVICE_REQUEST_SIZE, 0, &sent);
      if (r == SEND_RESULT_SPECIAL) {
        FUN_0028fb44(DAT_002ff5a4);
      } else if (r != 0 || sent != SERVICE_REQUEST_SIZE) {
        FUN_0028fb44(DAT_002ff56c, r, sent);
      }
    }
    FUN_0028ff38(DAT_0034a818->service);
    FUN_00290ff0(DAT_0034a818, 1);
    DAT_0034a81c = 0;
    FUN_000510c0(self, 0);
    if (delete_flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
