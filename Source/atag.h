#ifndef _FB_ATAG_H_
#define _FB_ATAG_H_


/* list of possible tags */
#define ATAG_NONE       0x00000000
#define ATAG_CORE       0x54410001
#define ATAG_SERIAL     0x54410006
#define ATAG_REVISION   0x54410007
#define ATAG_CMDLINE    0x54410009

struct atag_header {
        unsigned long size; /* length of tag in words including this header */
        unsigned long tag;  /* tag value */
};

struct atag_core {
};

struct atag_serialnr {
        unsigned long low;
        unsigned long high;
};

struct atag_revision {
        unsigned long rev;
};


struct atag_cmdline {
        char    cmdline[1];
};


struct atag {
        struct atag_header hdr;
        union {
                struct atag_core         core;
                struct atag_serialnr     serialnr;
                struct atag_revision     revision;
                struct atag_cmdline      cmdline;
        } u;
};

void setup_core_tag(void * address);
void setup_serial_tag(unsigned long low, unsigned long high );
void setup_rev_tag(unsigned long rev);
void setup_cmdline_tag(const char * line);

void setup_end_tag(void);

#endif//_FB_ATAG_H_
