#include <string.h>
/**
 * Define message codes
 */
#define MESSAGE_DEFAULT 1
#define MESSAGE_SUCCESS 2
#define MESSAGE_ERROR 3
#define MESSAGE_WARNING 4
#define MESSAGE_INFO 5

/**
 * Define text color codes
 * echo -e \e[STYLE;COLOR;BACKGROUNDCOLORmTEXT
 */
#define TEXT_COLOR_DEFAULT "39"
#define TEXT_COLOR_BLACK "30"
#define TEXT_COLOR_RED "31"
#define TEXT_COLOR_GREEN "32"
#define TEXT_COLOR_YELLOW "33"
#define TEXT_COLOR_BLUE "34"
#define TEXT_COLOR_MAGENTA "35"
#define TEXT_COLOR_CYAN "36"
#define TEXT_COLOR_WHITE "37"

#define TEXT_BACKGROUND_DEFAULT "49"
#define TEXT_BACKGROUND_BLACK "40"
#define TEXT_BACKGROUND_RED "41"
#define TEXT_BACKGROUND_GREEN "42"
#define TEXT_BACKGROUND_YELLOW "43"
#define TEXT_BACKGROUND_BLUE "44"
#define TEXT_BACKGROUND_MAGENTA "45"
#define TEXT_BACKGROUND_CYAN "46"
#define TEXT_BACKGROUND_WHITE "47"

#define TEXT_STYLE_DEFAULT "00"
#define TEXT_STYLE_BOLD "01"
#define TEXT_STYLE_BLINK "07"
// NOT CROSS SYSTEM
#define TEXT_STYLE_UNDERLINE "05"
#define TEXT_STYLE_HIDDEN "08"

// estaría bien si no fuéramos a usarla dinámicamente #define message_get_style(style ,color, background) "\e["style";"color";"background

char * message_get_style(char *dest, const char *style, const char *colorcode, const char *backgroundcode) {
	char ret[12] = "";
	strcat(ret, "\e[");
	strcat(ret, style);
	strcat(ret, ";");
	strcat(ret, colorcode);
	strcat(ret, ";");
	strcat(ret, backgroundcode);
	strcat(ret, "m");
	strcpy(dest, ret);
	return dest;
}

void message_custom(const char *msg, const char *style, const char *color, const char *background) {
	char default_style[12];// Max length is \e[00;00;00m + \0=> 12
	char custom_style[12];

	message_get_style(default_style, TEXT_STYLE_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_BACKGROUND_DEFAULT);
	message_get_style(custom_style, style, color, background);

	printf("%s%s%s", custom_style, msg, default_style);
}
/**
 * Prints a message with custom color
 * @param char[] msg the message
 * @param code one of the message codes defined above
 */
void message(const char *msg, const int code) {
	switch (code) {
		case MESSAGE_ERROR:
			return message_custom(msg, TEXT_STYLE_DEFAULT, TEXT_COLOR_RED, TEXT_BACKGROUND_DEFAULT);
		case MESSAGE_INFO:
			return message_custom(msg, TEXT_STYLE_DEFAULT, TEXT_COLOR_BLUE, TEXT_BACKGROUND_DEFAULT);
		case MESSAGE_WARNING:
			return message_custom(msg, TEXT_STYLE_DEFAULT, TEXT_COLOR_YELLOW, TEXT_BACKGROUND_DEFAULT);
		case MESSAGE_SUCCESS:
			return message_custom(msg, TEXT_STYLE_DEFAULT, TEXT_COLOR_GREEN, TEXT_BACKGROUND_DEFAULT);
	}
}
