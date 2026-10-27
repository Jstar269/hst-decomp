/* HSTMATCH module=hstp_trans_main.prx start=0x00063b78 end=0x00063d04 symbol=FUN_00063b78 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Voice {
    int f0;
    int id;
    unsigned char on;
    int handle;
    int mode;
};

extern "C" {
extern int DAT_003daec0;
void FUN_00063644(void);
void FUN_00062fd4(float wait);
void FUN_00063d04(Voice *self, int h);
int FUN_00077674(int id, int a, int b);
void FUN_00077c14(int h, int a);
void FUN_00078520(int h, int a, int b);
void FUN_00078c30(int h, int a, int b);
int FUN_00078c4c(int h, int a, int b, void (*cb)(void));
int FUN_00078d90(int h);
void FUN_002c7818(void);
}

static inline void StopHandle(Voice *self, int h)
{
    if (h >= 0) {
        FUN_00077c14(h, 0);
        if (self->on && self->handle == h)
            self->handle = -1;
    }
}

static inline void ResetHandle(int h)
{
    if (h >= 0)
        FUN_00078520(h, 0, 0);
}

static inline bool IsPlaying(int h)
{
    return !(FUN_00078d90(h) & 0x22);
}

extern "C" void FUN_00063b78(Voice *self)
{
    int h;

    if (self->on) {
        if (self->id < 0) {
            h = -1;
        } else {
            if (self->on)
                StopHandle(self, self->handle);
            h = FUN_00077674(self->id, 0, 0);
            if (self->on && h >= 0) {
                if (self->mode == 0) {
                    DAT_003daec0++;
                    FUN_00078c4c(h, 0, 0x10000, FUN_00063644);
                } else {
                    FUN_00078c30(h, 0, 0x10000);
                }
                self->handle = h;
            }
        }
        if (h >= 0) {
            ResetHandle(h);
            for (int i = 0; i < 90; i++) {
                if (!IsPlaying(h)) {
                    FUN_00063d04(self, h);
                    h = -1;
                    break;
                }
                FUN_00062fd4(30.0f);
                FUN_002c7818();
            }
            if (h >= 0)
                FUN_00063d04(self, h);
        }
    }
}
