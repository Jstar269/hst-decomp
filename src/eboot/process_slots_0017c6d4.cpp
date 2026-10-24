/* HSTMATCH module=EBOOT.BIN start=0x0017c6d4 end=0x0017c968 symbol=FUN_0017c6d4 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
struct Slot {
    int id;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    float data[6];
};

struct Obj {
    char pad0[0x5c];
    Slot f5c;
    char pad1[0x19c - 0x5c - sizeof(Slot)];
    int f19c;
    Slot slots[10];
    int f2e0;
    Slot f2e4;
};

extern "C" {
int FUN_00049094(unsigned int);
int FUN_001fe0dc(void);
void FUN_001fe0e8(int);
void FUN_0017d018(Obj*, int, float*, unsigned char, int);
void FUN_0017db50(Obj*);
int FUN_00048fc8(void (*)(Obj*), Obj*);
void FUN_0017c6d4(Obj *self, unsigned int param_2);
}

void FUN_0017c6d4(Obj *self, unsigned int param_2) {
    Slot *slot = &self->f5c;
    bool bVar2 = false;
    bool bVar1;

    if (FUN_00049094(param_2 & 0xff)) {
        if (FUN_001fe0dc()) {
            FUN_001fe0e8(0);
        }
        bVar1 = true;
        if (--self->f2e0 <= 0) {
            self->f2e0 = 0;
            for (int i = 0; i < 10; i++) {
                Slot *s = &self->slots[i];
                if (self->slots[i].id == 0x7fffffff) break;
                FUN_0017d018(self, s->id, s->data, s->f4, 1);
                s->id = 0x7fffffff;
                s->f4 = 0;
                s->f5 = 0;
                s->f6 = 0;
                s->f7 = 0;
                *(int*)&s->data[0] = 0x7fffffff;
                *(int*)&s->data[1] = 0x7fffffff;
                *(int*)&s->data[2] = 0x7fffffff;
                *(int*)&s->data[3] = 0x7fffffff;
                *(int*)&s->data[4] = 0x7fffffff;
                *(int*)&s->data[5] = 0x7fffffff;
            }
        } else {
            bVar1 = false;
        }
    } else {
        bVar1 = false;
    }

    if (bVar1) {
        if (--self->f19c <= 0) {
            self->f19c = 0;
        }
        if (param_2 != 0) {
            bVar2 = true;
        } else if (slot->f5 == 0 && FUN_00049094(param_2 & 0xff) != 0 && self->f19c <= 0) {
            bVar2 = true;
        }

        if (bVar2 && slot->id != 0x7fffffff) {
            if (param_2 != 0) {
                self->f2e4 = *slot;
                FUN_0017db50(self);
                slot->f5 = 1;
                self->f2e4.f5 = 1;
            } else {
                self->f2e4 = *slot;
                if (FUN_00048fc8(FUN_0017db50, self) != 0) {
                    slot->f5 = 1;
                    self->f2e4.f5 = 1;
                }
            }
        }
    }
}
