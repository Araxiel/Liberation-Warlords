// Script to send an order to the function make the sectors

if !( isServer ) exitWith {
	//Remote execute on the server
	_this remoteExec[ _fnc_scriptName, 2 ];
};

params [
	['_locations', objNull],
	['_amount', -1],
	['_sides', [ west, east, resistance]],
	[ '_defaultOwner', -1, [ 0, sideUnknown ] ]
];

private['_location','_locations_array'];

// initializing the array
_locations_array = [];

// checking if _locations are an array or just a single location
if !("ARRAY" == typeName _locations) then {
	_locations_array set [0, _locations];
} else {
	_locations_array = _locations
};
// if amount is -1 or larger than the array, make amount the entire array.
if ("SCALAR" != typeName _amount) then {
	_amount = count _locations_array;
} else {
	if (_amount == -1 or _amount >= count _locations_array) then {
		_amount = count _locations_array;
	};
};
// set's _defaultOwner to sideUnknown as a fallback
if ( _defaultOwner isEqualType sideUnknown ) then {
	if ( _defaultOwner isEqualTo sideUnknown ) then {
		_defaultOwner = -1;
	}else{
		_defaultOwner = _defaultOwner call BIS_fnc_sideID;
	};
};

for "_i" from 0 to _amount-1 do
{
	// for debugging
	diag_log format ["Starting Array: %1", _locations_array];
	// select a random element from the array
	_location = selectRandom _locations_array;
	diag_log format ["%1 creation started!", _location];

	[
		//name
		str(_location),
		//position
		getPosATL _location,
		//Sector Name, generated from stringTable 
		format[ "str_%1",_location] call BIS_fnc_localize,
		//Sector Designation, using first letter of Sector Name
		format[ "str_%1",_location] call BIS_fnc_localize select [0, 1],
		//Trigger dimensions, using the trigger "_location_t"
		triggerArea call compile format [ "%1_t", _location],
		//Sides that can capture
		_sides,
		//Default owning side (e.g. sideUnknown)
		_defaultOwner,
		//Code as STRING called when sector owner changes
		format ["
			params[ '_sector', '_owner', '_oldOwner','_location'];
			[_sector, _owner, _oldOwner, %1] execVM 'Mission\_onOwnerChange.sqf';", _location
		],
		1,
		// Task block
		0,
		"",
		"",
		// _ownerLimit
		0.5,
		// costs - Inf/Wheel/Track/Water/Air/Player
		1,2,4,1,0,0.5
	] call LARs_fnc_spawnSector;
	//remove current location from array
	_locations_array = _locations_array - [_location];
	diag_log format ["%1 creation finished!", _location];
	diag_log format ["Ending Array: %1", _locations_array];
};