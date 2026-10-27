/* HSTMATCH module=hstp_trans_main.prx start=0x002889e4 end=0x00288ac4 symbol=FUN_002889e4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies the 64-byte matrix at +0x8e0 into the local matrix of the node at +0x484 and refreshes its world transform
   (FUN_00108558 = world_transform_update_00108558.cpp), after the slot-1 virtual calls on the two objects. The node's
   matrix is a second base at +0x30, so the implicit conversion `Transform *t = node;` is retail's null-checked
   `addiu v0,v0,48`; Mat4 has a user constructor, so its implicit operator= copies row batches. Same source as the EBOOT
   twin src/eboot/node_set_local_matrix_00277834.cpp. */
struct Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
};

struct Obj {
    virtual void v0();
    virtual void v1(int);
};

struct NodeBase : Obj {
    char pad4[0x2c];
};

struct Transform {
    Mat4 local;
};

struct Node : NodeBase, Transform {
};

struct Self {
    char pad0[0x474];
    Obj *m474;
    char pad478[0xc];
    Node *node;
    char pad488[0x8e0 - 0x488];
    Mat4 mat;
};

extern "C" void FUN_00108558(Node *);

extern "C" void FUN_002889e4(Self *self)
{
    self->node->v1(1);
    self->m474->v1(0);
    Transform *t = self->node;
    t->local = self->mat;
    FUN_00108558(self->node);
}
