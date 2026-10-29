/* HSTMATCH module=hstp_trans_main.prx start=0x000b680c end=0x000b69f4 symbol=FUN_000b680c lang=c++ */
/* Clone of src/eboot/switch_spawn_000b35f4.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s10171846g1r1, FUN_000b680c.c) corrected by hand: switch cases rewritten in ascending retail order, address argument as the DAT_ symbol, Vec4 with memberwise copy ctor; exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
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

extern "C" char DAT_003eaad8;
extern "C" int FUN_001bfd3c(void *, int, const Vec4 *, int);

extern "C" void FUN_000b680c(Obj *param_1, int param_2)
{
    int v1 = -1;
    switch (param_2) {
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x68:
    case 0x6a:
    case 0x6c:
    case 0x6e:
    case 0x70:
    case 0x72:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x78:
    case 0x7a:
    case 0x7c:
    case 0x7e:
    case 0x80:
        v1 = 0;
        break;
    case 0x52:
    case 0x98:
    case 0x9a:
        v1 = 1;
        break;
    default:
        break;
    }

    if (v1 >= 0) {
        Vec4 pos = param_1->sub->inner->pos;
        FUN_001bfd3c(&DAT_003eaad8, v1 + 0x32, &pos, 0);
    }
}
// near miss from lane s10171846g1r1-0 (unreviewed)
// improved by lane fm10 (unreviewed): 118 -> 75 differing words

// matching idiom: the switch lists the 0x44..0x80 group first and 0x52/0x98/0x9a second (retail tests in reverse source order); the pos copy is a memberwise-copy-ctor Vec4.
