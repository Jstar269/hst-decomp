/* HSTMATCH module=EBOOT.BIN start=0x00290b0c end=0x00290c94 symbol=FUN_00290b0c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Receive loop: poll FUN_002b78a0 into a 0x48-byte message, handle the 0x800201b4 status (FUN_002b7ee0, retry after FUN_002b7958(33000)) and message types 0 and 1; leaves when DAT_0034a80c is set or the closing flag at +0x2a is set. */
extern unsigned char DAT_0034a80c;
extern char DAT_002ff720[];
extern char DAT_002ff754[];
extern char DAT_002ff780[];
extern void FUN_0028fb44();
extern void FUN_002905bc(void *, void *, int, int);
extern void FUN_002908cc(void *);
extern int FUN_002b78a0(int, void *, int, int, void *);
extern void FUN_002b7958(int);
extern void FUN_002b79b0(int);
extern int FUN_002b7ee0(void *);

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

int FUN_00290b0c(struct Obj *self)
{
    int prev = 0;
    struct Msg msg;
    int extra;
    int r;

    for (;;) {
        if (DAT_0034a80c != 0)
            break;
        r = FUN_002b78a0(self->handle, &msg, 0x48, 0, &extra);
        if (r == (int)0x800201b4) {
            r = FUN_002b7ee0(self);
            if (r < 0) {
                FUN_0028fb44(DAT_002ff720, r);
            } else if (r == 0x200) {
                if (DAT_0034a80c != 0)
                    break;
                FUN_002908cc(self);
            }
            if (self->closing != 0) {
                if (DAT_0034a80c == 0)
                    FUN_002908cc(self);
                break;
            }
            FUN_002b7958(33000);
            continue;
        }
        if (r != 0) {
            FUN_0028fb44(DAT_002ff754, r);
        } else {
            if (msg.type == 1 && prev != 0) {
                FUN_0028fb44(DAT_002ff780);
                FUN_002908cc(self);
            }
            prev = msg.type;
            switch (msg.type) {
            case 0:
                FUN_002908cc(self);
                break;
            case 1:
                FUN_002905bc(self, msg.data, msg.arg, 0);
                break;
            }
        }
    }
    FUN_002b79b0(0);
    return 0;
}
