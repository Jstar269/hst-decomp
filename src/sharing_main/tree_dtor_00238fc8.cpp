/* HSTMATCH module=hstp_trans_main.prx start=0x00238fc8 end=0x00239024 symbol=__dt__13Tree_00238fc8Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_00238fc8;
struct Tree_00238fc8 {
    int header;
    Node_00238fc8 *root;
    ~Tree_00238fc8();
};
extern "C" void FUN_0023930c(Tree_00238fc8 *t, Node_00238fc8 *x);
Tree_00238fc8::~Tree_00238fc8()
{
    if (root)
        FUN_0023930c(this, root);
}
