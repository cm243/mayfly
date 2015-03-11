#ifndef __MAYFLY__
#define __MAYFLY__

#include "entity.h"
#include "room.h"

#define MAX_MAYFLIES	40

typedef enum
{
	BELIEVER,
	SOLDIER,
	ARCHER
}className;

//soldier beats archer
//archer beats believer
//believer beats soldier

typedef struct Mayfly_T
{
	Entity *entity;
	className currClass;
	int	isFemale; //0 Male, 1 Female
	
	int age;

	int	health;
	int	speed;
	int	strength;
	int	luck;

	int	soldierExp;
	int	archerExp;
	int	believerExp;

	int	visible; //Turn invisible on combat
	int inUse;
	int selected;

	int action; //0 if action is used up

	//void (*think)(Entity *e);
}Mayfly;

extern Mayfly mayflyList[MAX_MAYFLIES];
extern Mayfly mayflySelect[15];

void initMayflyList();

Mayfly *newMayfly();
void setupMayfly(Mayfly *m);
void createMayfly();
void createMayflyOffspring(Mayfly *m1, Mayfly *m2);


void newMayflies();
void displayMayflies(SDL_Surface *screen);
void freeMayfly(Mayfly *m);
void closeMayflies();
void clearMayflySelection();
int	 checkSelected();
void setupMayflyOffspring(Mayfly *child);
void mayflyAllThink(Room *r);
void mayflyThink(Mayfly *m);

#endif