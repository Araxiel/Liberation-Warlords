if !( isServer ) exitWith {
	//Remote execute on the server
	_this remoteExec[ _fnc_scriptName, 2 ];
};

private ['_sectors_only_west','_early_sectors'];
//create array with locations only capapble by west
_sectors_only_west = locations_phase_0 + [loc_molosair];
// create sectors
[_sectors_only_west,-1,[WEST]] execVM "Mission\_sector_maker.sqf";
[loc_iraklia,-1,[WEST, EAST], EAST] execVM "Mission\_sector_maker.sqf";
// create array with all the phase 1 sectors for the tasks
_early_sectors = locations_phase_0 + locations_phase_0_plus;
// make the task
{ 
	[ 
		west,
		[format["%1_tsk0",_x],"prnt_tks0"], // looks something like "loc_lbeach1_tsk0"
		format["%1_tsk0",_x],
		_x,
		"AUTOASSIGNED",
		2,
		false,
		"land",
		false
	] call BIS_fnc_taskCreate;
} forEach _early_sectors;

// enemy spawning
private["_locations_array","_amount"];
_locations_array = locations_phase_0 + [loc_molosair];

// random amount of location that get enemies, weighted with most basic of ways
_amount = selectRandom [0,1,2,2,2,3,3,3,4,4,4,5,6,7,8];

for "_i" from 0 to _amount-1 do
{
	private ['_location','_result','_type'];
	// remove current location from array
	_location = selectRandom _locations_array;
	_locations_array = _locations_array - [_location];
	// select what type of unit(s) will spawn
	_type = selectRandom ["Squad","Two Squad","Vehicle"];

	if (_type == "Squad") then {
		_infantry_group = [getPos _location, EAST, 6] call BIS_fnc_spawnGroup;
		_infantry_group deleteGroupWhenEmpty true;

		_wp = _infantry_group addWaypoint [getPos _location, 80];
		_wp setWaypointType "MOVE";
		_wp setWaypointBehaviour "SAFE";
	};
	if (_type == "Two Squad") then {
		_infantry_group = [getPos _location, EAST, 6] call BIS_fnc_spawnGroup;
		_infantry_group deleteGroupWhenEmpty true;

		_wp = _infantry_group addWaypoint [getPos _location, 60];
		_wp setWaypointType "MOVE";
		_wp setWaypointBehaviour "SAFE";

		_infantry_group = [getPos _location, EAST, 6] call BIS_fnc_spawnGroup;
		_infantry_group deleteGroupWhenEmpty true;

		_wp = _infantry_group addWaypoint [getPos _location, 350];
		_wp setWaypointType "MOVE";
		_wp setWaypointBehaviour "SAFE";
	};
	if (_type == "Vehicle") then {
		_infantry_group = [getPos _location, EAST, 2] call BIS_fnc_spawnGroup;
		_infantry_group deleteGroupWhenEmpty true;
		_wp = _infantry_group addWaypoint [getPos _location, 80];
		_wp setWaypointType "MOVE";
		_wp setWaypointBehaviour "SAFE";
		// select a random vehicle
  		_vehicle_class = ["O_MRAP_02_hmg_F","O_LSV_02_armed_F","O_APC_Wheeled_02_rcws_v2_F"] selectRandomWeighted [3,5,2];

		_result = [getPos _location, getDir _location, _vehicle_class, EAST] call BIS_fnc_spawnVehicle;
		_result params ["_vehicle", "_crew", "_group"];
		_result #2 deleteGroupWhenEmpty true;
		_wp = _result #2 addWaypoint [getPos _location, 200];
		_wp setWaypointType "MOVE";
		_wp setWaypointBehaviour "SAFE";
	};
	diag_log format ["%2 spawned at %1!", format[ "str_%1",_location] call BIS_fnc_localize, _type];
};