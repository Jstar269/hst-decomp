/* HSTMATCH module=hstp_trans_main.prx start=0x00208628 end=0x00208700 symbol=FUN_00208628 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* prize.cpp (debug build): in game mode 49, when the slot of this object's index is not flagged, asserts
   "pMyPlayer" (FUN_00089f84 on the game global, line 9069), forwards FUN_00209c3c(self) to
   FUN_0025e2b4 and, with the flag at +0x521 set, FUN_0025e324 with DAT_003eac8c. The mode test is a
   one-case switch (retail `beq mode,49,body; b end`; a plain if gives `bne` with the body inline). */
typedef struct {
    unsigned char flag;
    char pad[0x11f];
} Slot;

typedef struct {
    char pad0[0x3cc];
    int idx;
    char pad3d0[0x521 - 0x3d0];
    unsigned char f521;
} Prize;

extern int DAT_003f39a8;
extern Slot DAT_003eabf4[];
extern void *DAT_003e19f0;
extern unsigned char DAT_003eac8c;
extern char DAT_003963d4[];
extern char DAT_00396878[];
extern char DAT_00396428[];
extern void *FUN_00089f84(void *);
extern void FUN_001fbc18(const char *, ...);
extern int FUN_00209c3c(Prize *);
extern void FUN_0025e2b4(void *, int);
extern void FUN_0025e324(void *, int);

#define ASSERT(c, text, line) \
    if (!(c)) { FUN_001fbc18(DAT_003963d4, text, DAT_00396428, line); for (;;) {} }

void FUN_00208628(Prize *self, void *obj)
{
    void *pMyPlayer;

    switch (DAT_003f39a8) {
    case 49:
        if (DAT_003eabf4[self->idx].flag == 0) {
            pMyPlayer = FUN_00089f84(DAT_003e19f0);
            ASSERT(pMyPlayer, DAT_00396878, 9069);
            FUN_0025e2b4(obj, FUN_00209c3c(self));
            if (self->f521 != 0) {
                FUN_0025e324(obj, DAT_003eac8c);
            }
        }
        break;
    }
}
