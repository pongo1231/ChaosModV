#include <stdafx.h>

#include "Effects/Register/RegisterEffect.h"

static void OnStart()
{
	for (Ped ped : GetAllPeds())
	{
		if (!IS_PED_A_PLAYER(ped))
		{
			CLEAR_PED_TASKS(ped);

			SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped, true);
		}
	}
}

static void OnStop()
{
	SET_EVERYONE_IGNORE_PLAYER(PLAYER_ID(), false);

	for (Ped ped : GetAllPeds())
	{
		if (!IS_PED_A_PLAYER(ped))
		{
			SET_PED_SEEING_RANGE(ped, 9999.f);
			SET_PED_HEARING_RANGE(ped, 9999.f);

			SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped, false);
			SET_PED_SHOOT_RATE(ped, 100);
			SET_PED_FIRING_PATTERN(ped, -957453492);
		}
	}
}

static void OnTick()
{
	SET_EVERYONE_IGNORE_PLAYER(PLAYER_ID(), true);

	for (Ped ped : GetAllPeds())
	{
		if (!IS_PED_A_PLAYER(ped))
		{
			SET_PED_SEEING_RANGE(ped, .0f);
			SET_PED_HEARING_RANGE(ped, .0f);

			SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped, true);
			SET_PED_SHOOT_RATE(ped, 0);
			SET_PED_FIRING_PATTERN(ped, -490063247);
		}
	}
}

// clang-format off
REGISTER_EFFECT(OnStart, OnStop, OnTick, 
	{
		.Name = "Blind Peds",
		.Id = "peds_blind",
		.IsTimed = true
	}
);