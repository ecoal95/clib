#ifndef __PROGRESS_H
#define __PROGRESS_H

#include <stdio.h>

#define PROGRESS_TOTAL_STEPS 30 // numero de caracteres que se usarán para indicar el progreso
#define PROGRESS_PREVIOUS '['
#define PROGRESS_NEXT ']'
#define PROGRESS_CHAR '='

/** Progress structure definition */
typedef struct Progress {
	float current_progress; /**> Current progress/100 */
	unsigned int painted; /**> If first paint was done */
} Progress;

/**
 * @constructor
 *
 * @return Progress
 */
Progress newProgress();

/**
 * Paint the progress bar
 *
 * @param Progress * progress
 *
 */
void Progress_paint(Progress *progress);

/**
 * Update the progress value
 *
 * @param Progress * progress
 * @param float newvalue
 *
 */
void Progress_update(Progress *progress, float newvalue);
#endif
