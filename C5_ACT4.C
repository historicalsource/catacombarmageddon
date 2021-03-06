/* Catacomb Armageddon Source Code
 * Copyright (C) 1993-2014 Flat Rock Software
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

// C4_PLAY.C

#include "DEF.H"
#pragma hdrstop

/*
=============================================================================

						 LOCAL CONSTANTS

=============================================================================
*/



//-------------------------------------------------------------------------
//
//				ARCH OBJECTS
//
//-------------------------------------------------------------------------



//-------------------------------------------------------------------------
//				ARCH
//-------------------------------------------------------------------------

void SpawnArch(int tilex, int tiley, int num);

extern statetype s_arch_1;
extern statetype s_arch_2;
extern statetype s_arch_3;
extern statetype s_arch_4;
extern statetype s_arch_5;
extern statetype s_arch_6;
extern statetype s_arch_7;
extern statetype s_arch_8;
extern statetype s_arch_9;
extern statetype s_arch_10;
extern statetype s_arch_11;
extern statetype s_arch_12;
extern statetype s_arch_13;

statetype s_arch_1 = {ARCH1PIC, 20, NULL, &s_arch_1};
statetype s_arch_2 = {ARCH2PIC, 20, NULL, &s_arch_2};
statetype s_arch_3 = {ARCH3PIC, 20, NULL, &s_arch_3};
statetype s_arch_4 = {ARCH4PIC, 20, NULL, &s_arch_4};
statetype s_arch_5 = {ARCH5PIC, 20, NULL, &s_arch_5};
statetype s_arch_6 = {ARCH6PIC, 20, NULL, &s_arch_6};
statetype s_arch_7 = {ARCH7PIC, 20, NULL, &s_arch_7};
statetype s_arch_8 = {ARCH8PIC, 20, NULL, &s_arch_8};
statetype s_arch_9 = {ARCH9PIC, 20, NULL, &s_arch_9};
statetype s_arch_10 = {ARCH10PIC, 20, NULL, &s_arch_10};
statetype s_arch_11 = {ARCH11PIC, 20, NULL, &s_arch_11};
statetype s_arch_12 = {ARCH12PIC, 20, NULL, &s_arch_12};
statetype s_arch_13 = {ARCH13PIC, 20, NULL, &s_arch_13};

void SpawnArch (int tilex, int tiley, int num)
{
	statetype	*objstate;


	switch (num)
	{
		case 1:
			objstate = &s_arch_1;
		break;
		case 2:
			objstate = &s_arch_2;
		break;
		case 3:
			objstate = &s_arch_3;
		break;
		case 4:
			objstate = &s_arch_4;
		break;
		case 5:
			objstate = &s_arch_5;
		break;
		case 6:
			objstate = &s_arch_6;
		break;
		case 7:
			objstate = &s_arch_7;
		break;
		case 8:
			objstate = &s_arch_8;
		break;
		case 9:
			objstate = &s_arch_9;
		break;
		case 10:
			objstate = &s_arch_10;
		break;
		case 11:
			objstate = &s_arch_11;
		break;
		case 12:
			objstate = &s_arch_12;
		break;
		case 13:
			objstate = &s_arch_13;
		break;
	}
	ASpawnNewObj(tilex,tiley,objstate,PIXRADIUS*35);
	new->obclass = solidobj;
	new->flags &= ~of_shootable;
}


//-------------------------------------------------------------------------
//
//				MISC OBJECTS
//
//-------------------------------------------------------------------------


//-------------------------------------------------------------------------
//		COLUMN, SULPHUR GAS HOLE, FIRE POT, FOUNTAIN
//-------------------------------------------------------------------------


void SpawnMiscObjects(int tilex, int tiley, int num);

extern statetype s_column;
extern statetype s_sulphur_gas_1;
extern statetype s_sulphur_gas_2;
extern statetype s_sulphur_gas_3;
extern statetype s_fire_pot_1;
extern statetype s_fire_pot_2;
extern statetype s_fountain;

