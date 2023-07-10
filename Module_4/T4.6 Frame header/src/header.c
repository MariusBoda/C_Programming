#include "header.h"

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header is valid, possibly checked using validateHeader function above, and ACK bit is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */



int validateHeader(uint32_t header){

<<<<<<< HEAD
    uint32_t sync = (header >> 24) & 0xFF;
    uint32_t ack = (header >> 23) & 0x01;
    uint32_t v = (header >> 22) & 0x01;
    uint32_t type = (header >> 22) & 0x01;
    uint32_t source = (header >> 16) & 0xFFFF;
    uint32_t dest = (header >> 0) & 0xFFFF;
    if(sync == 0x2a & ((ack & v) | (!ack & type != 0)) & source != 0 & dest != 0 & source != dest){
=======
    uint32_t sync = (header >> 0) & 0x3F;
    uint32_t ack = (header >> 6) & 0x01;
    uint32_t v = (header >> 7) & 0x01;
    uint32_t type = (header >> 8) & 0x07;
    //uint32_t frameId = (header >> 11) & 0x1F;
    uint32_t source = (header >> 16) & 0xFF;
    uint32_t dest = (header >> 24) & 0xFF;

    if ((sync == 0x2a) && ((ack && v) | (!ack && (type != 0))) & (source != 0) & (dest != 0) & (source != dest)) {
>>>>>>> a5e93f31a3ec08f8df6ebadb606f99c771dafc0e
        return 1;
    } else {
        return 0;
    }
}
int getFrameId(uint32_t header)
{
<<<<<<< HEAD
    uint32_t frameId = (header >> 16) & 0xFFFF;
=======

    uint32_t frameId = (header >> 11) & 0x1F;

>>>>>>> a5e93f31a3ec08f8df6ebadb606f99c771dafc0e
    if(validateHeader(header) == 1){
        return frameId;
    } else { return -1; }
}

int getFrameType(uint32_t header)
{   uint32_t ack = (header >> 6) & 0x01;
    uint32_t type = (header >> 8) & 0x07;
    if(validateHeader(header) == 0) {
        return -1;
    }
    else if(ack == 0) {return type;}

    else {
        return 0;
    }
}
int getSourceAddress(uint32_t header)
{
    if(validateHeader(header) == 0) {
        return -1;
    }
    else {
        return (header >> 16) & 0xFF;
    }
}

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid) {
    uint32_t header = 0;
    header = (header << 24) | 0x2a;
    header = (header << 16) | (sourceAddress & 0xFF);
    header = (header << 24) | (destAddress & 0xFF);
    header = (header << 11) | (frameId & 0x1F);
    header = (header << 7) | (valid & 0x07);
    return header;
}


uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type)
{
    uint32_t header = 0;
    header = (header << 24) | 0x2a;
    header = (header << 16) | (sourceAddress & 0xFF);
    header = (header << 24) | (destAddress & 0xFF);
    header = (header << 11) | (frameId & 0x1F);
    header = (header << 8) | (type & 0x07);
    return header;
}
