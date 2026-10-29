/* HSTMATCH module=EBOOT.BIN start=0x0015b6a4 end=0x0015b958 symbol=FUN_0015b6a4 lang=c++ rodata=0x2c1cf8 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: `if (flag != 0) { else-call } else { switch }` puts the else call first like retail, member-array delete loop indexed as self->slot[i] (self-based walker with displacement), delete on a virtual-destructor pointee for the null-check chain, rodata=0x2c1cf8 is the 12-entry jump table; names and types await human review. */
#include "hst/panel_host.h"

/* Object with a virtual destructor. */
struct VC {
    virtual ~VC();
};
extern char DAT_002de254[];
extern int DAT_00340404;
extern "C" {
void FUN_00000020(void *);
void FUN_00000028();
void FUN_0015a2b0(PanelHost *, int);
void FUN_0015b958(PanelHost *, int);
void FUN_0015ba80(PanelHost *, int);
void FUN_0015bc5c(PanelHost *, int);
void FUN_0015be74(PanelHost *, int, int);
void FUN_0015c078(PanelHost *, int);
void FUN_0015c1a0(PanelHost *, int);
void FUN_0015c2c8(PanelHost *, int, int);
void FUN_0015c4e0(PanelHost *, int);
void FUN_0015c854(PanelHost *, int);
void FUN_0015cbc4(int, int *, int *);
void FUN_0015d184(PanelHost *, int);
}

/* Sets the panel up for message `id`: deletes the owned widgets and slot objects, asks FUN_0015cbc4 for the
   message kind and value, runs the per-kind loader (or the direct loader when flag is set), then sets the
   countdown and the two state fields. */
extern "C" void FUN_0015b6a4(PanelHost *self, int id, int flag, int extra)
{
    FUN_00000020(DAT_002de254);
    DAT_00340404 = id;
    if (self->widgetA != 0) {
        delete (VC *)self->widgetA;
        self->widgetA = 0;
    }
    if (self->widgetB != 0) {
        delete (VC *)self->widgetB;
        self->widgetB = 0;
    }
    int i = 0;
    do {
        if (self->slot[i] != 0) {
            delete (VC *)self->slot[i];
            self->slot[i] = 0;
        }
        i++;
    } while (i < PANEL_HOST_SLOTS);
    self->node[0] = 0;
    self->node[1] = 0;
    int kind = 0;
    int v = 0;
    FUN_0015cbc4(id, &kind, &v);
    if (flag != 0) {
        FUN_0015c4e0(self, id);
    } else {
        switch (kind) {
        case 0:
            FUN_0015b958(self, v);
            break;
        case 1:
            FUN_0015bc5c(self, v);
            break;
        case 2:
            FUN_0015be74(self, v, 0);
            break;
        case 3:
            FUN_0015c078(self, v);
            break;
        case 4:
            FUN_0015c1a0(self, v);
            break;
        case 6:
            FUN_0015c2c8(self, v, extra);
            break;
        case 7:
            FUN_0015c854(self, v);
            break;
        case 10:
            FUN_0015ba80(self, v);
            break;
        case 11:
            FUN_0015be74(self, v, 1);
            break;
        }
    }
    if (kind == 6 || (flag != 0 && id == 1) || (kind == 7 && v == 7)) {
        FUN_0015a2b0(self, 2);
        self->unk18 = 0;
        self->unk1c = 1;
        self->countdown = 0x5a;
    } else {
        FUN_0015a2b0(self, 2);
        self->unk18 = 0;
        self->unk1c = 0;
        self->countdown = 1;
    }
    if (flag == 0 && extra != 0) {
        FUN_0015d184(self, id);
    }
    FUN_00000028();
}
