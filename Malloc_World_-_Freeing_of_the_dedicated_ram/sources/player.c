#include "../headers/header.h"

void printInventory(InventoryNode *inventoryNode){
    if(inventoryNode == NULL){
        printf("Inventaire vide");
    }else{
        while(inventoryNode != NULL){
            printf("Value : %d | Quantity : %d\n",inventoryNode->value,inventoryNode->quantity);
            inventoryNode = inventoryNode->next;
        }
    }
}

void addToInventory(InventoryNode **inventoryHead, int item, int quantity){
    InventoryNode *newNode= malloc(sizeof(InventoryNode));
    newNode->value = item;
    newNode->quantity = quantity;
    newNode->next = NULL;

    if(*inventoryHead == NULL){
        *inventoryHead = newNode;
    }else{
        InventoryNode *lastNode = *inventoryHead;

        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void initPlayer(Player *player){
    player->level = 1;
    player->xp = 0;
    player->maxHp = 100;
    player->currentHp = 100;
    player->inventory = NULL;

    addToInventory(&player->inventory, _woodSword, 1);
    addToInventory(&player->inventory, _woodPickaxe, 1);
    addToInventory(&player->inventory, _woodBillhook, 1);
    addToInventory(&player->inventory, _woodAxe, 1);

    printInventory(player->inventory);
}
