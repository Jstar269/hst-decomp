/* HSTMATCH module=hstp_trans_main.prx start=0x001a2ea8 end=0x001a2f04 symbol=__dt__13Tree_001a2ea8Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_001a2ea8;
struct Tree_001a2ea8 {
    int header;
    Node_001a2ea8 *root;
    ~Tree_001a2ea8();
};
extern "C" void FUN_001a3018(Tree_001a2ea8 *t, Node_001a2ea8 *x);
Tree_001a2ea8::~Tree_001a2ea8()
{
    if (root)
        FUN_001a3018(this, root);
}
