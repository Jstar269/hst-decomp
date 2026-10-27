/* HSTMATCH module=hstp_trans_main.prx start=0x000c3fcc end=0x000c41fc symbol=FUN_000c3fcc lang=c++ data=0x0037c2dc */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x0037c2dc-0x0037c320) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Per-frame network state handler: switch on the state import (0x2c7a10); in state 3 it checks the second import (0x2c7a30, result passed on to the debug print stub), mirrors the status word, and unless the current mode is 3 or 4 finishes the front record of the 0x50-byte record vector at +0x770 (copy its payload, or pick a status code, release its buffers, erase it) before the final unsigned-compare status check. Matching idioms: the discarded iterator goes through an inline erase(RecIter) that copies its by-value parameter (that is what gives retail's lwc1/swc1 slot copy of the 4-byte iterator), and the 64-bit field at +0x788 is what the second debug print passes in a2:a3. Names provisional. */
struct Tag {};
struct Rec {
    char pad0[0x40];
    char *buf;
    char *data;
    int size;
    int off;
};
struct RecIter {
    Rec *p;
};
struct RecVec;
extern "C" void FUN_000c4d90(RecVec *, RecIter, Tag);
struct RecVec {
    Rec *first;
    unsigned count;
    RecIter begin() { RecIter it; it.p = first; return it; }
    void erase(RecIter pos) { RecIter q = pos; FUN_000c4d90(this, q, Tag()); }
};
struct HdrA { char pad[8]; unsigned f8; };
struct HdrB { char pad[4]; unsigned f4; };
struct Obj {
    char pad0[0x3c];
    int f3c;
    int f40;
    char pad1[0x90 - 0x44];
    unsigned char f90;
    char pad2[0xb0 - 0x91];
    int fb0;
    char pad3[0x110 - 0xb4];
    int f110;
    char pad4[0x664 - 0x114];
    HdrA *f664;
    char pad5[0x66c - 0x668];
    HdrB *f66c;
    char pad6[0x770 - 0x670];
    RecVec vec;
    char pad7[0x788 - 0x778];
    long long f788;
};
extern unsigned char DAT_003e1e0c;
extern int DAT_003e1e10;
extern "C" {
int FUN_002c7a10(void);
int FUN_002c7a30(void);
void FUN_000c41fc(...);
void FUN_000c4a80(Obj *);
void *FUN_00011090(void *, const void *, unsigned);
}
extern "C" void FUN_000c3fcc(Obj *self)
{
    switch (FUN_002c7a10()) {
    case 0:
        FUN_000c4a80(self);
        break;
    case 1:
        break;
    case 2:
        DAT_003e1e0c = 1;
        break;
    case 3: {
        DAT_003e1e0c = 0;
        int err = FUN_002c7a30();
        if (err != 0) {
            FUN_000c41fc("sceUtilitySavedataShutdownStart Error : %x\n", err);
            break;
        }
        DAT_003e1e10 = self->fb0;
        int mode = self->f40;
        if (mode != 3 && mode != 4) {
            Rec *r = self->vec.first;
            if (r->data != 0) {
                if (self->f110 == r->size || self->f90 == 0) {
                    if (self->f3c != 5 && DAT_003e1e10 == 0)
                        FUN_00011090(r->buf, r->data, r->size);
                    if (self->f3c == 5) {
                        self->f788 = *(long long *)(self->vec.first->data + self->vec.first->off);
                        FUN_000c41fc("MsLib: rtc.tick = %lld\n", self->f788);
                    }
                } else {
                    if (mode == 2)
                        DAT_003e1e10 = 0x80110306;
                    else
                        DAT_003e1e10 = 0x80110326;
                }
                if (self->vec.first->data != 0) {
                    delete[] self->vec.first->data;
                    self->vec.first->data = 0;
                }
            } else {
                if (r->buf != 0) {
                    delete[] r->buf;
                    self->vec.first->buf = 0;
                }
            }
            self->vec.erase(self->vec.begin());
        }
        if (DAT_003e1e10 == 0 && self->f3c == 0 && self->f664->f8 < self->f66c->f4)
            DAT_003e1e10 = 0x80110383;
        break;
    }
    case 4:
        break;
    }
}
