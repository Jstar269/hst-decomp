/* HSTMATCH module=EBOOT.BIN start=0x002471c4 end=0x0024747c symbol=FUN_002471c4 lang=c++ */
#pragma opt_strength_reduction off

struct Tag {};
struct Vec;

extern "C" {
extern void *DAT_003098f4;
extern Vec DAT_0034a720;
extern Vec DAT_0034a738;
extern int DAT_0034a744;
extern struct Base *DAT_0034a748;

extern void FUN_00053718(void *, int);
extern void FUN_0022909c(Vec *, void **, void **, Tag);
extern void FUN_001466dc(Vec *, int);
extern void FUN_00056cb0(void *, int);
extern void FUN_0001f0f0(void *, int);
extern void FUN_00000a00(void *);
}

struct Vec {
    void **data;
    int size;
    unsigned int capacity;

    void swap(Vec &other) {
        unsigned int c = capacity;
        capacity = other.capacity;
        other.capacity = c;

        void **d = data;
        data = other.data;
        other.data = d;

        int s = size;
        size = other.size;
        other.size = s;
    }
};

struct Base {
    virtual ~Base();
};

struct Obj {
    void *vtable;
    char pad[220];
    char m224[432];
    char m656[100];
};

extern "C" Obj *FUN_002471c4(Obj *self, short flag)
{
    Vec temp1;
    Vec temp2;
    Tag tag1;
    Tag tag2;

    if (self != 0) {
        self->vtable = &DAT_003098f4;
        DAT_0034a744--;
        if (DAT_0034a744 == 0) {
            unsigned int i = 0;
            if (DAT_0034a720.size != 0) {
                do {
                    void *elem = DAT_0034a720.data[i];
                    if (elem != 0) {
                        FUN_00053718(elem, 1);
                        DAT_0034a720.data[i] = 0;
                    }
                    i++;
                } while (i < (unsigned int)DAT_0034a720.size);
            }
            int n1 = DAT_0034a720.size;
            DAT_0034a720.size -= n1;

            if (DAT_0034a738.size != 0) {
                i = 0;
                do {
                    void *elem = DAT_0034a738.data[i];
                    if (elem != 0) {
                        FUN_00053718(elem, 1);
                        DAT_0034a738.data[i] = 0;
                    }
                    i++;
                } while (i < (unsigned int)DAT_0034a738.size);
            }
            int n2 = DAT_0034a738.size;
            DAT_0034a738.size -= n2;

            temp1.data = 0;
            temp1.size = 0;
            temp1.capacity = 0;
            FUN_0022909c(&temp1, DAT_0034a720.data, DAT_0034a720.data + DAT_0034a720.size, tag1);
            DAT_0034a720.swap(temp1);
            FUN_001466dc(&temp1, 0);

            temp2.data = 0;
            temp2.size = 0;
            temp2.capacity = 0;
            FUN_0022909c(&temp2, DAT_0034a738.data, DAT_0034a738.data + DAT_0034a738.size, tag2);
            DAT_0034a738.swap(temp2);
            FUN_001466dc(&temp2, 0);
        }

        if (DAT_0034a748 != 0) {
            delete DAT_0034a748;
            DAT_0034a748 = 0;
        }

        FUN_00056cb0((char *)self + 656, -1);
        FUN_00056cb0((char *)self + 224, -1);
        FUN_0001f0f0(self, 0);

        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}
// near miss from lane ag2 (unreviewed)
