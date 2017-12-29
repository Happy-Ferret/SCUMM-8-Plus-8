#include <genesis.h>

void reset_ui();

// debugging
int show_debuginfo = TRUE;
int show_collision = FALSE;
//show_pathfinding = true
int show_perfinfo = TRUE;
int enable_mouse = TRUE;
int enable_diag_squeeze = FALSE;	// allow squeeze through diag gap?
//d = printh;

// game verbs (used in room definitions and ui)
/*verbs = {
	// {verb = verb_ref_name}, text = display_name
	{ { open = "open" }, text = "open" },
	{ { close = "close" }, text = "close" },
	{ { give = "give" }, text = "give" },
	{ { pickup = "pickup" }, text = "pick-up" },
	{ { lookat = "lookat" }, text = "look-at" },
	{ { talkto = "talkto" }, text = "talk-to" },
	{ { push = "push" }, text = "push" },
	{ { pull = "pull" }, text = "pull"},
	{ { use = "use" }, text = "use"}
}
// verb to use when just clicking around (e.g. move actor)
verb_default = {
	{ walkto = "walkto" }, text = "walk to"
}*/

void reset_ui() {
	int verb_maincol = 12;  // main colour (light blue)
	int verb_hovcol = 7;    // hover colour (white)
	int verb_shadcol = 1;   // shadow (dark blue)
	int verb_defcol = 10;   // default action (yellow)
}

// room & object definitions //
// [ ground floor ]
	// hall
		// objects
			struct obj_data {
                char name[12];
                char state[12];
                int x;
                int y;
                int z;
                int w;
                int h;
                int state_closed;
                char use_pos[12];
                char use_dir[12];
                char *classes[12];
            };

            struct room {
                struct obj_data data;
				//init = function(me)
				//	me.target_door = obj_front_door
				//end
			};

            struct room obj_front_door_inside = {
			    {
			        "front door",
			        "state_closed",
			        8,
			        16,
			        1,
			        1,
			        4,
			        79,
			        "pos_right",
			        "face_left",
                    {"class_openable", "class_door"}
                }
            };

			struct room obj_hall_door_library = {
				{
					"library",
					"state_open",
					136,
					16,
					0,
					1,
					3,
					"",
					"face_back",
					{"class_door"}
				}
			};

			struct room obj_hall_door_kitchen = {
				{
				    "kitchen",
					"state_open",
					176,
					16,
					0
					1,
					4,
					"pos_left",
					"face_right
					{"class_door"}
				}
			};



int main()
{

	VDP_drawText(obj_front_door_inside.data.name, 10, 10);
	VDP_drawText(obj_front_door_inside.data.state, 10, 11);
	VDP_drawText(obj_front_door_inside.data.classes[0], 10, 12);
	VDP_drawText(obj_front_door_inside.data.classes[1], 10, 13);

	while(1)
	{
		//read input
		//move sprite
		//update score
		//draw current screen (logo, start screen, settings, game, gameover, credits...)
	}
	return (0);
}
