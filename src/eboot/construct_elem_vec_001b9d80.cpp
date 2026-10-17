/* HSTMATCH module=EBOOT.BIN start=0x001b9d80 end=0x001b9f78 symbol=FUN_001b9d80 lang=c++ */
/* Clone of src/sharing_main/construct_elem_vec_001c7ac8.cpp (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_00309314;
extern int DAT_0034a678;

extern "C" void *FUN_00000bcc(unsigned int);
extern "C" void FUN_001baff0(void *, unsigned int);
extern "C" void FUN_001bafac(void *, void *, ...);
extern "C" void *FUN_0020498c(void *mem, int kind, int mode);

struct Tag {};

template <class T> struct Vec {
    T *data_;
    unsigned size_;
    unsigned cap_;
};

struct Obj {
    void *vptr;
    Vec<void *> vec;
    unsigned char b[3][4];
};

extern "C" Obj *FUN_001b9d80(Obj *self)
{
    self->vptr = &DAT_00309314;
    self->vec.data_ = 0;
    self->vec.size_ = 0;
    self->vec.cap_ = 0;
    for (int k = 0; k < 4; k++) {
        self->b[0][k] = 0;
        self->b[1][k] = 0;
        self->b[2][k] = 0;
    }
    int mode = 0;
    switch (DAT_0034a678) {
    case 0x29:
    case 0x30:
        mode = 1;
        break;
    }
    if (self->vec.cap_ < 4) {
        FUN_001baff0(&self->vec, 4);
    }
    for (int i = 0; i < 4; i++) {
        void *elem = 0;
        switch (i) {
        case 0: {
            void *mem = FUN_00000bcc(128);
            if (mem != 0) mem = FUN_0020498c(mem, 0, mode);
            elem = mem;
            break;
        }
        case 1: {
            void *mem = FUN_00000bcc(128);
            if (mem != 0) mem = FUN_0020498c(mem, 2, mode);
            elem = mem;
            break;
        }
        case 2: {
            void *mem = FUN_00000bcc(128);
            if (mem != 0) mem = FUN_0020498c(mem, 1, mode);
            elem = mem;
            break;
        }
        case 3: {
            void *mem = FUN_00000bcc(128);
            if (mem != 0) mem = FUN_0020498c(mem, 3, mode);
            elem = mem;
            break;
        }
        }
        if (self->vec.size_ < self->vec.cap_) {
            unsigned new_size = self->vec.size_ + 1;
            self->vec.size_ = new_size;
            self->vec.data_[new_size - 1] = elem;
        } else {
            FUN_001bafac(&self->vec, &elem, Tag());
        }
    }
    return self;
}
