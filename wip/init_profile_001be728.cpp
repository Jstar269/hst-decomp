/* HSTMATCH module=EBOOT.BIN start=0x001be728 end=0x001be968 symbol=FUN_001be728 lang=c++ */

extern "C" {
extern int DAT_002e9d28;
extern int DAT_002e9d2c;
extern int DAT_002e9d30;
extern int DAT_002e9d34;
extern int DAT_002e9d40;
extern int DAT_002e9d44;

void FUN_001bbd30(void *, int, int);
int FUN_002acd28(int);
}

static inline int Clamp(int v, const int &lo, const int &hi) {
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001be728(int *param_1, int param_2) {
    int i;
    int *p;
    if (param_2 != 0) {
        int lo = DAT_002e9d30;
        int v = 16;
        param_1[0x415] = (v < lo) ? lo : ((DAT_002e9d34 < v) ? DAT_002e9d34 : v);

        *param_1 = 9999999;
        *param_1 = Clamp(*param_1, DAT_002e9d28, DAT_002e9d2c);

        for (i = 0, p = param_1; i < 40; i++, p += 5) {
            if (FUN_002acd28(i)) {
                FUN_001bbd30(p + 0x416, 4, 1);
            }
        }

        param_1[0x408] = Clamp(99, DAT_002e9d40, DAT_002e9d44);
    } else {
        int lo = DAT_002e9d30;
        int v = 0;
        param_1[0x415] = (v < lo) ? lo : ((DAT_002e9d34 < v) ? DAT_002e9d34 : v);

        *param_1 = 0;
        *param_1 = Clamp(*param_1, DAT_002e9d28, DAT_002e9d2c);

        for (i = 0, p = param_1; i < 40; i++, p += 5) {
            FUN_001bbd30(p + 0x416, 0, 0);
        }

        param_1[0x408] = Clamp(0, DAT_002e9d40, DAT_002e9d44);
    }
}

// Differing words: 4 (140/144 words match retail)
// What differs:
// In param_2 != 0 arm:
//   Retail has: li v1, 16; slt at, v1, v0; beqzl at, else (15 words)
//   Ours has:   slti at, v0, 17; bnezl at, else (13 words, 2 words short)
// In param_2 == 0 arm:
//   Retail has: move v1, zero; slt at, v1, v0; beqzl at, else (15 words)
//   Ours has:   blezl v0, else (13 words, 2 words short)
// What was ruled out:
//   - By-value and by-reference Clamp helpers: Clamp(const int&) double-loads lo/hi globals and creates .data literal constants.
//   - Local variable forms: const int, int, char, unsigned char, struct member, ternary in/out of if all constant-fold to slti/blezl.
//   - Macro expansions MIN(MAX(...)) evaluated out of order.
//   - Everything else in the function (second clamp with store-forwarding, 40-element loops, fourth clamp, epilogue) matches retail 100%.
// near miss from lane ag4 (unreviewed)
