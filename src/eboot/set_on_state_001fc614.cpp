/* HSTMATCH module=EBOOT.BIN start=0x001fc614 end=0x001fc718 symbol=FUN_001fc614 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/set_on_state_0020ad2c.cpp, identical masked code: addresses substituted); exact match verified (matching idiom: the negated flag passed to FUN_001fbdb8 is written `(on != 0) ^ 1`, which keeps retail's sltu/xori/andi; `!on` drops the andi and permutes every saved register); names and types await human review. */
/* Without the child at +0x40 only the state is set (FUN_001fc718(self, 5)); otherwise the flag is stored in the
   object, the child and the member at +0x44 (after FUN_00103628), and the child's two handles are switched on or off
   with the matching state (2 plus the call FUN_001b1c44(&DAT_0034179c, 14) when on, 1 when off). */
struct Child {
    char pad[0x70];
    void *f70;
    void *f74;
    char pad78[4];
    unsigned char f7c;
    unsigned char f7d;
};
struct Member {
    char pad[0x5c];
    unsigned char f5c;
};
struct Self {
    char pad[0x40];
    Child *f40;
    Member *f44;
    char pad48[0xc];
    unsigned char f54;
};
extern "C" {
void FUN_001fc718(Self *, int);
void FUN_001fbdb8(Child *, unsigned char);
void FUN_00103628(Member *, int);
void FUN_000ffb3c(void *, int);
int FUN_001b1c44(char *, int);
extern char DAT_0034179c;
}

extern "C" void FUN_001fc614(Self *self, int on)
{
    if (self->f40 == 0) {
        FUN_001fc718(self, 5);
    } else {
        self->f54 = on;
        self->f40->f7c = on;
        FUN_001fbdb8(self->f40, (on != 0) ^ 1);
        Member *m = self->f44;
        FUN_00103628(m, on);
        m->f5c = on;
        if (self->f54 != 0) {
            Child *c = self->f40;
            c->f7d = 1;
            c->f7c = 0;
            FUN_000ffb3c(c->f70, 1);
            FUN_000ffb3c(c->f74, 1);
            FUN_001fc718(self, 2);
            FUN_001b1c44(&DAT_0034179c, 14);
        } else {
            Child *c = self->f40;
            c->f7d = 0;
            c->f7c = 1;
            FUN_000ffb3c(c->f70, 0);
            FUN_000ffb3c(c->f74, 0);
            FUN_001fc718(self, 1);
        }
    }
}
