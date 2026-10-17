/* HSTMATCH module=EBOOT.BIN start=0x001b4418 end=0x001b4458 symbol=FUN_001b4418 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Shared {
    char pad[0x7b4];
    int f7b4;
};

struct Self {
    Shared *shared;
};

extern "C" void FUN_00062b1c(int h, float f, int v);

extern "C" void FUN_001b4418(Self *self, float t, float f)
{
    int h = self->shared->f7b4;
    if (h >= 0) {
        FUN_00062b1c(h, f, (int)(t * 128.0f));
    }
}
