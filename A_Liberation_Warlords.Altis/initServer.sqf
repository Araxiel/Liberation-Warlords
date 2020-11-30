//Loadouts
[west, ["Blufor1",-1,-1]] call BIS_fnc_addRespawnInventory;
[west, ["Blufor2",-1,-1]] call BIS_fnc_addRespawnInventory;


//Mission params
/*  TODO
_paramsArray = [[paramsArray],0,[],[[]]];
_hour = [paramsArray,2,5,[0]] call bis_fnc_param;
_date = date;
_date set [2,(_date select 2) + 1];
_date set [3,_hour];
setdate _date;
*/

//Car alarms
{
	_x setVariable ["BIS_alarmEventHandler", _x addEventHandler ["Hit", {
		//The car
		private "_car";
		_car = _this select 0;

		//Remove event handler
		_car removeEventHandler ["Hit", _car getVariable "BIS_alarmEventHandler"];

		//Execute alarm script
		[[[_car], "Setup\carAlarm.sqf"], "BIS_fnc_execVM"] call BIS_fnc_mp;

		//Log
		["Car (%1) alarm went off at %2", _car, time] call BIS_fnc_logFormat;
	}]];
} forEach [
	civ_car_1
];
