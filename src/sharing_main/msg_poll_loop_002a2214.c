/* HSTMATCH module=hstp_trans_main.prx start=0x002a2214 end=0x002a239c symbol=FUN_002a2214 lang=c99 data=0x003a862c */
/* Clone of src/eboot/msg_poll_loop_00290b0c.c (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003a862c-0x003a86b4) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Receive loop: poll FUN_002c7640 into a 0x48-byte message, handle the 0x800201b4 status (FUN_002c7c60, retry after FUN_002c76f8(33000)) and message types 0 and 1; leaves when DAT_003f3b3c is set or the closing flag at +0x2a is set. */
extern unsigned char DAT_003f3b3c;
extern void FUN_002a130c();
extern void FUN_002a1d14(void *, void *, int, int);
extern void FUN_002a2024(void *);
extern int FUN_002c7640(int, void *, int, int, void *);
extern void FUN_002c76f8(int);
extern void FUN_002c7750(int);
extern int FUN_002c7c60(void *);

struct Msg {
    int type;
    int arg;
    char data[64];
};
struct Obj {
    char pad0[0x2a];
    unsigned char closing;
    char pad1[0x88 - 0x2b];
    int handle;
};

int FUN_002a2214(struct Obj *self)
{
    int prev = 0;
    struct Msg msg;
    int extra;
    int r;

    for (;;) {
        if (DAT_003f3b3c != 0)
            break;
        r = FUN_002c7640(self->handle, &msg, 0x48, 0, &extra);
        if (r == (int)0x800201b4) {
            r = FUN_002c7c60(self);
            if (r < 0) {
                FUN_002a130c("ERROR: scePsmfPlayerGetCurrentStatus()[1]: 0x%08x\n", r);
            } else if (r == 0x200) {
                if (DAT_003f3b3c != 0)
                    break;
                FUN_002a2024(self);
            }
            if (self->closing != 0) {
                if (DAT_003f3b3c == 0)
                    FUN_002a2024(self);
                break;
            }
            FUN_002c76f8(33000);
            continue;
        }
        if (r != 0) {
            FUN_002a130c("ERROR: sceKernelReceiveMsgPipe(): 0x%08x\n", r);
        } else {
            if (msg.type == 1 && prev != 0) {
                FUN_002a130c("PsmfPlayerManagerThread: StopRequest()\n");
                FUN_002a2024(self);
            }
            prev = msg.type;
            switch (msg.type) {
            case 0:
                FUN_002a2024(self);
                break;
            case 1:
                FUN_002a1d14(self, msg.data, msg.arg, 0);
                break;
            }
        }
    }
    FUN_002c7750(0);
    return 0;
}
