/* HSTMATCH module=hstp_trans_main.prx start=0x001c2404 end=0x001c2444 symbol=FUN_001c2404 lang=c++ */
/* Clone of src/eboot/call_with_scaled_int_001b4418.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Shared {
    char pad[0x7b4];
    int f7b4;
};

struct Self {
    Shared *shared;
};

extern "C" void FUN_000639e0(int h, float f, int v);

extern "C" void FUN_001c2404(Self *self, float t, float f)
{
    int h = self->shared->f7b4;
    if (h >= 0) {
        FUN_000639e0(h, f, (int)(t * 128.0f));
    }
}
