/* HSTMATCH module=hstp_trans_main.prx start=0x0016c5e4 end=0x0016c804 symbol=FUN_0016c5e4 lang=c++ */
/* Clone of src/eboot/FUN_00160058.cpp (hstclone.py tag s10172123g5r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: C++ Node hierarchy traversal, virtual GetTransform, animation track blending; exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Node {
    virtual void _0() = 0;
    virtual void _1() = 0;
    virtual void _2() = 0;
    virtual bool Method3() = 0;
    virtual bool Method4() = 0;
    virtual void _5() = 0;
    virtual Vec4 GetTransform() = 0;

    char pad_vptr[8];       // vptr (4) + pad (8) -> offset 12
    unsigned int index;     // 12 (0x0c)
    unsigned char flag;     // 16 (0x10)
    char pad17[3];
    Node **children;        // 20 (0x14)
    unsigned int count;     // 24 (0x18)

    Node *GetChild(unsigned int idx) {
        return (idx < count) ? children[idx] : 0;
    }
};

struct Model {
    char pad[0x30];
    char trackA[16];        // 48 (0x30)
    char trackB[16];        // 64 (0x40)
    float time;             // 80 (0x50)
    char pad84[0xa8 - 84];
    Node *root_node;        // 168 (0xa8)
};

extern "C" {
extern void FUN_000224c0(Vec4 *out, void *trackA, float time);
extern void FUN_00022440(Vec4 *out, void *trackB, Vec4 *in);
}

extern "C" Vec4 FUN_0016c5e4(Model *model)
{
    Node *curr = model->root_node;
    Node *target = 0;

    if (curr->Method3()) {
        do {
            target = curr;
            if (curr->flag != 0) {
                break;
            }
            curr = curr->GetChild(curr->index);
        } while (curr->Method3());
    }

    if (target != 0) {
        Node *child = target->GetChild(target->index);
        if (child != 0) {
            if (child->Method4()) {
                return child->GetTransform();
            }
            curr = target;
            if (target->Method3()) {
                do {
                    curr = curr->GetChild(curr->index);
                    if (curr->Method4()) {
                        break;
                    }
                } while (curr->Method3());
            }
            if (curr == target) {
                curr = 0;
            }
            if (curr != 0 && curr->Method4()) {
                return curr->GetTransform();
            }
        }
    }

    Vec4 local_10;
    Vec4 local_20;
    FUN_000224c0(&local_20, model->trackA, model->time);

    local_10 = local_20;
    Vec4 local_30;
    FUN_00022440(&local_30, model->trackB, &local_10);

    return local_30;
}
