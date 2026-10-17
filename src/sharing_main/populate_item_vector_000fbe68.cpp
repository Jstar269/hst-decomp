/* HSTMATCH module=hstp_trans_main.prx start=0x000fbe68 end=0x000fbf44 symbol=FUN_000fbe68 lang=c++ */
/* Clone of src/eboot/populate_item_vector_000f6774.cpp (hstclone.py tag u1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Tag {};

struct Item {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int f24;
    float f28;
    int f32;
    int f36;
    char f40;
    char pad[7];
    Item() {
        f0 = 0;
        f4 = 0;
        f8 = 0;
        f16 = 0;
        f20 = 0;
        f24 = 0;
        f28 = 1.0f;
        f32 = 1;
        f36 = 3;
        f40 = 0;
    }
};

extern "C" void FUN_00101a90(void *, Item **, Tag);

struct Vector {
    Item **data;
    unsigned int size;
    unsigned int capacity;
    void push_back(Item *val) {
        if (size < capacity) {
            ++size;
            data[size - 1] = val;
        } else {
            FUN_00101a90(this, &val, Tag());
        }
    }
};

struct Manager {
    char pad[0x830];
    Vector vec;
    char pad1[0x20];
    int count;
};

extern "C" void FUN_000fbe68(Manager *self, int count)
{
    self->count = count;
    for (int i = 0; i < count; i++) {
        Item *item = new Item();
        self->vec.push_back(item);
    }
}
