#ifndef BLOCK_H_
#define BLOCK_H_

#define BLOCK_MMAP
#define BLOCK_PAGE_SIZE 65536

struct block {
    void **pages;
    int count;
    int offset;
};

struct block *block_new(void);

void block_free(struct block*);

void *block_alloc(struct block*, int bytes);

const void *block_get_page(const struct block*, int page, int *bytes_used);

void block_stats(const struct block *block, int *bytes_allocated,
                 int *bytes_used);

#endif
