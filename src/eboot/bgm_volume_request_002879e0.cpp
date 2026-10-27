/* HSTMATCH module=EBOOT.BIN start=0x002879e0 end=0x00287b30 symbol=FUN_002879e0 lang=c++ data=0x002fe9f8 */
/* Hand-written reconstruction (port of src/sharing_main/bgm_volume_request_00299114.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002fe9f8-0x002fea13) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Twin of EBOOT 0x2879e0. BGM volume request: applied at once when there is no delay and FUN_002890c0(self) reports
   nothing pending, or when forced: mode 0 sets the volume (a negative volume restores the previous one, kept at
   +0x48) over frames/30 seconds and traces "Bgm Volume %.3f", mode 1 calls FUN_001b48b8; otherwise a type-0x49
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
extern char DAT_0034179c;
int FUN_002890c0(Self *);
void FUN_001b413c(void *, float, float);
void FUN_001b48b8(void *, float, float);
void FUN_00286acc(...);
Iter FUN_00289544(void *, const int &, Rec *);
}

extern "C" void FUN_002879e0(Self *self, int mode, float vol, int frames, int delay, int force)
{
    Rec rec;

    if ((delay < 1 && FUN_002890c0(self) == 0) || force != 0) {
        switch (mode) {
        case 0:
            vol = vol >= 0.0f ? vol : self->f48;
            FUN_001b413c(&DAT_0034179c, vol, frames / 30.0f);
            self->f48 = self->f44;
            self->f44 = vol;
            FUN_00286acc("          Bgm Volume %.3f\n", (double)vol);
            break;
        case 1:
            FUN_001b48b8(&DAT_0034179c, vol, frames / 30.0f);
            break;
        }
    } else {
        rec.type = 0x49;
        rec.delay = delay;
        rec.mode = mode;
        rec.vol = vol;
        rec.frames = frames;
        FUN_00289544(self->c100, (int)self + 0x68, &rec);
    }
}
