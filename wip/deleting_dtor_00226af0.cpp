/* HSTMATCH module=EBOOT.BIN start=0x00226af0 end=0x00226d78 symbol=FUN_00226af0 lang=c++ */
#pragma opt_strength_reduction off

extern "C" {
extern void *DAT_00309804;
extern int DAT_0034a314;

void FUN_00053718(void *, int);
void FUN_0022909c(void *, void *, void *, ...);
void FUN_001466dc(void *, int);
void FUN_00056cb0(void *, int);
void FUN_0001f0f0(void *, int);
void FUN_00000a00(void *);
}

struct Alloc {};

struct in_tag {};
struct Tag : in_tag {};

template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }

struct Vec {
    void **data;
    unsigned int size;
    unsigned int cap;

    void swap(Vec &x) { Swap(cap, x.cap); Swap(data, x.data); Swap(size, x.size); }
    void shrink(int n, Alloc) { size -= n; }
    void clear(Alloc a = Alloc()) { shrink(size, a); }
};

extern "C" {
extern Vec DAT_0034a2f0;
extern Vec DAT_0034a308;
}

extern "C" void *FUN_00226af0(void *param_1, short param_2) {
    if (param_1 != 0) {
        *(void **)param_1 = &DAT_00309804;
        DAT_0034a314--;
        if (DAT_0034a314 == 0) {
            {
                unsigned int i = 0;
                if (DAT_0034a2f0.size != 0) {
                    do {
                        void *p = DAT_0034a2f0.data[i];
                        if (p != 0) {
                            FUN_00053718(p, 1);
                            DAT_0034a2f0.data[i] = 0;
                        }
                        i++;
                    } while (i < DAT_0034a2f0.size);
                }
            }
            DAT_0034a2f0.clear();

            {
                unsigned int i = 0;
                if (DAT_0034a308.size != 0) {
                    do {
                        void *p = DAT_0034a308.data[i];
                        if (p != 0) {
                            FUN_00053718(p, 1);
                            DAT_0034a308.data[i] = 0;
                        }
                        i++;
                    } while (i < DAT_0034a308.size);
                }
            }

            DAT_0034a308.clear();

            Vec v1;
            Vec v2;
            Tag tag1;
            Tag tag2;

            v1.data = 0;
            v1.size = 0;
            v1.cap = 0;
            FUN_0022909c(&v1, DAT_0034a2f0.data, DAT_0034a2f0.data + DAT_0034a2f0.size, tag1);
            v1.swap(DAT_0034a2f0);
            FUN_001466dc(&v1, 0);

            v2.data = 0;
            v2.size = 0;
            v2.cap = 0;
            FUN_0022909c(&v2, DAT_0034a308.data, DAT_0034a308.data + DAT_0034a308.size, tag2);
            v2.swap(DAT_0034a308);
            FUN_001466dc(&v2, 0);
        }

        FUN_00056cb0((char *)param_1 + 608, -1);
        FUN_00056cb0((char *)param_1 + 176, -1);
        FUN_0001f0f0(param_1, 0);

        if (param_2 > 0) {
            FUN_00000a00(param_1);
        }
    }
    return param_1;
}

// lane wf20261026-e01-06 (2026-10-26): 42 -> 14 words. The swap blocks are exact once written as an inline member
// `void swap(Vec &x) { Swap(cap, x.cap); Swap(data, x.data); Swap(size, x.size); }` called as `v1.swap(G)` (the temp's
// member, global as argument); `G.swap(v1)` or free Swaps stay at 42. Remaining 14: the SECOND clear only (retail
// lw v1 size, lui v0 per access, subu/sw scheduled after `lb a3; addiu a0,sp,68`; ours lw a0 + hoisted lui v1).
// Ruled out this pass: begin()/end() const getters for the range args, a Vec() ctor (43), clear via a Vec* local,
// moving the clear after the decls / the v1 zero stores (scheduler ignores it), int/unsigned n temps (19), direct
// shrink(size), size -= size (82), unsigned shrink param (114), size = size - n.
// improved by lane wf20261026-e01-06 (unreviewed): 42 -> 14 differing words
