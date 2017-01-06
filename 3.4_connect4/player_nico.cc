#include "player_nico.h"
#include <regex>

int player_nico::play(const playfield &field){
	for(int x = 0; x < field.width; x++){
		int y = getFreeHeight(x, field);
		if(y>-1 && check(x,y,player_id, 0, 0, field) == 1){
			return x;
		}
	}
	for(int x = 0; x < field.width; x++){
		int y = getFreeHeight(x, field);
		if(y > -1 && check(x,y,player_id % 2 + 1, 0, 0, field) == 1){
			return x;
		}
	}
	return rand() % field.width;
}

int player_nico::check(int x, int y, int player, int offset_x, int offset_y, const playfield& field){
	if(offset_y == 0 && offset_x == 0){
		return int(check(x-1, y, player, -1, 0, field) + check(x+1, y, player, 1, 0, field) >= 3 || // horizontally
			 check(x, y-1, player, 0, -1, field) + check(x, y+1, player, 0, 1, field) >= 3 || // vertically
			 check(x-1, y-1, player, -1, -1, field) + check(x+1, y+1, player, 1, 1, field) >= 3 || // diagonally (\)
			 check(x+1, y-1, player, 1, -1, field) + check(x-1, y+1, player, -1, 1, field) >= 3); // diagonally (/)
	}
	else{
		if(x<0||y<0||x>field.width||y>field.height) return 0;
		if(field.stoneat(x,y) == player){
			return 1 + check(x+offset_x, y+offset_y, player, offset_x, offset_y, field);
		} 
		return 0;
	}
}

int player_nico::getFreeHeight(int col, const playfield &field){
	for(int i = field.height-1;i>=0;i--){
		if(field.stoneat(col, i) == 0) return i;
	}
	return -1;
}

player *player_nico::make(const char *plr)
{
	if(plr[0]!='N') return NULL;

	std::string p(plr);
	std::regex e("[0-9]+");
	std::smatch matches;
	std::regex_search(p, matches, e);
	int player_id=atoi(matches.str(0).c_str());

	std::cout << player_id;

	return new player_nico(player_id);
}