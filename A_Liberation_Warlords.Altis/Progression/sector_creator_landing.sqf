_pos = getPos player;

//Create the sector logic
"ModuleSector_F" createUnit [ _pos, createGroup sideLogic, "
		
		this setVariable[ 'DefaultOwner', '-1' ];
		this setVariable[ 'OnOwnerChange', '' ];
		this setVariable[ 'OwnerLimit', '0' ];
		this setVariable[ 'ScoreReward', '5' ];
		this setVariable[ 'TaskOwner', '0' ];
		this setVariable[ 'sides', [ east, west ] ];
		
		this setVariable[ 'BIS_fnc_initModules_disableAutoActivation', false, true ];
		
		_nul = [ this ] spawn {
			params[ '_logic' ];
			
			waitUntil {
				!isNil { _logic getVariable [ 'finalized', nil ] } &&
				{ !( _logic getVariable [ 'finalized', true ] ) }
			};

			_trgSize = 500;
			_logic setVariable [ 'size', _trgSize ];
			[ _logic, [], true, 'area' ] call BIS_fnc_moduleSector;

			_trg = ( _logic getVariable 'areas' ) select 0;
			_mrk = ( _trg getVariable 'markers' ) select 0;
			_mrk setMarkerSize [ _trgSize, _trgSize ];
		};
" ];