/* HSTMATCH module=hstp_trans_main.prx start=0x00108558 end=0x00108718 symbol=FUN_00108558 lang=c++ */
/* Clone of src/eboot/world_transform_update_00102c54.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The world matrix copy must be four row assignments of a struct with a float[4] array member, and the
   worldScale statement has to come LAST in the if-block: written first, MWCC schedules it after the rows. */
#pragma opt_strength_reduction off
struct Vec4 {
    float v[4];
};

struct Mat4 {
    Vec4 row[4];
} __attribute__((aligned(16)));

struct Node;

struct Item {
    char pad0[0x20];
    Node *node;
};

struct Node {
    char pad0[0x10];
    Item **items;
    int itemCount;
    char pad1[0x18];
    Mat4 local;
    Node *parent;
    char pad2[4];
    float scale;
    float worldScale;
    Mat4 world;
};

extern "C" void FUN_00022598(Mat4 *, Mat4 *, Mat4 *);
extern "C" void FUN_000ec4d0(Mat4 *, Mat4 *, Mat4 *);
extern "C" void FUN_001016c0(Mat4 *, Mat4 *);
extern "C" int FUN_00108718(Node *);
extern "C" Node *FUN_00108720(Item *);
extern "C" Item *FUN_00108728(Node *, int);
extern "C" void FUN_00108558(Node *);

extern "C" void FUN_00108558(Node *self)
{
    if (self->parent == 0) {
        self->world.row[0] = self->local.row[0];
        self->world.row[1] = self->local.row[1];
        self->world.row[2] = self->local.row[2];
        self->world.row[3] = self->local.row[3];
        self->worldScale = self->scale;
    } else {
        FUN_00022598(&self->world, &self->parent->world, &self->local);
        self->worldScale = self->parent->worldScale * self->scale;
    }
    for (int i = 0; i < self->itemCount; i++) {
        Node *node = self->items[i]->node;
        if (node == 0)
            continue;
        if (node->parent == 0) {
            FUN_001016c0(&node->world, &node->local);
            node->worldScale = node->scale;
        } else {
            FUN_000ec4d0(&node->world, &node->local, &node->parent->world);
            node->worldScale = node->parent->worldScale * node->scale;
        }
        int j = 0;
        if (0 < FUN_00108718(node)) {
            do {
                Item *item = FUN_00108728(node, j);
                Node *child = FUN_00108720(item);
                if (child != 0)
                    FUN_00108558(child);
                j++;
            } while (j < FUN_00108718(node));
        }
    }
}
// near miss: 112/112 words (same length), 108 differing - every difference is either the saved-
// register permutation (retail self=s2, i=s1, node=s0, j=s3; ours self=s3, i=s2, node=s1, j=s4)
// or its single cause: the outer index. Retail recomputes the byte address every iteration
// (`sll a0,s1,2; addu v1,v1,a0` from a base loaded each pass) and closes the loop with
// `bnezl v1,L; lw v1,16(s2)`; MWCC strength-reduces our `self->items[i]` into an offset induction
// variable (`addu v1,v1,s0` + a separate `addiu s0,s0,4` in the back-edge slot), which costs the
// fifth saved register and pushes every live value one slot. Tried and rejected: for-loop with the
// counter declared outside, pointer form `*(self->items + i)`, `Item *item = self->items[i]` split
// through a local, and a do/while with `if (0 < self->itemCount)` (113 words).
// Solved along the way (reusable):
// - the 64-byte matrix copy `world = local` must be FOUR row assignments `world.row[r] =
//   local.row[r]` of a row type declared with an ARRAY member, `struct Vec4 { float v[4]; };` -
//   that is the only spelling that gives retail's straight 4-register batch (lwc1 f3,f2,f1,f0 then
//   f3,f2,f1,f0 stores). A whole-struct 64-byte assignment becomes an 8-iteration lw/sw loop, a
//   `{float x,y,z,w}` row gives interleaved single-register pairs.
// - the layout: local matrix at 0x30, parent at 0x70, an unknown word at 0x74, scale at 0x78,
//   worldScale at 0x7c, world at 0x80 (Ghidra's 0x74 is a gap, not a field: without it every
//   float lands 4 bytes low).
