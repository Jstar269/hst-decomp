/* HSTMATCH module=EBOOT.BIN start=0x00298e4c end=0x00299048 symbol=FUN_00298e4c lang=c99 */

extern int DAT_0034ac60;
extern int DAT_0034ac64;
extern unsigned short DAT_0034ad10;
extern unsigned short DAT_0034ad50;
extern const char DAT_002cb354[];

void FUN_002b7958(int);
void FUN_00296b3c(int, int, int);
int FUN_0029785c(const char *);
int FUN_0029692c(int, int, int);
int FUN_00296adc(int, int, int);

int FUN_00298e4c(void)
{
    int local_20 = 0;
    int local_1c = 0;
    while (DAT_0034ac60 == 1) {
        FUN_002b7958(0x400);
    }
    local_20 = 0;
    while (1) {
        if (local_20 >= 1000 || DAT_0034ac64 == 0)
            break;
        if (DAT_0034ac64 == 2) {
            DAT_0034ac64 = 0;
            break;
        }
        FUN_002b7958(0x400);
        local_20++;
    }

    FUN_002b7958(0x7d000);
    FUN_00296b3c(0x34ad00, 0x88, 0x40);
    local_1c = FUN_0029785c(DAT_002cb354);
    if (local_1c > 0) {
        local_1c = 0;
        if (DAT_0034ad10 != DAT_0034ad50) {
            local_1c = -0x7ffffffc;
        } else if (FUN_0029692c(0x34ad12, 0x34ad52, 0xe) != 0) {
            local_1c = -0x7ffffffc;
        } else if (FUN_00296adc(0x34ad00, 0x34ad40, 0xc) != 0) {
            local_1c = -0x7ffffffc;
        } else if (FUN_00296adc(0x34ad20, 0x34ad60, 0xc) != 0) {
            local_1c = -0x7ffffffc;
        } else if (FUN_00296adc(0x34ad30, 0x34ad70, 0xc) != 0) {
            local_1c = -0x7ffffffc;
        }
    }
    return local_1c;
}
// Differing words: 125/127 under default mwcc; 78 under experimental gcc -O0 -G0.
// Disassembly is compiled with Sony SDK GCC unoptimized (-O0), using $s8 frame pointer,
// stack local spilling for every operation, and unconditional j jumps.
// Standard profiles (MWCC -O4,p and GCC -O1/-O2/-O3/-Os) optimize away the frame pointer and stack spilling.
// near miss from lane ag4 (unreviewed)
