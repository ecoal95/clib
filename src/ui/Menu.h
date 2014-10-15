#ifndef __MENU_H
#define __MENU_H

#include <stdio.h>
#include "message.h"
#include "../common/str.h"

/** Menu item structure */
typedef struct MenuItem {
	char * description; /**< Description of the option */
	void (*callback)(void); /**< Callback if the option goes checked */
} MenuItem;

/** Menu structure */
typedef struct Menu {
	unsigned item_count; /**< Number of items */
	unsigned selected_option; /**< Selected item */
	MenuItem * items; /**< Array of items */
} Menu;

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
MenuItem newMenuItem( const char * description, void (*callback)(void) );

/**
 * Menu constructor
 *
 * @constructor
 *
 * @return Menu
 */
Menu newMenu();

/**
 * Add a menu item
 *
 * @param Menu * self
 * @param const char * description
 * @param void (* callback)(void)
 *
 */
void Menu_add(Menu * self, const char *description, void (*callback)(void));

/**
 * Display the menu
 *
 * @param Menu * self
 */
void Menu_display(Menu * self);

/**
 * Get user input
 *
 * @param Menu * self
 */
void Menu_scan(Menu * self);

/**
 * Execute the current selected option
 *
 * @param Menu * self
 */
void Menu_exec(Menu * self);

/**
 * Display, read and exec the menu option
 *
 * @param Menu * self
 */
void Menu_init(Menu *self);

#endif
