/* HSTMATCH module=hstp_trans_main.prx start=0x00299114 end=0x00299264 symbol=FUN_00299114 lang=c++ data=0x003a7920 */
/* Hand-written reconstruction from the disassembly (queued-record call shaped like the matched sibling src/sharing_main/FUN_00299264.cpp); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a7920-0x003a793b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Twin of EBOOT 0x2879e0. BGM volume request: applied at once when there is no delay and FUN_0029a85c(self) reports
   nothing pending, or when forced: mode 0 sets the volume (a negative volume restores the previous one, kept at
   +0x48) over frames/30 seconds and traces "Bgm Volume %.3f", mode 1 calls FUN_001c2914; otherwise a type-0x49
   record {delay, mode, volume, frames} is inserted into the request list at +0x64 (position by const reference
   to a temporary, as in the sibling). Declared parameter order (float third) follows the prologue copies; the
   negative-volume fallback is a self-assigning ternary (the if form lays out the likely branch differently). */
struct Iter { int p; };

struct Rec {
    int type;
    int delay;
    int mode;
    float vol;
    int frames;
    int pad;
};

struct Self {
    char pad[0x44];
    float f44;
    float f48;
    char pad4c[0x18];
    char c100[4];
    char c104[4];
};

extern "C" {
extern char DAT_003eaad8;
int FUN_0029a85c(Self *);
void FUN_001c2280(void *, float, float);
void FUN_001c2914(void *, float, float);
void FUN_00297e90(...);
Iter FUN_0029ace0(void *, const int &, Rec *);
}

extern "C" void FUN_00299114(Self *self, int mode, float vol, int frames, int delay, int force)
{
    Rec rec;

    if ((delay < 1 && FUN_0029a85c(self) == 0) || force != 0) {
        switch (mode) {
        case 0:
            vol = vol >= 0.0f ? vol : self->f48;
            FUN_001c2280(&DAT_003eaad8, vol, frames / 30.0f);
            self->f48 = self->f44;
            self->f44 = vol;
            FUN_00297e90("          Bgm Volume %.3f\n", (double)vol);
            break;
        case 1:
            FUN_001c2914(&DAT_003eaad8, vol, frames / 30.0f);
            break;
        }
    } else {
        rec.type = 0x49;
        rec.delay = delay;
        rec.mode = mode;
        rec.vol = vol;
        rec.frames = frames;
        FUN_0029ace0(self->c100, (int)self + 0x68, &rec);
    }
}
