/* HSTMATCH module=hstp_trans_main.prx start=0x0028b474 end=0x0028b5d0 symbol=FUN_0028b474 lang=c++ */
/* Clone of src/eboot/struct_swap_0027a190.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Inline three-way exchange of a 48-byte record (5 bytes, 5 ints, 5 floats): the temp copy is one block copy through $f registers, the two writes back are member-wise, which is how the compiler expands an assignment between records that hold arrays. */
struct T {
    unsigned char c[5];
    int i[5];
    float f[5];
};

extern "C" void FUN_0028b474(T *a, T *b) {
    T t = *a;
    a->c[0] = b->c[0];
    a->c[1] = b->c[1];
    a->c[2] = b->c[2];
    a->c[3] = b->c[3];
    a->c[4] = b->c[4];
    a->i[0] = b->i[0];
    a->i[1] = b->i[1];
    a->i[2] = b->i[2];
    a->i[3] = b->i[3];
    a->i[4] = b->i[4];
    a->f[0] = b->f[0];
    a->f[1] = b->f[1];
    a->f[2] = b->f[2];
    a->f[3] = b->f[3];
    a->f[4] = b->f[4];
    b->c[0] = t.c[0];
    b->c[1] = t.c[1];
    b->c[2] = t.c[2];
    b->c[3] = t.c[3];
    b->c[4] = t.c[4];
    b->i[0] = t.i[0];
    b->i[1] = t.i[1];
    b->i[2] = t.i[2];
    b->i[3] = t.i[3];
    b->i[4] = t.i[4];
    b->f[0] = t.f[0];
    b->f[1] = t.f[1];
    b->f[2] = t.f[2];
    b->f[3] = t.f[3];
    b->f[4] = t.f[4];
}
