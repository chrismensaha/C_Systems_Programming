/*
Program 1: The Binary "Save State"
Goal: Master fwrite, fread, and struct persistence.

Instead of writing text that you can read in Notepad,
you will save the literal bits of a C struct to a file.

The Idea: Create a "Player Profile" for a game.

The New Logic: * Define a struct containing a name (char array), a level (int), and health (float).

Use fwrite(&player, sizeof(player), 1, fp) to save it.

Create a separate "Load" function that uses fread to pull that data back into a blank struct.

Why: You'll notice the resulting file is unreadable in a text editor,
but it's incredibly fast to load/save because no "parsing" of text is required.
 */
#include <stdio.h>
#include <string.h>

typedef struct player{
    char name[50];
    unsigned int level;
    float health;
} Player;


void createPlayer(Player* p){
    printf("Player name: ");
    fgets(p->name,sizeof(p->name),stdin);
    p->name[strcspn(p->name,"\n")]=0;
    printf("Player level: ");
    scanf("%u",&p->level);
    printf("Player health: ");
    scanf("%f",&p->health);
}

void createSave(Player* player,char filename[10]){
    FILE* file=fopen(filename,"wb");
    if (file!=NULL){
        fwrite(player,sizeof(Player),1,file);
        fclose(file);
    } 
}

void loadSave(Player* player, char filename[10]){
    FILE* fileptr=fopen(filename,"rb");
    if (fileptr!=NULL){
        fread(player,sizeof(Player),1,fileptr);
        fclose(fileptr);
    }
}

int main(){
    Player p1;
    createPlayer(&p1);
    createSave(&p1,"player1.bin");
    loadSave(&p1,"player1.bin");
    return 0;
}