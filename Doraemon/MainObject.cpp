#include "MainObject.h"
#include "Game.h"


// Nhân vật sẽ có hai tọa độ riêng biệt
///<\sumary>
///	x_pos và y_pos là tọa độ của nhân vật trên màn hình
/// map_x_pos và map_y_pos là tọa độ của nhân vật trên map
/// x_pos và y_pos sẽ giới hạn trong kích thước màn hình
/// map_x_pos và map_y_pos sẽ giới hạn trong kích thước của map
///<\sumary>


MainObject::MainObject()
{
	x_pos = 0;
	y_pos = 0;
	x_val = 0;
	y_val = 0;

	map_x_pos = 0;
	map_y_pos = 0;

	movement.down = 0;
	movement.left = 0;
	movement.right = 0;
	movement.up = 0;

	setColisionBox(0, 54, 39, 3);
	loadAnimation();
	main_ani = &stand;

	main_speed = PLAYER_SPEED;
}

MainObject::~MainObject()
{

}

void MainObject::loadAnimation()
{
	walkdown.setFrameSheet(1, 18);
	walkdown.setFrameSize(39, 57);
	walkdown.loadTexture("acces/walk_down.png");

	walkup.setFrameSheet(1, 18);
	walkup.setFrameSize(39, 57);
	walkup.loadTexture("acces/walk_up.png");

	stand.setFrameSheet(1, 18);
	stand.setFrameSize(39, 57);
	stand.loadTexture("acces/stand.png");

	walkright.setFrameSheet(1, 18);
	walkright.setFrameSize(39, 57);
	walkright.loadTexture("acces/walk_right.png");

	walkleft.setFrameSheet(1, 18);
	walkleft.setFrameSize(39, 57);
	walkleft.loadTexture("acces/walk_left.png");
}

void MainObject::handleInputAction(SDL_Event& window_event)
{
	/// <summary>
	/// Xử lý sự kiện bàn phím
	/// </summary>
	/// <param name="window_event"></param>
	
	switch (window_event.type)
	{
		case SDL_KEYDOWN:
		{
			switch (window_event.key.keysym.sym)
			{
				case SDLK_UP:
					movement.up = 1;
					break;
				case SDLK_DOWN:
					movement.down = 1;
					break;
				case SDLK_LEFT:
					movement.left = 1;
					break;
				case SDLK_RIGHT:
					movement.right = 1;
					break;
			}
			break;
		}
		case SDL_KEYUP:
		{
			switch (window_event.key.keysym.sym)
			{
			case SDLK_UP:
				movement.up = 0;
				break;
			case SDLK_DOWN:
				movement.down = 0;
				break;
			case SDLK_LEFT:
				movement.left = 0;
				break;
			case SDLK_RIGHT:
				movement.right = 0;
				break;
			}
			break;
		}
	}
}

void MainObject::move(GameMap &map_data, ObjectList& obj_list)
{
	// Tính toán vị trí của nhân vật sau khi bấm các phím di chuyển
	
	x_val = 0;
	y_val = 0;

	if (movement.down)
	{
		y_val += main_speed;
	}
	if (movement.up)
	{
		y_val -= main_speed;
	}
	if (movement.left)
	{
		x_val -= main_speed;
	}
	if (movement.right)
	{
		x_val += main_speed;
	}

	//	Nếu nhân vật va phải các chướng ngại vật trên bản đồ thì không thể đi tiếp
	if (checkColision(map_data, obj_list))
	{
		//main_speed = 1;
		return;
	}

	if (movement.up || movement.down || movement.left || movement.right)
	{
		main_speed = PLAYER_SPEED;
	}
		
	x_pos += x_val;
	y_pos += y_val;
	
	
	
	if (x_pos < 0) x_pos = 0;
	else if (x_pos + main_ani->getFrameWidth() > Window::getWindowWidth())
	{
		x_pos = Window::getWindowWidth() - main_ani->getFrameWidth();
	}
	//	Nếu nhân vật di chuyển thành công thì tính tọa độ map của nhân vật
	else map_x_pos += x_val;

	if (y_pos < 0) y_pos = 0;
	else if (y_pos + main_ani->getFrameHeight() > Window::getWindowHeight())
	{
		y_pos = Window::getWindowHeight() - main_ani->getFrameHeight();
	}
	//	Nếu nhân vật di chuyển thành công thì tính tọa độ map của nhân vật
	else map_y_pos += y_val;
}

void MainObject::doThing(GameMap& map_data, ObjectList &obj_list)
{
	/// <summary>
	/// Xử lý nhân vật sau mỗi vòng lặp
	/// </summary>
	/// <param name="map_data"></param>
	// Di chuyển
	move(map_data, obj_list);
	//	Đặt frame
	checkAnimation();
	//	Di chuyển bản đồ
	if (x_pos > Window::getWindowWidth() / 2 && movement.right 
		|| movement.left && x_pos < Window::getWindowWidth() / 2)
	{
		//	Nếu xảy ra va chạm thì bản đồ không di chuyển
		if (checkColision(map_data, obj_list))
		{
			return;
		}
		if (map_data.cameraMove(x_val, 0))
		{
			x_pos -= x_val;
		}
	}
	if (y_pos > Window::getWindowHeight() / 2 && movement.down
		|| movement.up && y_pos < Window::getWindowHeight() / 2)
	{
		//	Nếu xảy ra va chạm thì bản đồ không di chuyển
		if (checkColision(map_data, obj_list))
		{
			return;
		}
		
		if (map_data.cameraMove(0, y_val))
		{
			y_pos -= y_val;
		}
	}

}

