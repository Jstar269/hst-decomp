/* HSTMATCH module=hstp_trans_main.prx start=0x001c31b4 end=0x001c328c symbol=FUN_001c31b4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* sound_controller.cpp (file name and assert text from the strings): per-player sound restart; releases the player's live
   handle through FUN_001c00d4 (release_slot_handle) with the module float DAT_00391480, starts a new one via the
   FUN_001c29f0 wrapper (a1/a2 passed through) and records the flag byte. Debug build: the pcNo range assertion is kept. */
extern void FUN_001c328c(const char *, ...);
extern const char DAT_00391484[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_003914b0[];   /* "0 <= pcNo && pcNo < eMT_PLAYER_NUM" */
extern const char DAT_003914d4[];   /* "sound_controller.cpp" */
#define HST_ASSERT(cond, text, file, line) do { if (!(cond)) { FUN_001c328c(DAT_00391484, text, file, line); for (;;) {} } } while (0)

typedef struct SoundController {
    char pad0[0x5c];
    int *handles;            /* 0x5c */
    unsigned char *flags;    /* 0x60 */
} SoundController;

extern float DAT_00391480;
extern char DAT_003eaad8[];
extern void FUN_001c00d4(float, char *, int *);
extern int FUN_001c29f0(char *, int, int);

int FUN_001c31b4(SoundController *self, int pcNo, int id, unsigned char flag)
{
    int *h;

    HST_ASSERT(0 <= pcNo && pcNo < 4, DAT_003914b0, DAT_003914d4, 415);
    h = &self->handles[pcNo];
    if (*h >= 0) {
        FUN_001c00d4(DAT_00391480, DAT_003eaad8, h);
    }
    *h = FUN_001c29f0(DAT_003eaad8, pcNo, id);
    self->flags[pcNo] = flag;
    return *h;
}
