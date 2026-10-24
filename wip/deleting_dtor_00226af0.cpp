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
            Swap(DAT_0034a2f0.cap, v1.cap);
            Swap(DAT_0034a2f0.data, v1.data);
            Swap(DAT_0034a2f0.size, v1.size);
            FUN_001466dc(&v1, 0);

            v2.data = 0;
            v2.size = 0;
            v2.cap = 0;
            FUN_0022909c(&v2, DAT_0034a308.data, DAT_0034a308.data + DAT_0034a308.size, tag2);
            Swap(DAT_0034a308.cap, v2.cap);
            Swap(DAT_0034a308.data, v2.data);
            Swap(DAT_0034a308.size, v2.size);
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

// Differing words: 42 words out of 162 words (first at +0x118).
// Prologue through 0x226c04 is 100% exact match.
// Mismatch is in the second clear and swap temporaries (retail keeps old size in v1, lui in v0;
// ours hoists lui into v1 and puts size into a0, with swap block register colors a1/a0 vs v1/a1/a0).
// Identical unsolved MWCC issue as documented for sister function 0x2471c4 in docs/MWCC-NOTES.md.
// near miss from lane ag4 (unreviewed)