statetype s_column = {COLUMNPIC, 20, NULL, &s_column};
statetype s_sulphur_gas_1 = {SULPHUR_GAS_1PIC, 20, NULL, &s_sulphur_gas_2};
statetype s_sulphur_gas_2 = {SULPHUR_GAS_2PIC, 20, NULL, &s_sulphur_gas_3};
statetype s_sulphur_gas_3 = {SULPHUR_GAS_3PIC, 20, NULL, &s_sulphur_gas_1};
statetype s_fire_pot_1 = {FIRE_POT_1PIC, 20, NULL, &s_fire_pot_2};
statetype s_fire_pot_2 = {FIRE_POT_2PIC, 20, NULL, &s_fire_pot_1};
statetype s_fountain = {WFOUNTAINPIC, 20, NULL, &s_fountain};


void SpawnMiscObjects(int tilex, int tiley, int num)
{
	statetype	*objstate;

	switch (num)
	{
		case 1:
			objstate = &s_column;
		break;

		case 2:
			objstate = &s_sulphur_gas_1;
		break;

		case 3:
			objstate = &s_fire_pot_1;
		break;

		case 4:
			objstate = &s_fountain;
		break;
	}

	SpawnNewObj(tilex,tiley,objstate,PIXRADIUS*35);
	new->obclass = realsolidobj;
	if (num == 2)
		new->flags &= ~of_shootable;
	else
		new->flags |= of_shootable;
}






#if 0
void SpawnColumn(int tilex, int tiley);

extern statetype s_column;
statetype s_column = {COLUMNPIC, 20, NULL, &s_column};

void SpawnColumn(int tilex, int tiley)
{
	SpawnNewObj(tilex,tiley,&s_column,PIXRADIUS*35);
	new->obclass = realsolidobj;
	new->flags |= of_shootable;
}


//-------------------------------------------------------------------------
//				SULPHUR GAS
//-------------------------------------------------------------------------

void SpawnSulphurGas(int tilex, int tiley);

extern statetype s_sulphur_gas_1;
extern statetype s_sulphur_gas_2;
extern statetype s_sulphur_gas_3;

statetype s_sulphur_gas_1 = {SULPHUR_GAS_1PIC, 20, NULL, &s_sulphur_gas_2};
statetype s_sulphur_gas_2 = {SULPHUR_GAS_2PIC, 20, NULL, &s_sulphur_gas_3};
statetype s_sulphur_gas_3 = {SULPHUR_GAS_3PIC, 20, NULL, &s_sulphur_gas_1};

void SpawnSulphurGas(int tilex, int tiley)
{
	SpawnNewObj(tilex,tiley,&s_sulphur_gas_1,PIXRADIUS*35);
	new->obclass = realsolidobj;
	new->flags &= ~of_shootable;
}


//-------------------------------------------------------------------------
//				FIRE POT
//-------------------------------------------------------------------------

void SpawnFirePot(int tilex, int tiley);

extern statetype s_fire_pot_1;
extern statetype s_fire_pot_2;

statetype s_fire_pot_1 = {FIRE_POT_1PIC, 20, NULL, &s_fire_pot_2};
statetype s_fire_pot_2 = {FIRE_POT_2PIC, 20, NULL, &s_fire_pot_1};

void SpawnFirePot(int tilex, int tiley)
{
	SpawnNewObj(tilex,tiley,&s_fire_pot_1,PIXRADIUS*35);
	new->obclass = realsolidobj;
	new->flags |= of_shootable;

}

//------------------------------------------------------------------------
//				FOUNTAIN
//------------------------------------------------------------------------

void SpawnFountain(int tilex, int tiley);

extern statetype s_fountain;
statetype s_fountain = {WFOUNTAINPIC, 20, NULL, &s_fountain};

void SpawnFountain(int tilex, int tiley)
{
	SpawnNewObj(tilex,tiley,&s_fountain,PIXRADIUS*35);
	new->obclass = realsolidobj;
	new->flags |= of_shootable;
}

#endif


//------------------------------------------------------------------------
//				FORCE FIELD
//------------------------------------------------------------------------

void SpawnForceField(int tilex, int tiley);
void T_ForceField(objtype *ob);
void T_ForceFieldRemove(objtype *ob);

