/* HSTMATCH module=EBOOT.BIN start=0x000bab10 end=0x000babb8 symbol=FUN_000bab10 lang=c99 data=0x002d4fe4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d4fe4-0x002d502d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/adhoc_net.h"

extern int FUN_002b7d58(const void *);
extern void FUN_000ba3ac(const char *, ...);
extern AdhocNet *DAT_00338ac4;
extern int FUN_000bda40(AdhocNet *, void *, int, int, int);

/* Connects to the ad-hoc group named in the config; returns 1 on success. */
int FUN_000bab10(AdhocNet *self)
{
    int result = FUN_002b7d58(self->config.groupName);
    if (result < 0) {
        FUN_000ba3ac("sceNetAdhocctlConnect() failed(0x%X)\n", result);
        return 0;
    }
    FUN_000ba3ac("sceNetAdhocctlConnect() success\n");
    self->state = 1;
    switch (self->state) {
    case 4:
    case 8: {
        AdhocNet *net = DAT_00338ac4;
        self->unk17c =
            (unsigned char)FUN_000bda40(net, net->unk38, (unsigned short)self->config.unk0c, 0x5a4, 0);
        break;
    }
    case 10:
        break;
    }
    return 1;
}
