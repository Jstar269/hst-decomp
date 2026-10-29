/* HSTMATCH module=EBOOT.BIN start=0x001f41e8 end=0x001f44ec symbol=FUN_001f41e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the else-call of FUN_000657e4 passes a literal 1 that Ghidra drops (retail shares the compare constant in a2), Vec4 and the temp matrix copied field by field while the stored matrix is a struct assignment (row batches), the loop body indexes group->slot[i] / group->mat[i] (group-based induction pointers); names and types await human review. */
#include "hst/slot_group.h"
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
};
struct Node {
    char pad[0x50];
    Vec4 v;
};
struct Slot {
    virtual void m0();
    virtual void m1();
    char pad[0x58 - 4];
    Node *node;
};
struct Target {
    char pad[0x90];
    void *table;
};
struct Group {
    char pad[0x3a0];
    Slot *slot[SLOT_GROUP_COUNT];
    int param[SLOT_GROUP_COUNT];
    char pad1[0x3cc - 0x3c0];
    int selected;
    char pad2[0x410 - 0x3d0];
    Mat4 mat[SLOT_GROUP_COUNT];
    char pad3[0x584 - 0x510];
    Target *target;
};
extern Vec4 DAT_002bc430;
extern Vec4 DAT_002bc440;
extern unsigned char DAT_003417b8;
extern char DAT_002ee4c8[];
extern char DAT_002ee8d0[];
extern "C" {
float FUN_000657e4(void *, char *, ...);
void FUN_0004d2d4(float, Mat4 *, Mat4 *);
Mat4 *FUN_00093818(Slot *);
void FUN_00093434(Slot *, Mat4 *);
void FUN_001f37e4(Group *, Slot *, int, int, int, int);
void FUN_0005548c(Mat4 *, Node *, char *);
void FUN_001ed87c(Target *, Vec4 *, Vec4 *);
}

/* Rotate each slot's matrix by the table angle, store it, and report the selected slot's pelvis and node positions to the target. */
extern "C" void FUN_001f41e8(Group *group)
{
    Vec4 pelvis_pos;
    pelvis_pos.x = DAT_002bc440.x;
    pelvis_pos.y = DAT_002bc440.y;
    pelvis_pos.z = DAT_002bc440.z;
    pelvis_pos.w = DAT_002bc440.w;
    Vec4 node_pos;
    node_pos.x = DAT_002bc430.x;
    node_pos.y = DAT_002bc430.y;
    node_pos.z = DAT_002bc430.z;
    node_pos.w = DAT_002bc430.w;
    float angle;
    if (DAT_003417b8 == 1) {
        angle = FUN_000657e4(group->target->table, DAT_002ee4c8, 2);
    } else {
        angle = FUN_000657e4(group->target->table, DAT_002ee4c8, 1);
    }
    int i = 0;
    do {
        Node *node = group->slot[i] ? group->slot[i]->node : 0;
        if (node != 0) {
            Mat4 *cur_mat = FUN_00093818(group->slot[i]);
            Mat4 rot_mat;
            rot_mat.r0.x = cur_mat->r0.x; rot_mat.r0.y = cur_mat->r0.y; rot_mat.r0.z = cur_mat->r0.z; rot_mat.r0.w = cur_mat->r0.w;
            rot_mat.r1.x = cur_mat->r1.x; rot_mat.r1.y = cur_mat->r1.y; rot_mat.r1.z = cur_mat->r1.z; rot_mat.r1.w = cur_mat->r1.w;
            rot_mat.r2.x = cur_mat->r2.x; rot_mat.r2.y = cur_mat->r2.y; rot_mat.r2.z = cur_mat->r2.z; rot_mat.r2.w = cur_mat->r2.w;
            rot_mat.r3.x = cur_mat->r3.x; rot_mat.r3.y = cur_mat->r3.y; rot_mat.r3.z = cur_mat->r3.z; rot_mat.r3.w = cur_mat->r3.w;
            FUN_0004d2d4(-angle * 0.017453292f /* degrees to radians */, &rot_mat, &rot_mat);
            FUN_00093434(group->slot[i], &rot_mat);
            group->slot[i]->m1();
            group->mat[i] = *FUN_00093818(group->slot[i]);
            FUN_001f37e4(group, group->slot[i], group->param[i], i, 5, 0);
            if (group->selected == i) {
                Mat4 pelvis_mat;
                FUN_0005548c(&pelvis_mat, node, DAT_002ee8d0);
                pelvis_pos.x = pelvis_mat.r3.x;
                pelvis_pos.y = pelvis_mat.r3.y;
                pelvis_pos.z = pelvis_mat.r3.z;
                pelvis_pos.w = pelvis_mat.r3.w;
                node_pos.x = node->v.x;
                node_pos.y = node->v.y;
                node_pos.z = node->v.z;
                node_pos.w = node->v.w;
            }
        }
        i++;
    } while (i < SLOT_GROUP_COUNT);
    FUN_001ed87c(group->target, &pelvis_pos, &node_pos);
}
