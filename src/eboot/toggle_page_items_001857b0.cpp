/* HSTMATCH module=EBOOT.BIN start=0x001857b0 end=0x00185970 symbol=FUN_001857b0 lang=c++ */
/* Clone of src/sharing_main/toggle_page_items_00191efc.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idioms: `switch (mode) { case 0: .. }` (an `if (mode == 0)` lays out differently); `kind` is assigned at its declaration AND again at the end of case 0: with a single reaching definition MWCC folds the constant into the call arguments, with two it keeps the value in a saved register (retail's `li s3,1` twice, `move a1,s3`); #pragma opt_strength_reduction off keeps `items[idx]` recomputed per pass. */
struct Iface { virtual void s0(); virtual void s1(int); };
struct Cnt { char pad[0x104]; int f104; };
struct Item { void *f0; int f4, f8, fc, f10; };
struct Ctx { char pad[0x5a6]; unsigned char f5a6; };
struct Rec { char pad[0x64]; signed char bf : 4; };
struct Obj {
    char pad0[0x2878];
    Cnt *f2878;
    char pad2878[0xc];
    Cnt *f2888;
    char pad288c[0x1c];
    Iface *f28a8;
    Item *f28ac;
};
extern Rec *DAT_00338b08;
extern "C" Ctx *FUN_0016bc70(void);
extern "C" int FUN_00179348(Ctx *, int, int);
extern "C" Rec *FUN_000d8c24(Rec *, int, int);
extern "C" void FUN_000ffb3c(void *, int);
extern "C" void FUN_001857b0(Obj *self, int mode, int count);
#pragma opt_strength_reduction off

void FUN_001857b0(Obj *self, int mode, int count)
{
    int sel = count - 1;
    Cnt *c7 = 0;
    Item *items = 0;
    int kind = 1;
    if (sel < 0)
        sel = 0;
    switch (mode) {
    case 0: {
        Ctx *ctx = FUN_0016bc70();
        if (ctx->f5a6 != 0) {
            self->f28a8->s1(0);
            items = self->f28ac;
            c7 = self->f2888;
        } else {
            self->f28a8->s1(1);
        }
        kind = 1;
        break;
    }
    }
    if (items != 0) {
        int i = 0;
        int idx = sel << 2;
        do {
            if (self->f2878->f104 <= idx)
                return;
            Item *p = &items[idx];
            if (idx >= c7->f104) {
                FUN_000ffb3c(p->f0, 1);
            } else if (sel == 0 && i == 0) {
                FUN_000ffb3c(p->f0, 1);
            } else {
                int v = FUN_00179348(FUN_0016bc70(), kind, idx);
                Rec *r = FUN_000d8c24(DAT_00338b08, kind, v);
                if (r != 0 && r->bf == 1)
                    FUN_000ffb3c(p->f0, 0);
                else
                    FUN_000ffb3c(p->f0, 1);
            }
            i++;
            idx++;
        } while (i < 20);
    }
}
