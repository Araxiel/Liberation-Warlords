// called on first capping of one of the basic landings (not airstrip or town)

params [
	['_location', objNull],
	['_sector', objNull]
];

// complete task
[format ["%1_tsk0", _location],"SUCCEEDED"] call BIS_fnc_taskSetState;
// delete all the other
private ['_leftover_array'];
_leftover_array = locations_phase_0;
_leftover_array = _leftover_array - [_location];
{ 
	[format["%1_tsk0",_x]] call BIS_fnc_deleteTask;
	private _obj = missionNamespace getVariable [format ["%1_sector", _x], objNull];
	deleteVehicle _obj;
} forEach _leftover_array;

_leftover_array = locations_phase_0_plus - [_location];
{ 
	[format["%1_tsk0",_x]] call BIS_fnc_deleteTask;
} forEach _leftover_array;

// make spawn point
_respawn = [WEST,getPos _location,format["STR_%1",_location] call BIS_fnc_localize] call BIS_fnc_addRespawnPosition;
// make new objectives
sleep 2;
[ 
	west,  
	["prnt_tks1"], // looks something like "loc_lbeach1_tsk0"
	"",
	objNull,
	"ASSIGNED",  
	2,  
	true,  
	"move1",  
	false 
] call BIS_fnc_taskCreate; 

{ 
	[ 
		west,  
		[format["%1_tsk1",_x],"prnt_tks1"], // looks something like "loc_lbeach1_tsk0"
		format["%1_tsk1",_x], 
		_x, 
		"AUTOASSIGNED",  
		1.5,  
		false,  
		"attack",  
		false 
	] call BIS_fnc_taskCreate; 
	sleep 1;
} forEach locations_phase_1;

_locations_phase_1_wo_0 = locations_phase_1 - locations_phase_0_plus;
[_locations_phase_1_wo_0,-1,[WEST, EAST], EAST] execVM "Mission\_sector_maker.sqf";