#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define N             (27000)
#define BITS_PER_WORD (sizeof(uint32_t) * CHAR_BIT)
#define BUFFER_LENGTH (N / BITS_PER_WORD + 1)

const int k_shift = 5;
const int k_mask  = 0x1F;

void set(uint32_t * const buffer, const int i);
int is_set(uint32_t * const buffer, const int i);

int main(void)
{
    int i;
    uint32_t buffer[BUFFER_LENGTH] = {};

    while(scanf("%d\n", &i) != EOF)
    {
        set(buffer, i);
    }

    for(i = 0; i < N; ++i)
    {
        if(is_set(buffer, i))
	{
	    printf("%d\n", i);
	}
    }

    return 0;
}

void set(uint32_t * const buffer, const int i)
{
    int index    = i >> k_shift;
    int set_bits = i &  k_mask;

    buffer[index] |= 1 << set_bits;
}

static int is_set(uint32_t * const buffer, const int i)
{
    int index    = i >> k_shift;
    int set_bits = i &  k_mask;

    return buffer[index] & (1 << set_bits);
}
