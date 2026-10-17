/* HSTMATCH module=hstp_trans_main.prx start=0x000dd040 end=0x000dd0b0 symbol=__dt__10D_000dd040Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000dd040 { int v; ~Elem_000dd040() {} };
class V_000dd040 {
public:
    Elem_000dd040 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000dd040() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000dd040 : public V_000dd040 { public: ~D_000dd040(); };
D_000dd040::~D_000dd040() { size = 0; }
