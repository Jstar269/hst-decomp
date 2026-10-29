/* HSTMATCH module=EBOOT.BIN start=0x0021869c end=0x00218814 symbol=FUN_0021869c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ids 0..299 are group*ID_PAGE_SIZE+index; later bands start a new group. */
enum { ID_PAGE_SIZE = 64, ID_BAND_1 = 300, ID_BAND_2 = 400, ID_BAND_3 = 500, ID_BAND_4 = 600 };

void FUN_0021869c(int *group, int *index, int id)
{
    if (id == 0x8f) {
        *group = 0;
        *index = 0x29;
    } else if (id == 0x90) {
        *group = 0;
        *index = 0x2c;
    } else if (id == 0xfa) {
        *group = 0;
        *index = 0x2f;
    } else if (id == 0xfb) {
        *group = 0;
        *index = 0x31;
    } else if (id == 0xfc) {
        *group = 1;
        *index = 0x27;
    } else if (id == 0xfd) {
        *group = 2;
        *index = 5;
    } else if (id == 0xfe) {
        *group = 2;
        *index = 9;
    } else if (id == 0xff) {
        *group = 2;
        *index = 0xe;
    } else if (id >= ID_BAND_4) {
        *group = 6;
        *index = id - ID_BAND_4;
    } else if (id >= ID_BAND_3) {
        *group = 5;
        *index = id - ID_BAND_3;
    } else if (id >= ID_BAND_2) {
        *group = 4;
        *index = id - ID_BAND_2;
    } else if (id >= ID_BAND_1) {
        *group = 3;
        *index = id - ID_BAND_1;
    } else {
        *group = id / ID_PAGE_SIZE;
        *index = id % ID_PAGE_SIZE;
    }
}
