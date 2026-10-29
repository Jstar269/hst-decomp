/* HSTMATCH module=EBOOT.BIN start=0x00290b0c end=0x00290c94 symbol=FUN_00290b0c lang=c99 data=0x002ff720 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002ff720-0x002ff7a8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Receive loop: poll FUN_002b78a0 into a request message, handle the 0x800201b4 status (FUN_002b7ee0, retry after FUN_002b7958(PSMF_IDLE_DELAY)) and message types STOP and START; leaves when DAT_0034a80c is set or the closing flag is set. */
#include "hst/psmf_player.h"

extern unsigned char DAT_0034a80c;
extern void FUN_0028fb44();
extern void FUN_002905bc(void *, void *, int, int);
extern void FUN_002908cc(void *);
extern int FUN_002b78a0(int, void *, int, int, void *);
extern void FUN_002b7958(int);
extern void FUN_002b79b0(int);
extern int FUN_002b7ee0(void *);


/* Manager thread body: receives requests from the pipe and dispatches stop and start. */
int FUN_00290b0c(PsmfPlayer *self)
{
    int prev_type = 0;
    PsmfMsg msg;
    int received;
    int r;

    for (;;) {
        if (DAT_0034a80c != 0)
            break;
        r = FUN_002b78a0(self->pipe, &msg, SERVICE_REQUEST_SIZE, 0, &received);
        if (r == (int)0x800201b4) {
            r = FUN_002b7ee0(self);
            if (r < 0) {
                FUN_0028fb44("ERROR: scePsmfPlayerGetCurrentStatus()[1]: 0x%08x\n", r);
            } else if (r == PSMF_STATUS_FINISHED) {
                if (DAT_0034a80c != 0)
                    break;
                FUN_002908cc(self);
            }
            if (self->closing != 0) {
                if (DAT_0034a80c == 0)
                    FUN_002908cc(self);
                break;
            }
            FUN_002b7958(PSMF_IDLE_DELAY);
            continue;
        }
        if (r != 0) {
            FUN_0028fb44("ERROR: sceKernelReceiveMsgPipe(): 0x%08x\n", r);
        } else {
            if (msg.type == PSMF_MSG_START && prev_type != 0) {
                FUN_0028fb44("PsmfPlayerManagerThread: StopRequest()\n");
                FUN_002908cc(self);
            }
            prev_type = msg.type;
            switch (msg.type) {
            case PSMF_MSG_STOP:
                FUN_002908cc(self);
                break;
            case PSMF_MSG_START:
                FUN_002905bc(self, msg.data, msg.arg, 0);
                break;
            }
        }
    }
    FUN_002b79b0(0);
    return 0;
}