void MainObject::checkAnimation()
{
	// Đặt animation phù hợp với các hoạt động của nhân vật
	if (movement.down)
	{
		main_ani = &walkdown;
	}
	else if (movement.up)
	{
		main_ani = &walkup;
	}
	else if (movement.right)
	{
		main_ani = &walkright;
	}
	else if (movement.left)
	{
		main_ani = &walkleft;
	}
	else
	{
		main_ani = &stand;
	}
}

bool MainObject::checkColision(GameMap &map_data, ObjectList& obj_list)
{
	if (checkMapColision(map_data)) return true;
	if (checkObjectListColision(obj_list)) return true;

	return false;
}

bool MainObject::checkMapColision(GameMap& map_data)
{
	// Kiểm tra va chạm với map
	int tile_row;
	int tile_col;
	Tile current_tile;
	int x = map_x_pos + x_val;
	int y = map_y_pos + y_val;

	// x,y* * * * * * *
	//  *		      *
	//  *   nhân vật  *
	//  * 		      *
	//  *		      *
	//  * * * * * * * x_width, y_width

	int x_width, y_width;

	//	Va chạm phía trái trên
	tile_col = x / TILE_SIZE;
	tile_row = y / TILE_SIZE;
	current_tile = map_data.getTile(tile_col, tile_row);
	if (checkTileColision(current_tile)) return true;
	
	//	Va chạm phía trái dưới
	//	Check left down
	tile_col = x / TILE_SIZE;
	y_width = y + main_ani->getFrameHeight();
	tile_row = y_width / TILE_SIZE;
	current_tile = map_data.getTile(tile_col, tile_row);
	if (checkTileColision(current_tile)) return true;

	//	Va chạm phải trên
	//	Check right up
	x_width = x + main_ani->getFrameWidth();
	tile_col = x_width / TILE_SIZE;
	tile_row = y / TILE_SIZE;
	current_tile = map_data.getTile(tile_col, tile_row);
	if (checkTileColision(current_tile)) return true;

	//	Va chạm phải dưới
	//	Check right down
	x_width = x + main_ani->getFrameWidth();
	y_width = y + main_ani->getFrameHeight();
	tile_col = x_width / TILE_SIZE;
	tile_row = y_width / TILE_SIZE;
	current_tile = map_data.getTile(tile_col, tile_row);
	if (checkTileColision(current_tile)) return true;

	return false;
}

bool MainObject::checkTileColision(Tile &tile)
{
	SDL_Rect this_obj = colision_box;
	SDL_Rect other_obj = tile.colision_box;

	if (other_obj.w == 0 || other_obj.h == 0) return false;

	this_obj.x += map_x_pos + x_val;
	this_obj.y += map_y_pos + y_val;
	other_obj.x += tile.rect.x;
	other_obj.y += tile.rect.y;

	//	Va chạm phải dưới 
	if (this_obj.x <= other_obj.x && other_obj.x <= this_obj.x + this_obj.w - 1
		&& this_obj.y <= other_obj.y && other_obj.y <= this_obj.y + this_obj.h -1)
	{
		return true;
	}

	//	Va chạm trái dưới
	if (other_obj.x <= this_obj.x && this_obj.x <= other_obj.x + other_obj.w - 1
		&& this_obj.y <= other_obj.y && other_obj.y <= this_obj.y + this_obj.h - 1)
	{
		return true;
	}

	//	Va chạm trái trên
	if (other_obj.x <= this_obj.x && this_obj.x <= other_obj.x + other_obj.w - 1
		&& other_obj.y <= this_obj.y && this_obj.y <= other_obj.y + other_obj.h - 1)
	{
		return true;
	}

	//	Va chạm phải trên
	if (this_obj.x <= other_obj.x && other_obj.x <= this_obj.x + this_obj.w - 1
		&& other_obj.y <= this_obj.y && this_obj.y <= other_obj.y + other_obj.h - 1)
	{
		return true;
	}

	return false;
}

bool MainObject::checkObjectListColision(ObjectList &object_list)
{
	for (int i = 0; i < object_list.object_list.size(); ++i)
	{
		if (checkObjectColision(*object_list.object_list[i])) return true;
	}
	return false;
}

void MainObject::render(int layer)
{
	SDL_Rect render_clip = main_ani->getCurrentRect();
	main_ani->setRenderRect(x_pos, y_pos, MAIN_FRAME_WIDTH, MAIN_FRAME_HEIGHT);

	Game::draw_queue.addToQueue(main_ani->getTexture(), main_ani->getRenderRect(), layer, render_clip);

	main_ani->frameIncrease();
}