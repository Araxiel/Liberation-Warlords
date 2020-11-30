class CfgORBAT
{
	//Inspired by 25th Infantry Div.
	//http://en.wikipedia.org/wiki/25th_Infantry_Division_%28United_States%29
	//keep in mind https://en.wikipedia.org/wiki/Military_organization

	class 31division
	{
		id = 31;
				// Unit ID
		idType = 0;
				// Unit ID type
				//	0 - show as ordinal number, e.g. "7th" (default)
				//	1 - show as roman numeral, e.g. "VII"
				//	2 - show as NATO phonetical alphabet word, e.g. "Golf"
		side = "West";
		size = "Division";
		type = "HQ";
		texture = "StormOwlRey2.paa";
				// Unit insignia, displayed in ORBAT background and in tooltip
		commander = "Armstrong";
				// Name of unit commander
				// - can be either direct name, or class from CfgWords >> GenericNames (random name from the list is then selected)
		//commanderRank = "General";
				// Rank of unit commander (by default selected based on unit size)
		text = "%1 %2 %3";
		textShort = "%1 %3";
				// ALTERNATIVE SETTINGS
				// Custom text and short text, can still use some arguments when defined:
				// 	%1 - ID (e.g. "7th")
				// 	%2 - Type (e.g. "Infantry")
				// 	%3 - Size (e.g. "Division")
		//assets = {""};
				//Possible assets shown in the ORBAT viewer, taken from CfgVehicles

		// When 'subordinates' are missing, child classes will be used. They can have their own subs - number of tiers is not limited.

		class 1bri
		{
			id = 1;
			side = "West";
			type = "MechanizedInfantry";
			size = "BCT";
			commander = "NATOMen";
			color[] = {0.6,0.5,0.7,1};

			class 1briHQ
			{
				id = 1;
				side = "West";
				type = "HQ";
				size = "Company";
				commander = "NATOMen";
				text = "Brigade Headquarters and Headquarters %3";
				textShort = "%2";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briRec
			{
				id = 1;
				side = "West";
				type = "Cavalry";
				size = "Squadron";
				commander = "NATOMen";
				text = "1st Squadron, 7th Cavalry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briMech1
			{
				id = 1;
				side = "West";
				type = "MechanizedInfantry";
				size = "Battalion";
				commander = "NATOMen";
				text = "1st Battalion, 6th Infantry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briMech2
			{
				id = 1;
				side = "West";
				type = "MechanizedInfantry";
				size = "Battalion";
				commander = "NATOMen";
				text = "1st Battalion, 9th Infantry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briMech3
			{
				id = 3;
				side = "West";
				type = "MechanizedInfantry";
				size = "Battalion";
				commander = "NATOMen";
				text = "3rd Battalion, 23th Infantry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briArty
			{
				id = 2;
				side = "West";
				type = "Artillery";
				size = "Battalion";
				commander = "NATOMen";
				text = "2nd Battalion, 9th Field Artillery Rgt.";
				textShort = "%1 %2 %3";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briSup
			{
				id = 31;
				side = "West";
				type = "Support";
				size = "Battalion";
				commander = "NATOMen";
				text = "31st Brigade, Support Battalion";
				textShort = "Support";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briMotor
			{
				id = 1;
				side = "West";
				type = "MotorizedInfantry";
				size = "Company";
				idType = 2;
				commander = "NATOMen";
				text = "A Company, 64th Infantry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briEngi
			{
				id = 82;
				side = "West";
				type = "Maintenance";
				size = "Company";
				commander = "NATOMen";
				text = "82nd Engineer";
				textShort = "%1 Engineer";
				color[] = {0.6,0.5,0.7,1};
			};
			class 1briServ
			{
				id = 110;
				side = "West";
				type = "Service";
				size = "Company";
				commander = "NATOMen";
				text = "110th Signal Company";
				textShort = "110th %3";
				color[] = {0.6,0.5,0.7,1};
			};
		};
		//-----------Player Brigade-------------------
		class 2bri
		{
			id = 2;
			side = "West";
			type = "MechanizedInfantry";
			size = "BCT";
			commander = "NATOMen";
			color[] = {0.39,0.78,0.39,1};
			assets[] = {"B_Heli_Transport_01_camo_F","B_Heli_Light_01_F","B_Heli_Transport_03_F","B_Heli_Attack_01_F"};

			class 2briHQ
			{
				id = 1;
				side = "West";
				type = "HQ";
				size = "Battalion";
				commander = "NATOMen";
				text = "Brigade Headquarters and Headquarters %3";
				textShort = "HQ";
				color[] = {0.39,0.78,0.39,1};
			};
			class 2briRec
			{
				id = 2;
				side = "West";
				type = "Recon";
				size = "Squadron";
				commander = "NATOMen";
				text = "2nd Squadron, 11th Cavalry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.39,0.78,0.39,1};
			};
			class 2briMech1
			{
				id = 1;
				side = "West";
				type = "MechanizedInfantry";
				size = "Battalion";
				commander = "NATOMen";
				text = "1st Battalion, 27th Infantry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.39,0.78,0.39,1};
			};
			//Player Battalion
			class 2briMech2
			{
				id = 5;
				side = "West";
				type = "MechanizedInfantry";
				size = "Battalion";
				commander = "Highstein";
				text = "5th Battalion, 29th Infantry Regiment";
				textShort = "%1 %2 %3";

				class 2briMech2HQ
				{
					id = 1;
					side = "West";
					type = "HQ";
					size = "Company";
					commander = "NATOMen";
					text = "%2 %3";
					textShort = "%2 %3";
				};
				class 2briMech2CompA
				{
					id = 1;
					side = "West";
					type = "MechanizedInfantry";
					size = "Company";
					idType = 2;
					commander = "NATOMen";
					text = "%1 %3";
					textShort = "%1 %3";
				};
				class 2briMech2CompB
				{
					id = 2;
					side = "West";
					type = "MechanizedInfantry";
					size = "Company";
					idType = 2;
					commander = "NATOMen";
					text = "%1 %3";
					textShort = "%1 %3";
				};
				//Player Company
				class 2briMech2CompC
				{
					id = 3;
					side = "West";
					type = "Infantry";
					size = "Company";
					idType = 2;
					commander = "NATOMen";
					text = "%1 %3";
					textShort = "%1 %3";

					class CompCPlatHQ
					{
						id = 1;
						side = "West";
						type = "HQ";
						size = "Platoon";
						idType = 0;
						commander = "NATOMen";
						text = "%3";
						textShort = "Coy. %2";
					};
					class CompCPlat1
					{
						id = 1;
						side = "West";
						type = "Infantry";
						size = "Platoon";
						idType = 0;
						commander = "NATOMen";
						text = "%1 %3";
						textShort = "%1 %3";
					};
					class CompCPlat2
					{
						id = 2;
						side = "West";
						type = "Infantry";
						size = "Platoon";
						idType = 0;
						commander = "NATOMen";
						text = "%1 %3";
						textShort = "%1 %3";
					};
					class CompCPlat3
					{
						id = 3;
						side = "West";
						type = "Infantry";
						size = "Platoon";
						idType = 0;
						commander = "NATOMen";
						text = "%1 %3";
						textShort = "%1 %3";
					};
					class CompCPlat4
					{
						id = 4;
						side = "West";
						type = "Infantry";
						size = "Platoon";
						idType = 0;
						commander = "NATOMen";
						text = "Weapons %3";
						textShort = "Wep %3";
					};
				};
				class 2briMech2CompSup
				{
					id = 1;
					side = "West";
					type = "Infantry";
					size = "Company";
					idType = 2;
					commander = "NATOMen";
					text = "Support Weapons %3";
					textShort = "Weapons %3";
				};
				class 2briMech2CompAdmin
				{
					id = 1;
					side = "West";
					type = "Service";
					size = "Company";
					idType = 2;
					commander = "NATOMen";
					text = "Administrative %3";
					textShort = "Weapons %3";
				};
			};
			class 2briArm
			{
				id = 2;
				side = "West";
				type = "Armored";
				size = "Squadron";
				commander = "NATOMen";
				text = "2nd Squadron, 23rd Cavalry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.39,0.78,0.39,1};

					class 2briArm1Troop
					{
						id = 1;
						side = "West";
						type = "Armored";
						size = "Company";
						idType = 1;
						commander = "NATOMen";
						text = "%1 Troop";
						textShort = "%1 Troop";
					};
					class 2briArm2Troop
					{
						id = 2;
						side = "West";
						type = "Armored";
						size = "Company";
						idType = 1;
						commander = "NATOMen";
						text = "%1 Troop";
						textShort = "%1 Troop";
					};
			};
			class 2briArty
			{
				id = 2;
				side = "West";
				type = "Artillery";
				size = "Company";
				commander = "NATOMen";
				text = "2nd Battalion, 12th Field Artillery Rgt.";
				textShort = "%1 %2 %3";
				color[] = {0.39,0.78,0.39,1};
			};
			class 2briSup
			{
				id = 106;
				side = "West";
				type = "Support";
				size = "Company";
				commander = "NATOMen";
				text = "106th Brigade, Support Battalion";
				textShort = "%2";
				color[] = {0.39,0.78,0.39,1};
			};
			class 2briMotor
			{
				id = 3;
				side = "West";
				type = "MotorizedInfantry";
				size = "Company";
				idType = 2;
				commander = "NATOMen";
				text = "C Company, 64th Infantry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.39,0.78,0.39,1};
			};
			class 2briEngi
			{
				id = 54;
				side = "West";
				type = "Maintenance";
				size = "Company";
				commander = "NATOMen";
				text = "54th Engineer";
				textShort = "%1 Engineer";
				color[] = {0.39,0.78,0.39,1};
			};
			class 2briServ
			{
				id = 325;
				side = "West";
				type = "Service";
				size = "Company";
				commander = "NATOMen";
				text = "325th Signal Company";
				textShort = "%1 %3";
				color[] = {0.39,0.78,0.39,1};
			};
 		};
		class 3bri
		{
			id = 3;
			side = "West";
			type = "MotorizedInfantry";
			size = "Brigade";
			commander = "NATOMen";
			color[] = {0.19,0.62,0.62,1};

			class 3briHQ
			{
				id = 1;
				side = "West";
				type = "HQ";
				size = "Company";
				commander = "NATOMen";
				text = "3rd Brigade Infantry Battalion";
				textShort = "HQ";
				color[] = {0.19,0.62,0.62,1};
			};
			class 3briRec
			{
				id = 3;
				side = "West";
				type = "Recon";
				size = "Squadron";
				commander = "NATOMen";
				text = "3rd Squadron, 16th Cavalry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.19,0.62,0.62,1};
			};
			class 3briInf1
			{
				id = 2;
				side = "West";
				type = "Infantry";
				size = "Battalion";
				commander = "NATOMen";
				text = "2nd Battalion, 27th Infantry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.19,0.62,0.62,1};
			};
			class 3briInf2
			{
				id = 2;
				side = "West";
				type = "Infantry";
				size = "Battalion";
				commander = "NATOMen";
				text = "2nd Battalion, 34th Infantry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.19,0.62,0.62,1};
			};
			class 3briArty
			{
				id = 3;
				side = "West";
				type = "Artillery";
				size = "Battalion";
				commander = "NATOMen";
				text = "3rd Battalion, 16th Field Artillery Rgt.";
				textShort = "%1 %2 %3";
				color[] = {0.19,0.62,0.62,1};
			};
			class 3briSup
			{
				id = 322;
				side = "West";
				type = "Support";
				size = "Battalion";
				commander = "NATOMen";
				text = "322nd Brigade, Support Battalion";
				textShort = "Support";
				color[] = {0.19,0.62,0.62,1};
			};
 		};
		//player heli brigade
		class 4bri
		{
			id = 4;
			side = "West";
			type = "CombatAviation";
			size = "Regiment";
			commander = "NATOMen";
			color[] = {0.07,0.39,0.98,1};

			class 4briHQ
			{
				id = 1;
				side = "West";
				type = "HQ";
				size = "Company";
				commander = "NATOMen";
				text = "Wing Headquarters";
				textShort = "HQ";
				color[] = {0.07,0.39,0.98,1};
			};
			class 4briRecon
			{
				id = 2;
				side = "West";
				type = "AttackRecon";
				size = "Squadron";
				commander = "NATOMen";
				text = "2nd Recon Squadron, 22nd Cavalry Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.07,0.39,0.98,1};
			};
			class 4briHeli1
			{
				id = 1;
				side = "West";
				type = "Helicopter";
				size = "Squadron";
				commander = "NATOMen";
				text = "1st Attack Squadron, 3nd Aviation Regiment";
				textShort = "%1 %3";
				color[] = {0.07,0.39,0.98,1};
			};
			class 4briHeli2
			{
				id = 2;
				side = "West";
				type = "Assault";
				size = "Squadron";
				commander = "NATOMen";
				text = "2nd Assault Squadron, 26th Aviation Regiment";
				textShort = "%1 %2 %3";
				color[] = {0.07,0.39,0.98,1};
			};
			//player support helis
			class 4briHeli3
			{
				id = 3;
				side = "West";
				type = "AviationSupport";
				size = "Squadron";
				commander = "NATOMen";
				text = "1st Support Squadron, 4th Aviation Regiment";
				textShort = "%1 Support %3";
				color[] = {0.07,0.39,0.98,1};
			};
			class 4briHeli4
			{
				id = 4;
				side = "West";
				type = "GeneralSupport";
				size = "Squadron";
				commander = "NATOMen";
				text = "3nd Combat Squadron, 26th Aviation Regiment";
				textShort = "%1 CAS %3";
				color[] = {0.07,0.39,0.98,1};
			};
		};
		class 5air
		{
			id = 1;
			side = "West";
			type = "Fighter";
			size = "Squadron";
			commander = "NATOMen";
			text = "Air Support";
			textShort = "%1 %2 %3";
			color[] = {0.62,0.70,0.82,1};
		};
	};
};
