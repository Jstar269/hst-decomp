/* HSTMATCH module=EBOOT.BIN start=0x000bc524 end=0x000bc6c0 symbol=FUN_000bc524 lang=c++ */
/* Clone of src/sharing_main/clear_vectors_000bf998.cpp (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" void __dl__FPv(void *);
extern "C" void FUN_000bea00(void *, int);

struct Base {
    virtual ~Base();
};

struct Vector {
    Base **start;
    int size;
};

inline bool not_equal(Base **a, Base **b) {
    return !(a == b);
}

struct Container {
    char pad[0x48];
    Vector *m_vec48;
    Vector *m_vec4c;
};

struct Tag {};

extern "C" void FUN_000bc524(Container *self, Tag)
{
    Vector *v1 = self->m_vec4c;
    if (v1 != 0) {
        Base **it = v1->start;
        Base **end = it + v1->size;
        while (not_equal(it, end)) {
            Base *elem = *it;
            if (elem != 0) {
                delete elem;
                *it = 0;
            }
            v1 = self->m_vec4c;
            it++;
            end = v1->start + v1->size;
        }
        if (v1 != 0) {
            if (v1 != 0) {
                if (v1 != 0) {
                    FUN_000bea00(v1, 0);
                }
                __dl__FPv(v1);
            }
            self->m_vec4c = 0;
        }
    }

    Vector *v2 = self->m_vec48;
    if (v2 != 0) {
        Base **it2 = v2->start;
        Base **end = it2 + v2->size;
        while (not_equal(it2, end)) {
            Base *elem = *it2;
            if (elem != 0) {
                delete elem;
                *it2 = 0;
            }
            v2 = self->m_vec48;
            it2++;
            end = v2->start + v2->size;
        }
        if (v2 != 0) {
            if (v2 != 0) {
                if (v2 != 0) {
                    FUN_000bea00(v2, 0);
                }
                __dl__FPv(v2);
            }
            self->m_vec48 = 0;
        }
    }
}
