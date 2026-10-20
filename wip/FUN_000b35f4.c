/* HSTMATCH module=EBOOT.BIN start=0x000b35f4 end=0x000b37dc symbol=FUN_000b35f4 lang=c++ */

struct Vec4 {
    float x, y, z, w;
};

struct SubInner {
    char pad[0x60];
    Vec4 pos;
};

struct Sub {
    char pad[100];
    SubInner *inner;
};

struct Obj {
    char pad[0x5bc];
    Sub *sub;
};

extern "C" int FUN_001b1d10(int, int, const Vec4 *, int);

extern "C" void FUN_000b35f4(Obj *param_1, int param_2)
{
    int v1 = -1;
    if (param_2 != 0x9a) {
        if (param_2 == 0x98) {
            v1 = 1;
        } else if (param_2 != 0x52) {
            if (param_2 == 0x80) {
                v1 = 0;
            } else if (param_2 == 0x7e ||
                       param_2 == 0x7c ||
                       param_2 == 0x7a ||
                       param_2 == 0x78 ||
                       param_2 == 0x76 ||
                       param_2 == 0x75 ||
                       param_2 == 0x74 ||
                       param_2 == 0x72 ||
                       param_2 == 0x70 ||
                       param_2 == 0x6e ||
                       param_2 == 0x6c ||
                       param_2 == 0x6a ||
                       param_2 == 0x68 ||
                       param_2 == 0x51 ||
                       param_2 == 0x50 ||
                       param_2 == 0x4f ||
                       param_2 == 0x4e ||
                       param_2 == 0x4d ||
                       param_2 == 0x4c ||
                       param_2 == 0x4b ||
                       param_2 == 0x4a ||
                       param_2 == 0x49 ||
                       param_2 == 0x48 ||
                       param_2 == 0x47 ||
                       param_2 == 0x46 ||
                       param_2 == 0x45 ||
                       param_2 == 0x44) {
                v1 = 0;
            }
        } else {
            v1 = 1;
        }
    } else {
        v1 = 1;
    }

    if (v1 >= 0) {
        Vec4 pos = param_1->sub->inner->pos;
        FUN_001b1d10(0x34179c, v1 + 0x32, &pos, 0);
    }
}
// near miss from lane s10171846g1r1-0 (unreviewed)
