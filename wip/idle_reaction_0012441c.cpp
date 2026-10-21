/* HSTMATCH module=EBOOT.BIN start=0x0012441c end=0x00124610 symbol=FUN_0012441c lang=c++ */
struct Cell {
    char pad[0x234];
    int f234;
    int f238;
    int f23c;
};
struct Obj58 {
    char pad[0x58];
    int f58;
};
struct Game {
    char pad[0x70];
    int f70;
    char pad1[0x88 - 0x74];
    Cell *f88;
    char pad2[0x9c - 0x8c];
    Obj58 *f9c;
};
struct Env {
    char pad[0x8c];
    int f8c;
};
struct Self {
    char pad[0x74];
    float timer;
    char pad1[0x79 - 0x78];
    unsigned char active;
    char pad2[0x84 - 0x7a];
    float f84;
    char pad3[0x90 - 0x88];
    int f90;
};
extern Game *DAT_003386b0;
extern Env *DAT_00340284;
extern unsigned int DAT_00310fc8;
extern int DAT_002da1dc;
extern int DAT_002da1e0;
extern "C" {
int FUN_000b3490(int);
int FUN_0012520c(Self *, int);
int FUN_00125514(Self *, int, int, int);
float FUN_00130b10(Env *);
void FUN_001258bc(Self *, int);
}

extern "C" void FUN_0012441c(Self *self)
{
    if (self->active == 0) {
        return;
    }
    Cell *cell = DAT_003386b0->f88;
    int s1 = cell->f23c;
    int s0 = cell->f234;
    int code = 0;
    if (FUN_000b3490(DAT_003386b0->f70) != 0) {
        code = 12;
    } else if (DAT_00340284->f8c == 2 || s0 != 0 || s1 != 2) {
        int v = DAT_003386b0->f9c->f58;
        if (v == DAT_002da1dc + FUN_0012520c(self, 7)) {
            code = 14;
        }
    } else {
        code = 13;
    }
    if (self->timer > 0.0f) {
        self->timer = self->timer - 1.0f;
    }
    if (code > 0) {
        float t = self->timer;
        if (t > 0.0f) {
            if (t == 1.0f) {
                self->timer = t + 1.0f;
            }
        } else {
            DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
            int r = (int)((DAT_00310fc8 >> 16) & 0x7fff) % 100;
            if (r < DAT_002da1e0) {
                int idx = FUN_00125514(self, code, 0, 0);
                if (idx >= 0) {
                    float d = FUN_00130b10(DAT_00340284);
                    self->f90 = (int)((float)self->f90 + (self->f84 - d));
                    FUN_001258bc(self, idx);
                }
            }
            self->timer = 60.0f;
        }
    }
}
// lane sn6: 120/125 words (five short), the first 17 instructions and every operation match; the difference is branch/delay-slot layout in the reason-code selection:
//  retail  `jal b3490; move s2,zero; beqz v0,ELSE; nop; b JOIN; li s2,12; ELSE: lui v1,0x34 ...; beq a0,v1,B; nop; bnez s0,B; nop; bne s1,v1,B; nop; b JOIN; li s2,13; B: ...`
//  ours    `beqzl v0,ELSE+4; lui v1,0x34; b JOIN; li s2,12; ELSE: ...; beql s1,v1,JOIN; li s2,13`  (MWCC turns both into likely branches, retail leaves plain beqz+nop and bne+nop+b).
// Tried (all 107-108 words off): if/else-if chain, inverted nesting (`!= 2 && == 0 && == 2` first), `ret` local, `== 0` first, helper `Reason()` with early returns (125 off, different frame),
// do { ... break; } while (0), Ghidra's literal goto form (`fVar5 = timer; goto LAB`). Rest of the function (LCG `seed*0x343fd+0x269ec3` -> `((seed >> 16) & 0x7fff) % 100` as ext+div, timer logic,
// `f90 = (int)((float)f90 + (f84 - FUN_00130b10(env)))`, `timer = 60.0f`) is as retail.
// near miss from lane sn6 (unreviewed)
