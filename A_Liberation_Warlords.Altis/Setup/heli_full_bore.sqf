_helo = _this # 0;
_helo allowdamage false;
sleep 0.5;
_helo setPosASL [getPos _helo select 0, getPos _helo select 1, 210];
_helo flyInHeight 210;
sleep 1;
_helo allowdamage true;