/* HSTMATCH module=hstp_trans_main.prx start=0x000557dc end=0x0005584c symbol=__dt__10D_000557dcFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000557dc { int v; ~Elem_000557dc() {} };
class V_000557dc {
public:
    Elem_000557dc *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000557dc() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000557dc : public V_000557dc { public: ~D_000557dc(); };
D_000557dc::~D_000557dc() { size = 0; }
