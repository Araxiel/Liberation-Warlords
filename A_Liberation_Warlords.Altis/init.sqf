// disable the usage of Freedom turrets.

[] spawn {
    if (!hasInterface) exitWith {};
    while {true} do {
        // Check if the player has an AV terminal
        if ("B_UavTerminal" in assignedItems player) then {
            // This code must be run each time the player gets a new AV terminal
            {player disableUAVConnectability [_x,true];} forEach [carrier_sam_0,carrier_sam_1,carrier_sam_2,carrier_sam_3,carrier_sam_4,carrier_sam_5,carrier_sam_6,destroyer_sam_1,destroyer_sam_2,destroyer_sam_3];
            while {("B_UavTerminal" in assignedItems player)} do {sleep 4;};
        };
        sleep 4;
    };
};