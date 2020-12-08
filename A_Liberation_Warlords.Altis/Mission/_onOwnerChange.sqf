if !( isServer ) exitWith {
	//Remote execute on the server
	_this remoteExec[ _fnc_scriptName, 2 ];
};

params [
	['_sector', objNull],
	['_owner', sideUnknown],
	['_oldOwner', sideUnknown],
	['_location', objNull]
];

diag_log format ["Sector: %1", _sector];

if !( _owner isEqualTo sideUnknown ) then {
	diag_log format ["%1 capped by %2 from %3!", format[ "str_%1",_location] call BIS_fnc_localize, _owner, _oldOwner];
	_trigger_unlock = format["%1_owner%2_v",_location,_owner]; // eg: area_hangars_ownerWEST_v
	diag_log format ["Unlock: %1", _trigger_unlock];
	call compile format [ "%1 = true", _trigger_unlock];
	publicVariable call compile str(_trigger_unlock);

	if ( locations_phase_0_and_1 findIf { _x == _location } > -1 && _owner == WEST) then {
		diag_log "Simple Landing Capped";
		[_location,_sector] execVM "Mission\Phase 1\phase_0_cap.sqf";
	};
};