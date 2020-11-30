class CfgRoles
{
	class Assault // Class name used in CfgRespawnInventory
	{
		displayName = $STR_A3_Role_Assault; // Name of the role, displayed in the respawn menu
		icon = "a3\missions_f_exp\data\img\classes\assault_ca.paa"; // Icon shown next to the role name in the respawn screen
	};
};
 
class CfgRespawnInventory
{
	class Blufor1
	{
		displayName = "Light";									// Name visible in the menu
		icon = "\A3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa";	// Icon displayed next to the name
		role = "Assault";										// Optional, see CfgRoles

		// Loadout definition, uses same entries as CfgVehicles classes
		weapons[] = {
			"arifle_MXC_F",
			"Binocular"
		};
		magazines[] = {
			"30Rnd_65x39_caseless_mag",
			"30Rnd_65x39_caseless_mag",
			"SmokeShell"
		};
		items[] = {
			"FirstAidKit"
		};
		linkedItems[] = {
			"V_Chestrig_khk",
			"H_Watchcap_blk",
			"optic_Aco",
			"acc_flashlight",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
		uniformClass = "U_B_CombatUniform_mcam_tshirt";
		backpack = "B_AssaultPack_mcamo";
	};
	class Blufor2
	{
		// Alternative configuration pointing to a CfgVehicles class. Loadout will be copied from it.
		vehicle = "B_soldier_AR_F"
	};
};