/* HSTMATCH module=EBOOT.BIN start=0x00062cb4 end=0x00062e40 symbol=FUN_00062cb4 lang=c++ */
/* Clone of src/sharing_main/sound_start_wait_00063b78.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Voice {
    int f0;
    int id;
    unsigned char on;
    int handle;
    int mode;
};

extern "C" {
extern int DAT_00331b80;
void FUN_000627bc(void);
void FUN_00062150(float wait);
void FUN_00062e40(Voice *self, int h);
int FUN_00075eb4(int id, int a, int b);
void FUN_00076454(int h, int a);
void FUN_00076d60(int h, int a, int b);
void FUN_00077470(int h, int a, int b);
int FUN_0007748c(int h, int a, int b, void (*cb)(void));
int FUN_000775d0(int h);
void FUN_002b7a78(void);
}

static inline void StopHandle(Voice *self, int h)
{
    if (h >= 0) {
        FUN_00076454(h, 0);
        if (self->on && self->handle == h)
            self->handle = -1;
    }
}

static inline void ResetHandle(int h)
{
    if (h >= 0)
        FUN_00076d60(h, 0, 0);
}

static inline bool IsPlaying(int h)
{
    return !(FUN_000775d0(h) & 0x22);
}

extern "C" void FUN_00062cb4(Voice *self)
{
    int h;

    if (self->on) {
        if (self->id < 0) {
            h = -1;
        } else {
            if (self->on)
                StopHandle(self, self->handle);
            h = FUN_00075eb4(self->id, 0, 0);
            if (self->on && h >= 0) {
                if (self->mode == 0) {
                    DAT_00331b80++;
                    FUN_0007748c(h, 0, 0x10000, FUN_000627bc);
                } else {
                    FUN_00077470(h, 0, 0x10000);
                }
                self->handle = h;
            }
        }
        if (h >= 0) {
            ResetHandle(h);
            for (int i = 0; i < 90; i++) {
                if (!IsPlaying(h)) {
                    FUN_00062e40(self, h);
                    h = -1;
                    break;
                }
                FUN_00062150(30.0f);
                FUN_002b7a78();
            }
            if (h >= 0)
                FUN_00062e40(self, h);
        }
    }
}
