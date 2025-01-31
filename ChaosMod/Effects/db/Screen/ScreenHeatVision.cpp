#include <stdafx.h>

#include "Effects/Register/RegisterEffect.h"

static void OnStop()
{
	SET_SEETHROUGH(false);
}

static void OnTick()
{
	SET_SEETHROUGH(true);
}

// clang-format off
REGISTER_EFFECT(nullptr, OnStop, OnTick, 
	{
		.Name = "Heat Vision",
		.Id = "player_heatvision",
		.IsTimed = true,
		.IsShortDuration = true
	}
);