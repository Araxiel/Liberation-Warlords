//server starting
diag_log "----------- MAP START -------------------------------------------------------------------------------------------------------------------------";

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

// disable the usage of Freedom turrets.

[] spawn {
    if (!hasInterface) exitWith {};
    while {true} do {
        // Check if the player has an AV terminal
        if ("B_UavTerminal" in assignedItems player) then {
            // This code must be run each time the player gets a new AV terminal
            {player disableUAVConnectability [_x,true];} forEach [carrier_sam_0,carrier_sam_1,carrier_sam_2,carrier_sam_3,carrier_sam_4,carrier_sam_5,carrier_sam_6];
            while {("B_UavTerminal" in assignedItems player)} do {sleep 3;};
        };
        sleep 3;
    };
}; 

// global variables
store_unlocked_carrierfixedwing = false;
store_unlocked_carrierchopper = false;
destroyer_arrived = false;

execVM "Mission\location_init.sqf";