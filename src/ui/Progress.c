#include "Progress.h"
/**
 * @constructor
 *
 * @return Progress
 */
Progress newProgress() {
	Progress progress;
	progress.current_progress = 0;
	progress.painted = 0;
	return progress;
}

/**
 * Paint the progress bar
 *
 * @param Progress * progress
 *
 */
void Progress_paint(Progress *progress) {
	int chars,
		spaces,
		i;
	if( ! progress->painted ) {
		printf("\n");
		progress->painted = 1;
	}
	printf("\r");
	chars = progress->current_progress * PROGRESS_TOTAL_STEPS / 100;
	spaces = PROGRESS_TOTAL_STEPS - chars;

	printf("%c", PROGRESS_PREVIOUS);
	for( i = 0; i < chars; i++ ) {
		printf("%c", PROGRESS_CHAR);
	}
	// printf("%*s", PROGRESS_TOTAL_STEPS - chars, " ");
	for( i = 0; i < spaces; i++ ) {
		printf("%c", ' ');
	}
	printf("%c", PROGRESS_NEXT);
	printf(" %6.2f%%", progress->current_progress);
	fflush(stdout); // No newline so we have to
}

/**
 * Update the progress value
 *
 * @param Progress * progress
 * @param float newvalue
 *
 */
void Progress_update(Progress *progress, float newvalue) {
	progress->current_progress = newvalue;
}
