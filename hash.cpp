#include "hash.h"

void HashInit(Hash* hash){
    hash->size = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        hash->table[i] = InitLinkList();
    }
}

void HashInsert(Hash* hash, type data){
    int index = data % MAX_SIZE;
    PushBackNode(hash->table[index], data);
    hash->size++;
}

void HashDelete(Hash* hash, type data){
    int index = data & MAX_SIZE;
    DeleteNode_data(hash->table[index], data);
    hash->size--;
}

LinkList HashFind(Hash* hash, type index){
    return hash->table[index];
}