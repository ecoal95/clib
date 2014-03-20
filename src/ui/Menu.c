#include "Menu.h"

/**
 * Menu item constructor
 *
 * @constructor
 *
 * @param const char * description the option description
 * @param void (* callback)(void) the callback to be executed
 *
 * @return MenuItem
 */
MenuItem newMenuItem( const char * description, void (*callback)(void) ) {
	MenuItem item;
	item.description = str_clone(description);
	item.callback = callback;
	return item;
}

/**
 * Menu constructor
 *
 * @constructor
 *
 * @return Menu
 */
Menu newMenu() {
	Menu menu;
	menu.item_count = 0;
	menu.selected_option = 0;
	return menu;
}

/**
 * Add a menu item
 *
 * @param Menu * self
 * @param const char * description
 * @param void (* callback)(void)
 *
 */
void Menu_add(Menu * self, const char *description, void (*callback)(void)) {
	MenuItem item = newMenuItem(description, callback);

	self->item_count++;

	self->items = realloc(self->items, sizeof(self->items) + sizeof(item));
	self->items[self->item_count - 1] = item; // Ojo! Item no es un puntero, así que hay que usar: item.description en vez de item->description
}

/**
 * Display the menu
 *
 * @param Menu * self
 */
void Menu_display(Menu * self) {
	int i = 0;
	for( ; i < self->item_count; i++ ) {
		printf("%d) %s\n", i, self->items[i].description);
	}
}

/**
 * Get user input
 *
 * @param Menu * self
 */
void Menu_scan(Menu * self) {
	printf("\nIntroduce la opción deseada:\n");

	scanf("%d", &(self->selected_option));
	if( (self->selected_option < 0) || (self->selected_option > (self->item_count - 1)) ) {
		message("Error: ", MESSAGE_ERROR);
		printf("La opción introducida no es correcta\n");
		Menu_scan(self);
	}
}

/**
 * Execute the current selected option
 *
 * @param Menu * self
 */
void Menu_exec(Menu * self) {
	self->items[self->selected_option].callback();
}

/**
 * Display, read and exec the menu option
 *
 * @param Menu * self
 */
void Menu_init(Menu *self) {
	Menu_display(self);
	Menu_scan(self);
	Menu_exec(self);
}
