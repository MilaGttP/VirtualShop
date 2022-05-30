#include "Id.h"

uint32_t Id::id = 0;

uint32_t Id::getId()
{
    return id++;
}