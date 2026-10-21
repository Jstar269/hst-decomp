/* HSTMATCH module=EBOOT.BIN start=0x002528ac end=0x00252c84 symbol=FUN_002528ac lang=c++ rodata=0x2ca68c */
struct Owner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[0x2f8 - 4];
    int f2f8;
    int f2fc;
    char pad1[0x350 - 0x300];
    int **f350;
};
extern int DAT_0034179c;
extern unsigned int DAT_00310fc8;
extern int DAT_0034a788;
extern unsigned char DAT_002fbef9;
extern "C" {
int FUN_001b1f7c(int *);
void FUN_001b1f84(int *, int *);
void FUN_001b3ea4(float, int *);
void FUN_0024e6cc(int, int, int);
int FUN_001b2bb8(int *, int);
}

struct Fx {
    Owner *owner;
    int state;
    int cnt;
    int handle;
    void SetState(int s)
    {
        state = s;
        switch (state) {
        case 0:
            owner->v1();
            break;
        case 1:
            owner->v1();
            break;
        case 2:
        case 4:
            cnt = 9;
            break;
        case 3:
            break;
        }
    }
};

extern "C" void FUN_002528ac(Fx *self)
{
    int st = self->state;
    switch (st) {
    case 2: {
            int c = self->cnt - 1;
            self->cnt = c;
            if (c <= 0) {
                if (self->handle >= 0) {
                    if (FUN_001b1f7c(&DAT_0034179c) != 0) {
                        return;
                    }
                }
                if (self->handle >= 0) {
                    FUN_001b1f84(&DAT_0034179c, &self->handle);
                }
                self->handle = -1;
                self->SetState(3);
            }
        break;
    }
    case 4: {
            int c = self->cnt - 1;
            self->cnt = c;
            if (c <= 0) {
                self->SetState(5);
            }
        break;
    }
    default: {
            if (st == 0) {
                switch (self->owner->f2f8) {
                case 0:
                    FUN_001b3ea4(0.3f, &DAT_0034179c);
                    self->SetState(4);
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    break;
                case 5:
                case 6:
                    DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
                    DAT_0034a788 = (int)((DAT_00310fc8 >> 16) & 0x7fff) % 5;
                    FUN_0024e6cc(1, 0, 0);
                    FUN_001b3ea4(0.3f, &DAT_0034179c);
                    self->SetState(2);
                    if (DAT_002fbef9 == 0) {
                        self->handle = FUN_001b2bb8(&DAT_0034179c, **(self->owner->f350 + self->owner->f2fc) + 50);
                    } else {
                        self->cnt = 15;
                    }
                    break;
                }
            }
            self->owner->v2();
    }
    }
}
// lane sn6: 233/246 words, shift-tolerant mismatch ~17 (hstmatch word-by-word counts 229 because of the 13-word shortfall). Structure now equals retail:
//  - the state-entry helper is an inline `SetState(s)` that stores state and then dispatches on the MEMBER (`switch (state)`, not on the parameter): tests come out 3, 4, 2, 1, 0 and are NOT
//    constant-folded at the call sites (retail keeps `li a0,3; beq a0,a0`); dispatching on `s` or an if chain on `s` folds the whole chain away (123 words). Source order of its cases:
//    0 (owner->v1()), 1 (owner->v1()), `2: 4:` (cnt = 9), 3 (empty);
//  - the main body is `switch (st) { case 2: {..} break; case 4: {..} break; default: {..} }` (layout B2, B4, default; tests 4 then 2); an if/else-if chain puts the st==4 body first;
//  - the owner switch needs the empty labels 1-4 so the 7-entry jump table (rodata=0x2ca68c) is emitted.
// Open: retail starts every virtual-call arm with its own `lw a0,0(s0)` IN ADDITION to the copy in the likely-branch slot (8 extra words); a per-arm local `Owner *o`, an identical-layout cast
// (Fx2) for either arm and a direct `owner->v1()` all give the slot copy only. Also `li v0,15` (the cnt = 15 store of the else arm of DAT_002fbef9) is missing after the SetState(2) inline.
// near miss from lane sn6 (unreviewed)