extern statetype s_force_field_1;
extern statetype s_force_field_2;
extern statetype s_force_field_3;
extern statetype s_force_field_4;
extern statetype s_force_field_die1;

statetype s_force_field_1 = {FORCE_FIELD_1PIC, 10, T_ForceField, &s_force_field_2};
statetype s_force_field_2 = {FORCE_FIELD_2PIC, 10, T_ForceField, &s_force_field_3};
statetype s_force_field_3 = {FORCE_FIELD_3PIC, 10, T_ForceField, &s_force_field_4};
statetype s_force_field_4 = {FORCE_FIELD_4PIC, 10, T_ForceField, &s_force_field_1};

statetype s_force_field_die = {0,0,T_ForceFieldRemove,&s_force_field_die1};
statetype s_force_field_die1 = {0,0,NULL,NULL};

void SpawnForceField(int tilex, int tiley)
{
	SpawnNewObj(tilex,tiley,&s_force_field_1,PIXRADIUS*35);
	new->obclass = solidobj;
	new->hitpoints = EasyHitPoints(20);
	new->flags |= of_forcefield;		//sets bit 7 :: makes it nonsolid, but also detectable
												//		without adding another object type!
	new->flags |= of_shootable;
}

void T_ForceField(objtype *ob)
{
	long move,deltax,deltay,size;

	size = (long)ob->size + player->size;

	deltax = ob->x - player->x;
	deltay = ob->y - player->y;

	if (deltax <= size && deltax >= -size
	&& deltay <= size && deltay >= -size)
		TakeDamage (20);

}

void T_ForceFieldRemove(objtype *ob)
{
	actorat[ob->tilex][ob->tiley] = 0;
}


//------------------------------------------------------------------------
//			SKELETON HANGING FROM CEILING
//------------------------------------------------------------------------

void SpawnSkeletonHanging(int tilex, int tiley);
void T_SkelHangThink(objtype *ob);

extern statetype s_skeleton_hanging;
statetype s_skeleton_hanging = {SKEL_HANGPIC, 20, T_SkelHangThink, &s_skeleton_hanging};

void SpawnSkeletonHanging(int tilex, int tiley)
{
	unsigned tile;

	SpawnNewObj(tilex,tiley,&s_skeleton_hanging,PIXRADIUS*35);
	new->obclass = solidobj;

	tile = *(mapsegs[2]+farmapylookup[tiley+1]+tilex);
	if (tile)
		new->temp1 = (tile>>8)*30;
	else
		new->temp1 = (3*60)+random(4*60);

	new->flags |= of_shootable;
}

void T_SkelHangThink(objtype *ob)
{
	ob->temp1 -= realtics;
	if (ob->temp1 <= 0)
	{
		ob->state = &s_skel_1;
		ob->ticcount = ob->state->tictime;
		ob->obclass = skeletonobj;
		ob->speed = 2036;
		ob->flags |= of_shootable;
		ob->hitpoints = EasyHitPoints(12);
	}
}


/////////////////////////////////////////////////////////////////////////////
//
//	EasyHitPoints
//
//	Checks to see if the player has selected the easy mode for playing.
//	If so then the normal hit points are cut in half.
//	This is when the object is spawned.
//
//	Parms
//		NrmHitPts - the normal hit points
//
//	Returns
//		Half of NrmHitPts
//
/////////////////////////////////////////////////////////////////////////////

int EasyHitPoints(int NrmHitPts)
{
	if (EASYMODEON)				// Wimpy, Wimpy, Wimpy!!!!!
	{
		return(NrmHitPts/4);
	}
	else
		return(NrmHitPts);
}

/////////////////////////////////////////////////////////////////////////////
//
//	EasyDoDamage
//
//	Checks to see if the player has selected the easy mode for playing.
//	If so then the normal amount of damage is cut in half.
//	This is called each time a monster does damage.
//
//	Parms
//		Damage - the normal damage taken
//
//	Returns
//		Half of Damage
//
/////////////////////////////////////////////////////////////////////////////

int EasyDoDamage(int Damage)
{
	if (EASYMODEON)				// Wimpy, Wimpy, Wimpy!!!!!
		return(Damage/2);
	else
		return(Damage);
}

