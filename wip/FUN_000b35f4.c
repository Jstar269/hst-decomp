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
    switch (param_2) {
    case 0x9a:
    case 0x98:
    case 0x52:
        v1 = 1;
        break;
    case 0x80:
    case 0x7e:
    case 0x7c:
    case 0x7a:
    case 0x78:
    case 0x76:
    case 0x75:
    case 0x74:
    case 0x72:
    case 0x70:
    case 0x6e:
    case 0x6c:
    case 0x6a:
    case 0x68:
    case 0x51:
    case 0x50:
    case 0x4f:
    case 0x4e:
    case 0x4d:
    case 0x4c:
    case 0x4b:
    case 0x4a:
    case 0x49:
    case 0x48:
    case 0x47:
    case 0x46:
    case 0x45:
    case 0x44:
        v1 = 0;
        break;
    default:
        break;
    }

    if (v1 >= 0) {
        Vec4 pos = param_1->sub->inner->pos;
        FUN_001b1d10(0x34179c, v1 + 0x32, &pos, 0);
    }
}
// near miss from lane s10171846g1r1-0 (unreviewed)
// improved by lane fm10 (unreviewed): 118 -> 75 differing words
