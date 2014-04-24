/**
 * Implementation of the software paging unit.
 */
#include "addressTranslation.h"

#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {


    int addressUpperLimmit = 255;

    if (logical < 0 || logical > addressUpperLimmit) {
        return ERR_OUT_OF_RANGE;
    }

    int higherOrderBits = ((logical & PAGEMASK) >> PAGEBITS);

    if (!ptr[higherOrderBits].valid) {
        return ERR_INVALID;
    }

    int lowerOrderBits = (logical & PAGESIZE);

    int physicalAddressTranslation = ( ( (ptr[higherOrderBits].frame) << PAGEBITS ) + lowerOrderBits );

    return physicalAddressTranslation;

}